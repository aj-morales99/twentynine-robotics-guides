---
layout: default
title: Mini Hunter RC controller setup
description: Connect, bind, and safely test the Mini Hunter RC controller using the kit-supplied RC Cable V1.
---

# RC controller setup

<span class="status-chip ready">Ready — text-only guide</span>

Use this guide to prepare the supplied RC controller, connect its receiver to the Mini Hunter, bind the controller and receiver, and check the controls safely.

<div class="note"><strong>RC Cable V1 record:</strong> This procedure intentionally uses <strong>RC Cable V1</strong>, which is normally supplied with the Mini Hunter kit. Keep this cable with the robot. A different-looking receiver cable may have a different pin arrangement and must not be connected by guesswork.</div>

## Setup record

| Item | Configuration used by this guide |
|---|---|
| Transmitter | HotRC HT-10A shown in the supplied demonstration |
| Receiver | HotRC F-10A shown in the supplied demonstration |
| Receiver cable | **RC Cable V1 — normally supplied with the Mini Hunter kit** |
| Throttle channel | CH3 — left stick up/down |
| Steering channel | CH1 — right stick left/right |
| Robot connection | Bluetooth/RC header on the FullVision STM32 board |

## What you need

- Mini Hunter 1KG or 3KG Sumobot Kit
- Compatible HotRC transmitter and receiver supplied with the kit
- **RC Cable V1**, normally included with the kit
- Four AA batteries for the transmitter
- A stable stand or block that can hold the robot with both wheels off the surface

## Before you begin

1. Turn off the robot.
2. Turn off the RC transmitter.
3. Remove the blade or other attachment if it could move during testing.
4. Place the robot on a stable stand so its wheels cannot touch the table or floor.
5. Keep hands, cables, tools, and loose objects away from the wheels.

<div class="warning note"><strong>Test with the wheels raised.</strong> A newly connected receiver can send an unexpected command if its channels are connected incorrectly. Do not perform the first test with the robot resting on its wheels.</div>

## 1. Prepare the RC transmitter

1. Open the battery compartment at the back of the transmitter.
2. Insert four AA batteries. Match the `+` and `−` markings in the battery compartment.
3. Close the battery cover securely.
4. Turn on the transmitter.
5. If the transmitter asks for a language, use the buttons beside the screen to select **English**.
6. Install the supplied thumb pins or stick extensions on the two control sticks, if they are not already installed.

### Check the stick channels

Use the transmitter's channel display to confirm these two controls:

| Control movement | Channel shown on the transmitter | Robot function after setup |
|---|---:|---|
| Left stick up and down | CH3 | Forward and reverse |
| Right stick left and right | CH1 | Turn left and right |

Move only one stick direction at a time. Confirm that CH3 responds to the left stick's up/down movement and CH1 responds to the right stick's left/right movement. Then return both sticks to their center positions.

## 2. Connect RC Cable V1 to the receiver

Leave the transmitter on with both sticks centered. The robot must remain powered off while the receiver cable is connected.

1. Find the receiver's **CH1** and **CH3** connections.
2. Connect the two receiver ends of RC Cable V1 to CH1 and CH3.
3. On each receiver connection, keep the wire colors aligned with the receiver markings:

   - Yellow wire → `S` for signal
   - Red wire → `+` for power
   - Black wire → `−` for ground

If the two channel leads are not labeled, either lead may be placed in CH1 or CH3 for the first test. The channel assignment can be corrected later by swapping the **two complete channel plugs**.

<div class="warning note"><strong>Do not reverse the wire colors.</strong> Swapping the complete CH1 and CH3 plugs is different from reversing the wires inside a plug. Yellow must remain on <strong>S</strong>, red on <strong>+</strong>, and black on <strong>−</strong>.</div>

## 3. Connect the receiver to the Mini Hunter

1. Confirm that the robot is still powered off.
2. Locate the Bluetooth module on the FullVision STM32 board.
3. Carefully unplug the Bluetooth module from its header. Pull it straight out without bending its pins.
4. Connect the robot-side plug of RC Cable V1 to the same board header.
5. Place the receiver where it cannot touch the wheels, blade, or loose metal parts.
6. Check every connection once more before applying power.

The Bluetooth module and RC receiver use the same controller connection in this setup. Do not try to install both at the same time.

## 4. Bind the receiver and transmitter

Binding makes the receiver listen to this transmitter.

1. Make sure both transmitter sticks are centered.
2. Turn on the robot. The receiver LED should blink if it is not yet bound.
3. Press the receiver's **Bind** button. Its LED should begin blinking faster.
4. On the transmitter, open **Settings**.
5. Open **Bind Set**, then start the binding command shown on the screen.
6. Wait for the receiver LED to stop blinking and remain steadily lit.

<div class="note"><strong>Binding checkpoint:</strong> A steady receiver LED indicates that binding is complete. If the LED continues blinking, turn the robot off and repeat this section. Do not continue to the movement test until the connection is stable.</div>

## 5. Select RC Mode

1. Keep the robot supported with its wheels raised.
2. Use the switches on the FullVision STM32 board to display **RC MODE** on the OLED.
3. Select RC Mode.
4. Leave both transmitter sticks centered and watch the wheels.

Both wheels should remain stopped while the sticks are centered. If either wheel moves, turn off the robot immediately and see [If the robot moves at neutral](#if-the-robot-moves-at-neutral).

## 6. Test and correct the controls

Use small stick movements during the first test.

1. Move the left stick slightly upward. The robot wheels should respond as a forward command.
2. Move the left stick slightly downward. The wheels should respond as a reverse command.
3. Return the left stick to center. The wheels should stop.
4. Move the right stick slightly left. The robot should turn left.
5. Move the right stick slightly right. The robot should turn right.
6. Return the right stick to center. The wheels should stop.

### If forward/reverse and turning use the wrong sticks

1. Turn off the robot.
2. Turn off the transmitter.
3. At the receiver, swap the two **complete channel plugs** between CH1 and CH3.
4. Keep the yellow, red, and black wires in their correct `S`, `+`, and `−` orientation.
5. Power the system again, select RC Mode, and repeat the supported-wheel test.

If the correct stick controls the correct function but the direction itself is reversed, stop testing and confirm the transmitter's channel-reverse setting for the supplied controller. Do not change the receiver's signal, power, or ground order.

## If the robot moves at neutral

1. Turn off the robot immediately.
2. Return both sticks to their center positions.
3. Center the transmitter trims.
4. Confirm that the correct transmitter model memory is selected.
5. Check that the two RC Cable V1 receiver plugs are fully seated and correctly aligned.
6. Repeat the test with the wheels raised.

Do not place the robot on the arena until all four commands work correctly and both wheels stop whenever the sticks return to center.

## Final checklist

- [ ] RC Cable V1 is connected securely.
- [ ] Yellow is on `S`, red is on `+`, and black is on `−` at the receiver.
- [ ] The Bluetooth module has been removed from the shared board header.
- [ ] The receiver LED remains steadily lit.
- [ ] RC Mode is selected on the robot.
- [ ] Left stick up/down controls forward/reverse.
- [ ] Right stick left/right controls turning.
- [ ] The wheels stop when both sticks are centered.
- [ ] The first complete test was performed with the wheels raised.

The original Twentynine Robotics demonstration used to prepare this text guide is available in the [RC controller setup reference video](https://drive.google.com/file/d/1IzRf03yDP47ePiNyPkbAr98qOXkC-erA/view?usp=drive_link).
