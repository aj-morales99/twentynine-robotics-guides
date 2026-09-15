---
layout: default
title: Mini Hunter line-sensor calibration
description: Adjust the Mini Hunter line sensors using CAL MODE and the OLED indicators.
---

# Line-sensor calibration

The goal is simple: the OLED should show `..` over the dark arena surface and `##` over the light boundary. Calibrate at the robot's normal ride height.

## Prepare safely

- Support the robot with moving parts clear.
- Use a small nonconductive adjustment tool.
- Prepare samples of the actual dark arena and light boundary surfaces.
- Clean the sensor faces gently before adjusting them.

## Adjust the first sensor

1. [Enter CAL MODE](./) and press **SW1 once** for **LINE SENSOR ADJUST**.
2. Put the first line sensor over the light boundary sample.
3. Turn its adjustment clockwise until the display reads `..`.
4. Turn it counterclockwise slowly until the display changes to `##`.
5. Turn it one additional full turn counterclockwise.
6. Move the sensor over the dark surface and confirm it returns to `..`.

Repeat the same procedure for the second line sensor.

> **Supporting image coming later — MH-CAL-LINE-01**
> Adjustment point and OLED indicators, with `..` labeled dark and `##` labeled light.

## Validate before driving

Test all four combinations three times at normal ride height:

| Left sensor | Right sensor | Expected display |
| --- | --- | --- |
| Dark | Dark | `....` |
| Light | Dark | `##..` |
| Dark | Light | `..##` |
| Light | Light | `####` |

The readings should change cleanly and should not flicker while the robot is held still. If they flicker, clean the sensors, restore normal height, reduce strong direct light, and adjust again.

[Back to calibration](./)
