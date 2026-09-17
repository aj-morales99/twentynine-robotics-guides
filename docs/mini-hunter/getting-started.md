---
layout: default
title: Start using your Mini Hunter
description: A beginner guide to checking, selecting a control mode, and safely operating a pre-programmed Mini Hunter.
---

# Start using your Mini Hunter

<span class="status-chip ready">Start here — no programming required</span>

Your Mini Hunter normally arrives with working firmware already installed. You do **not** need to upload code before learning how to use the robot.

This guide takes you from opening the kit to a safe first drive or autonomous test. Programming is optional and is kept in a separate section for users who want to change the firmware.

## Learn the three board controls

The FullVision STM32 board uses three switches:

| Control | Type | What it does |
|---|---|---|
| **MODE** | Latching switch | Changes between the RC/RMT side and the AUTO side |
| **SW1** | Momentary switch | Moves to the next choice or changes a displayed value |
| **SW2** | Momentary switch | Selects, confirms, or starts the displayed choice |

Read the OLED before pressing another switch. It tells you which side of the menu is active and what SW1 and SW2 do on that screen.

## 1. Perform the first safety check

Before turning on the robot:

1. Put the robot on a stable table with the power switched off.
2. Check that the wheels are secure and can rotate without rubbing the chassis.
3. Check that sensor and motor cables are fully connected and clear of the wheels.
4. Make sure the blade or front attachment is secure.
5. Remove tools and loose objects from the test area.
6. For the first powered test, support the robot so both wheels are off the surface.

See [Wheels & gears check-up](hardware/wheels-gears-checkup.html) for the current maintenance procedure.

<div class="warning note"><strong>Keep the wheels raised for the first test.</strong> The selected mode may move the motors as soon as it starts.</div>

## 2. Choose how you want to control the robot

Use the MODE switch to choose one of two menu groups.

### RC/RMT side

Use this side when a person will control the robot.

1. Move MODE until the OLED shows **RC/RMT**.
2. Press SW1 to move through the available controller choices.
3. Stop when the OLED shows the controller you prepared:

   - **BT MODE** for the Android Bluetooth application
   - **RC MODE** for the supplied RC transmitter and receiver

4. Press SW2 to start the displayed control mode.

Set up the controller first if needed:

- [Bluetooth application setup](bluetooth-application-setup.html)
- [RC controller setup with RC Cable V1](rc-controller-setup.html)

### AUTO side

Use this side when the robot should run an autonomous sumobot behavior.

1. Move MODE until the OLED shows **AUTO**.
2. Press SW1 to cycle through the installed autonomous modes.
3. Press SW2 when the mode you want is displayed.
4. The OLED will ask for the starting delay.
5. Press SW1 to cycle through `0` to `5` seconds.
6. Press SW2 to confirm the delay and start the countdown.

Read [Modes introduction](modes/introduction.html) before choosing an autonomous behavior for a match.

## 3. Calibrate before an autonomous run

The robot relies on its sensors to find an opponent and avoid the arena boundary. Calibration is part of normal operation, especially after transport, repair, or a change of arena surface.

1. Return to the **RC/RMT** main screen.
2. Hold SW1 and SW2 together for about two seconds.
3. Release both switches when **CAL Mode** appears.
4. Use SW1 to choose the line-sensor or enemy-sensor check.

Complete both guides:

- [Line-sensor calibration](calibration/line-sensors.html)
- [Enemy-detection sensor check](calibration/enemy-detection.html)

<div class="note"><strong>Why this matters:</strong> an uncalibrated line sensor may allow the robot to leave the arena even when no opponent is nearby.</div>

## 4. Perform a supported-wheel test

1. Keep the robot on its stand.
2. Select the control mode you plan to use.
3. Confirm the wheels are stopped before giving a command.
4. Test forward, reverse, left, and right using small commands.
5. If using AUTO, select the intended mode and watch one short cycle while the wheels remain raised.
6. Exit the running mode before removing the stand.

To exit an active mode, press SW1 and SW2 together. Confirm that the motors stop and the menu returns before touching the robot.

## 5. Prepare for the arena

- Confirm the battery is charged and secured.
- Confirm the correct attachment and weight configuration are installed.
- Confirm both line sensors change correctly between the arena and boundary.
- Confirm the enemy sensors react at the distances you expect.
- Confirm the chosen mode appears on the OLED.
- Keep the robot switched off until it is placed in the permitted starting position.

## When programming is actually needed

Programming is only needed when you want to reinstall firmware, change detection distances or timing, customize modes, or study the FullVision code.

Continue with:

- [Arduino IDE, board setup, and uploading](setup-and-first-upload.html)
- [Common firmware settings](programming/common-settings.html)
- [FullVision function library](code-library/)
- [FullVision STM32 pin map](programming/pin-map.html)

If the robot does not behave as described, stop it and use the [Troubleshooting guide](troubleshooting/) before changing code.
