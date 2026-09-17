---
layout: default
title: Mini Hunter modes customization in code
description: Safely choose Mini Hunter system and mode counts and edit autonomous behaviors.
---

# Modes customization in code

<span class="status-chip in-progress">In progress — custom mode creation and simplified uploading are still under development</span>

<div class="note"><strong>Under development:</strong> Twentynine Robotics is developing a simpler workflow that will let users create their own modes and upload them to the robot more easily. Until that workflow is released and tested, the instructions below are intended for careful source-code editing.</div>

Always edit a working copy and keep the original release untouched. A filename is only a label; the values inside the FullVision library determine the active sensor and mode counts.

## Choose the configuration

In the supplied FullVision library source, find the configuration values:

```cpp
const uint8_t SYSTEM = 5;
const uint8_t NUM_MODES = 7;
```

Use the combination that matches the robot and sketch:

| Robot configuration | `SYSTEM` | `NUM_MODES` |
| --- | ---: | ---: |
| 3-system / 4-mode | `3` | `4` |
| 5-system / 7-mode | `5` | `7` |

The same choice applies whether the build is 1 kg or 3 kg, but the actual movement values and installed hardware can still differ. In the supplied files reviewed for this guide, both library copies currently contain `SYSTEM = 5` and `NUM_MODES = 7`, even where a folder name suggests 3-system/4-mode. Verify the values rather than trusting the folder name.

<div class="warning note"><strong>Important:</strong> if `NUM_MODES` is 7, the sketch must contain seven valid mode behaviors. If `SYSTEM` is 5, the robot must have the matching sensors and wiring.</div>

## Edit a mode safely

1. Duplicate the complete sketch folder and give the copy a clear version name.
2. Open the main `.ino` file from inside that copied folder.
3. Locate the selected mode's behavior; do not rename required Arduino entry points.
4. Change one behavior at a time.
5. Run **Verify** before connecting the robot.
6. Upload using the [board setup procedure](../setup-and-first-upload.html).
7. Test at reduced speed in a clear area and record the result.

## Bluetooth module programming through `test()`

Some supplied sketches keep Bluetooth-module configuration code in a function named `test()`. To run it temporarily, preserve a backup and swap only the function names:

```cpp
// Temporary service arrangement
void loop()  { /* Bluetooth programming code that was in test() */ }
void loopp() { /* normal robot loop code */ }
```

After the module is configured, restore the original names so the normal robot behavior is again inside `loop()`. Arduino automatically runs `loop()` repeatedly; `loopp()` and `test()` are ordinary functions unless your code calls them. Never leave module-programming commands active during normal use.

## Recommended future filenames

Use names that describe hardware and behavior directly, for example:

```text
MiniHunter_1kg_3System_4Mode
MiniHunter_1kg_5System_7Mode
MiniHunter_3kg_3System_4Mode
MiniHunter_3kg_5System_7Mode
```

Add a firmware version after the descriptive name rather than hiding the configuration in an unclear historical filename.
