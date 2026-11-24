#include <SoftwareSerial.h>

// Arduino Uno R3 or classic Nano (ATmega328P).
// HC-05 TXD goes to D10. D11 goes to HC-05 RXD through a 5 V to 3.3 V divider.
SoftwareSerial robotLink(10, 11);  // Arduino RX, then Arduino TX.
constexpr unsigned long bluetoothBaud = 38400;

struct DriveCommand {
  int throttle;
  int steering;
  uint8_t limit;
  uint8_t buttons;
  uint32_t runId;
};

// Hold the latest values for the Serial Monitor and the onboard LED.
int throttleValue = 1500, steeringValue = 1500;
uint8_t speedLimit = 0, buttonMask = 0;

constexpr uint32_t commandTimeoutMs = 250;
constexpr uint32_t replyIntervalMs = 250;
char buffer[40];
size_t length = 0;
bool overflow = false;
bool linkAlive = false;
uint32_t lastFrameMs, lastReplyMs, activeRun;
uint32_t lastFrameUs, maxGapUs;
unsigned int frameCount;
int leftPower, rightPower;
bool buttonA, buttonB, buttonC;

bool readField(char*& part, unsigned long& value, char delimiter) {
  if (*part < '0' || *part > '9') return false;
  char* end;
  value = strtoul(part, &end, 10);
  if (*end != delimiter || value > 2147483647UL) return false;
  part = delimiter == '\0' ? end : end + 1;
  return true;
}

bool readCommand(DriveCommand& cmd) {
  if (strncmp(buffer, "DRV,", 4) != 0) return false;
  char* part = buffer + 4;
  unsigned long throttle, steering, limit, buttons, runId;
  if (!readField(part, throttle, ',') || throttle < 1000 || throttle > 2000 ||
      !readField(part, steering, ',') || steering < 1000 || steering > 2000 ||
      !readField(part, limit, ',') || limit > 100 ||
      !readField(part, buttons, ',') || buttons > 7 ||
      !readField(part, runId, '\0')) return false;
  cmd = {static_cast<int>(throttle), static_cast<int>(steering),
         static_cast<uint8_t>(limit), static_cast<uint8_t>(buttons),
         static_cast<uint32_t>(runId)};
  return true;
}

void stopOutputs() {
  activeRun = 0;
  throttleValue = steeringValue = 1500;
  speedLimit = buttonMask = 0;
  digitalWrite(LED_BUILTIN, LOW);
  leftPower = rightPower = 0;
  buttonA = buttonB = buttonC = false;
  // For live hardware, set the motors and auxiliary outputs to their safe states here.
}

void applyDrive(const DriveCommand& cmd) {
  throttleValue = cmd.throttle;
  steeringValue = cmd.steering;
  speedLimit = cmd.limit;
  buttonMask = cmd.buttons;
  // The app's up direction is below 1500. Right is above 1500.
  const int forward = 1500 - cmd.throttle;
  const int turn = cmd.steering - 1500;
  leftPower = static_cast<long>(constrain(forward + turn, -500, 500)) * cmd.limit / 500;
  rightPower = static_cast<long>(constrain(forward - turn, -500, 500)) * cmd.limit / 500;
  buttonA = (cmd.buttons & 1) != 0;
  buttonB = (cmd.buttons & 2) != 0;
  buttonC = (cmd.buttons & 4) != 0;
  digitalWrite(LED_BUILTIN, buttonA ? HIGH : LOW);  // A controls the onboard LED.
}

void receiveCommand(const DriveCommand& cmd, uint32_t now) {
  const bool firstFrame = !linkAlive;
  const uint32_t previousRun = activeRun;
  const uint32_t receivedUs = micros();
  if (linkAlive) maxGapUs = max(maxGapUs, receivedUs - lastFrameUs);
  lastFrameUs = receivedUs;
  ++frameCount;
  linkAlive = true;
  lastFrameMs = now;
  if (cmd.runId == 0) {
    stopOutputs();
  } else if (cmd.runId == activeRun) {
    applyDrive(cmd);
  } else {
    stopOutputs();
    // Arm a new run only on a centered command with all auxiliary outputs off.
    if (cmd.throttle == 1500 && cmd.steering == 1500 && cmd.buttons == 0) {
      activeRun = cmd.runId;
    }
  }

  if (firstFrame || previousRun != activeRun || now - lastReplyMs >= replyIntervalMs) {
    robotLink.print("TEL,LINK,OK*");
    if (activeRun != 0 || previousRun != 0) {
      robotLink.print("TEL,RUN,");
      robotLink.print(activeRun);
      robotLink.print('*');
    }
    lastReplyMs = now;
  }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  robotLink.begin(bluetoothBaud);
  stopOutputs();
  Serial.println("Sinyas Arduino bench ready. A controls the onboard LED.");
}

void loop() {
  if (linkAlive && millis() - lastFrameMs >= commandTimeoutMs) {
    linkAlive = false;
    stopOutputs();
    Serial.println("Command timeout. Outputs cleared.");
  }

  while (robotLink.available() > 0) {
    const char next = robotLink.read();
    if (next == '*') {
      buffer[length] = '\0';
      DriveCommand cmd;
      if (!overflow && readCommand(cmd)) receiveCommand(cmd, millis());
      length = 0;
      overflow = false;
    } else if (next == '\0' || length == sizeof buffer - 1) {
      overflow = true;
    } else if (!overflow) {
      buffer[length++] = next;
    }
  }

  static uint32_t lastReportMs;
  if (linkAlive && millis() - lastReportMs >= 1000) {
    lastReportMs = millis();
    Serial.print("RUN "); Serial.print(activeRun);
    Serial.print(" | sticks "); Serial.print(throttleValue);
    Serial.print('/'); Serial.print(steeringValue);
    Serial.print(" | limit "); Serial.print(speedLimit);
    Serial.print(" | mask "); Serial.print(buttonMask);
    Serial.print(" | calculated power L/R "); Serial.print(leftPower);
    Serial.print('/'); Serial.print(rightPower);
    Serial.print(" | A/B/C "); Serial.print(buttonA);
    Serial.print('/'); Serial.print(buttonB);
    Serial.print('/'); Serial.print(buttonC);
    Serial.print(" | frames "); Serial.print(frameCount);
    Serial.print(" | max gap (us) "); Serial.println(maxGapUs);
    frameCount = 0;
    maxGapUs = 0;
  }
}
