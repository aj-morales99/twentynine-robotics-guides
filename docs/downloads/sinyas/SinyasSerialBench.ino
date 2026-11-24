#include <SoftwareSerial.h>

// FullVision-STM32 V1.5. HC-05 TX goes to PB15 and HC-05 RX goes to PA8.
SoftwareSerial robotLink(PB15, PA8);

struct DriveCommand {
  int throttle;
  int steering;
  uint8_t limit;
  uint8_t buttons;
  uint32_t runId;
};

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
  leftPower = rightPower = 0;
  buttonA = buttonB = buttonC = false;
  // For live hardware, set the motors and auxiliary outputs to their safe states here.
}

void applyDrive(const DriveCommand& cmd) {
  // The app's up direction is below 1500. Right is above 1500.
  const int forward = 1500 - cmd.throttle;
  const int turn = cmd.steering - 1500;
  leftPower = constrain(forward + turn, -500, 500) * cmd.limit / 500;
  rightPower = constrain(forward - turn, -500, 500) * cmd.limit / 500;
  buttonA = (cmd.buttons & 1) != 0;
  buttonB = (cmd.buttons & 2) != 0;
  buttonC = (cmd.buttons & 4) != 0;
  // This bench example only calculates outputs. Apply them here for live hardware.
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
  Serial1.begin(115200);
  robotLink.begin(38400);
  stopOutputs();
  Serial1.println("Sinyas bench ready. Motor outputs are unused.");
}

void loop() {
  if (linkAlive && millis() - lastFrameMs >= commandTimeoutMs) {
    linkAlive = false;
    stopOutputs();
    Serial1.println("Command timeout. Outputs cleared.");
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
    Serial1.print("RUN "); Serial1.print(activeRun);
    Serial1.print(" | motor % L/R "); Serial1.print(leftPower);
    Serial1.print('/'); Serial1.print(rightPower);
    Serial1.print(" | A/B/C "); Serial1.print(buttonA);
    Serial1.print('/'); Serial1.print(buttonB);
    Serial1.print('/'); Serial1.print(buttonC);
    Serial1.print(" | frames "); Serial1.print(frameCount);
    Serial1.print(" | max gap (us) "); Serial1.println(maxGapUs);
    frameCount = 0;
    maxGapUs = 0;
  }
}
