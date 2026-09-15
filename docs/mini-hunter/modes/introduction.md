---
layout: default
title: Mini Hunter modes introduction
description: Plain-language introduction to Mini Hunter operating and autonomous modes.
---

# Modes introduction

A **control mode** decides where movement commands come from. An **autonomous mode number** selects one programmed behavior. These are related, but they are not the same thing.

## Control choices shown by the robot

| Display choice | Meaning | Use it when |
| --- | --- | --- |
| `AUTO` / numbered mode | Autonomous behavior | The robot should use its sensors and selected program without continuous driving input. |
| `BT MODE` | Bluetooth control | A compatible Android panel will send commands. |
| `RC MODE` | RC receiver control | A verified transmitter and receiver will send channel pulses. |
| `JS MODE` | Joystick mode | The installed firmware and matching joystick hardware support it. |

The selector may first show **RC/RMT**, then offer Bluetooth, RC, or joystick choices. Read the OLED before confirming; do not assume the last-used selection is still active.

## Systems versus modes

- A **3-system** robot uses front-left, front, and front-right enemy sensors.
- A **5-system** robot adds left and right enemy sensors.
- A **4-mode** program contains four selectable autonomous behaviors.
- A **7-mode** program contains seven selectable autonomous behaviors.
- **1 kg** and **3 kg** describe hardware/competition configurations; they do not automatically prove which sensor or mode count is loaded.

Check both the physical robot and the program configuration before uploading.

## Safe first run

1. Confirm the intended firmware and control mode.
2. Check battery security, attachments, and blade clearance.
3. Test sensor readings in calibration mode.
4. Perform the first movement test on a stand or in a controlled test area.
5. Keep a direct way to remove power.

[Customize modes in code](customization.html) · [Back to Mini Hunter guides](../)
