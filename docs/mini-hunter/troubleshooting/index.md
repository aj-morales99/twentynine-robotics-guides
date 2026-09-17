---
layout: default
title: Mini Hunter troubleshooting
description: Symptom-first help for Mini Hunter setup, controls, sensors, and unexpected behavior.
permalink: /mini-hunter/troubleshooting/
---

# Something happened—what do I do?

<span class="status-chip in-progress">In progress — initial checks are available while more verified symptoms and fixes are being added</span>

Start with the symptom you can observe. Change only one thing at a time and write down what happened.

<div class="warning note"><strong>If the robot moves unexpectedly:</strong> keep clear of the blade and wheels, use the normal power control if safely reachable, then disconnect power before touching hardware.</div>

## The computer does not show a COM port

1. Try a known USB **data** cable.
2. Connect directly to the computer instead of an unpowered hub.
3. Open Windows Device Manager and watch for a new port while reconnecting.
4. Install the approved CH340 driver only if your controller requires it.
5. Try another USB port and restart Arduino IDE.

## The sketch verifies but will not upload

1. Confirm the FullVision board and correct COM port are selected.
2. Close Serial Monitor and other programs using that port.
3. Confirm STM32CubeProgrammer is installed.
4. Repeat the documented **BT0/RST** bootloader sequence exactly.
5. After a successful upload, reset the controller back into normal operation.

## The upload succeeds but the robot does not start normally

Confirm that the complete sketch folder was opened, including its companion tabs and matching library. Check `SYSTEM` and `NUM_MODES`, then restore a known-good firmware backup. A successful upload proves that programming completed; it does not prove the selected firmware matches the hardware.

## Bluetooth connects but controls do nothing

1. Confirm the robot shows **BT MODE**.
2. Confirm the imported `.kwl` panel matches the installed firmware.
3. Exit RC mode so its interrupts no longer use the shared PA8/PB15 pins.
4. Test **Stop**, then one command briefly.
5. Restart the app and robot if the control source changed.

## RC control is reversed or moves at neutral

Power off the robot. Center trims, confirm the correct transmitter model memory, and repeat the supported-wheel test. Do not reverse channels, endpoints, or wiring by trial and error on the floor. Use the model-specific RC setup once verified.

## A line sensor misses the boundary

Clean the sensor face, return the robot to normal ride height, and repeat [line-sensor calibration](../calibration/line-sensors.html) using the real arena colors. Check the display three times for each surface and watch for flicker.

## An enemy sensor stays near 10 or 80 cm

Use a flat matte target and test one sensor at a time. Power off before checking its connector or cable. Compare it with a working sensor under the same conditions and record the failing position.

## The program no longer compiles after editing

Read the **first** error, not only the final summary. Undo the last small change or compare the whole sketch with the untouched backup. Confirm that required tabs and libraries remain present. If you changed mode count, make sure the matching mode functions exist.

## Information to include when asking for help

```text
Robot weight class and controller revision:
3-system or 5-system:
4-mode or 7-mode:
Firmware folder and version:
What you expected:
What happened instead:
Exact first error message, if any:
What changed immediately before the problem:
Photo or short video with the robot powered safely:
```
