---
layout: default
title: Mini Hunter RC controller setup
description: Safe preparation and first test for a Mini Hunter RC receiver and controller.
---

# RC controller setup

<span class="status-chip pending">Hardware verification required</span>

This page explains the safe order for preparing RC control. The FullVision firmware reads two receiver channels through pins shared with the Bluetooth connection, so the robot must be in the correct control mode. Final receiver wiring, transmitter settings, and channel direction still need to be verified for the exact RC kit supplied with your robot.

## Before connecting anything

- Use only the receiver and cable supplied or approved for your Mini Hunter.
- Keep the robot powered off while connecting the receiver.
- Support the robot so its wheels and blade are clear.
- Remove loose objects from the test area.
- Put the transmitter sticks at neutral and any throttle trim at center.

<div class="warning note"><strong>Stop if the connector does not match.</strong> Do not force it, reverse it, or guess the signal, power, and ground order.</div>

> **Supporting image coming later — MH-RC-01**
> Approved transmitter, receiver, and keyed Mini Hunter receiver connection shown separately.

## First setup sequence

1. Confirm the transmitter is off and the robot is off.
2. Connect the approved receiver using its verified orientation.
3. Place both transmitter sticks at neutral.
4. Turn on the transmitter first.
5. Power on the supported robot.
6. Use the robot's mode controls to choose **RC MODE**.
7. Do not touch a stick yet. The wheels should remain stopped at neutral.
8. Move one stick a small amount and confirm only the expected action.
9. Release the stick and confirm the robot stops.
10. Repeat with the other channel.

The current firmware treats approximately **1500 microseconds** as neutral, accepts pulses from **800 to 2200 microseconds**, and maps the normal control range from **1000 to 2000 microseconds**. Values around **1475 to 1525 microseconds** are treated as a neutral deadband. These are firmware facts, not instructions to change transmitter endpoints without validation.

## If the robot moves at neutral

1. Power off the robot immediately.
2. Re-center transmitter trims and sticks.
3. Confirm the correct model memory is selected on the transmitter.
4. Check that channel mixing is disabled unless the supplied setup explicitly requires it.
5. Repeat the supported-wheel test.

Do not reverse channels or change endpoints simply by trial and error while the robot is on the floor. Record the transmitter model and receiver wiring so a final model-specific page can be added.

[Back to Mini Hunter guides](./) · [Troubleshooting](troubleshooting/)
