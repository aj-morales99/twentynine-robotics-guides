---
layout: default
title: Common Mini Hunter firmware settings
description: Safely adjust Mini Hunter build, speed, timing, scan-distance, and attack-distance variables.
---

# Common firmware settings

<span class="status-chip ready">Beginner configuration reference</span>

These are the settings Mini Hunter owners are most likely to change. They are near the top of the main `.ino` file, before `setup()`.

Always duplicate the complete sketch folder before editing it. Change one setting at a time, upload it, and test with the robot supported so the wheels are raised.

## Select the 1KG or 3KG build

The supplied combined sketch contains one active 1KG block and one commented 3KG block. **Only one block should be active.**

### For a 1KG Mini Hunter

Use the 1KG class label and leave the 1KG values uncommented:

```cpp
#define ClassBuild "1KG"

uint8_t revSpeed = 100, turnSpeed = 100, attackSpeed = 100;
uint16_t revDelay = 75, turn180Delay = 200, turn90Delay = 75;

// Keep the 3KG block commented out.
```

### For a 3KG Mini Hunter

Change the class label, comment out the 1KG variables, and uncomment the 3KG variables:

```cpp
#define ClassBuild "3KG"

// uint8_t revSpeed = 100, turnSpeed = 100, attackSpeed = 100;
// uint16_t revDelay = 75, turn180Delay = 200, turn90Delay = 75;

uint8_t revSpeed = 80, turnSpeed = 100, attackSpeed = 100;
uint16_t revDelay = 100, turn180Delay = 200, turn90Delay = 100;
```

<div class="warning note"><strong>Do not leave both blocks active.</strong> Two declarations with the same variable names will stop the sketch from compiling. Do not leave both blocks commented either, because the movement code needs these variables.</div>

The different reverse speed and delays account for the heavier 3KG build. Treat the supplied values as the starting point, then verify boundary recovery on the actual arena.

## Set scan and attack distance

The default sketch contains:

```cpp
float scanDist = 50, attackDist = 25;
```

Both values are in centimeters.

| Variable | Meaning | Current default |
|---|---|---:|
| `scanDist` | Farthest distance at which the behavior treats a sensor reading as an opponent | 50 cm |
| `attackDist` | Close range at which the front-sensor behavior changes from approach to attack | 25 cm |

With the current autonomous logic:

- Front reading above `scanDist`: continue the selected search behavior.
- Front reading at or below `scanDist` but above `attackDist`: approach at 60% motor command.
- Front reading at or below `attackDist`: use the mode's attack command.
- Front-left, front-right, left, and right checks also use `scanDist` when deciding whether to turn toward a target.

### If detection is too erratic

Lower `scanDist`. A large scan range makes distant reflections, arena objects, people, or uncertain readings more likely to influence the robot. The supported Sharp-sensor conversion is limited to roughly **10–80 cm**; a displayed 80 cm is the upper clamp, not proof of an exact target at 80 cm.

A conservative example is:

```cpp
float scanDist = 40, attackDist = 20;
```

This example is not a universal best setting. Arena surface, lighting, sensor angle, opponent shape, and sensor condition all affect the useful range.

## Find a practical distance in Calibration Mode

1. Place the robot in the actual arena with its motors stopped.
2. From the **RC/RMT** main screen, hold SW1 and SW2 together for about two seconds.
3. Release the buttons when **CAL Mode** appears.
4. Press SW1 until the enemy-sensor check is displayed.
5. Put a representative opponent or flat target at the farthest distance where you want the robot to react.
6. Read the relevant value several times. Move the target slightly left and right and confirm that the reading remains stable.
7. Choose a `scanDist` near that stable distance. If false detections continue, reduce it a little more.
8. Move the target to the closer point where the robot should switch to a committed attack.
9. Use that stable closer reading for `attackDist`.

Keep `attackDist` lower than `scanDist`:

```cpp
10 <= attackDist < scanDist <= 80
```

See the complete [enemy-detection sensor check](../calibration/enemy-detection.html) before changing these values.

## Understand the movement variables

| Variable | Unit | What it changes |
|---|---|---|
| `revSpeed` | Percent, 0–100 | Reverse motor command during boundary recovery |
| `turnSpeed` | Percent, 0–100 | Spin/turn command during recovery and target alignment |
| `attackSpeed` | Percent, 0–100 | Main attack command and some opening moves |
| `revDelay` | Milliseconds | How long reverse recovery stages run |
| `turn180Delay` | Milliseconds | Approximate two-wheel spin duration after both line sensors trigger |
| `turn90Delay` | Milliseconds | Approximate correction spin after one line sensor triggers |

The delay names describe their intended behavior, not a guaranteed physical angle. Battery voltage, robot weight, tire grip, motor condition, and arena surface change how far the robot moves during the same delay.

## Safe tuning order

1. Select the correct 1KG or 3KG block.
2. Calibrate both line sensors.
3. Use Calibration Mode to choose `scanDist` and `attackDist`.
4. Test slow search and target alignment with the wheels raised.
5. Test boundary recovery at reduced risk on the arena.
6. Change only one speed or delay at a time.
7. Record the old value, new value, arena, and result.

Do not increase attack speed to compensate for poor sensor calibration. Fix sensor alignment and detection distance first.
