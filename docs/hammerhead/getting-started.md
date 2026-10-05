---
layout: default
title: Start using the Hammerhead RC Variant
description: Identify the Hammerhead variant, power on the RC Variant, assign its LED color, and perform a safe first control test.
permalink: /hammerhead/getting-started.html
---

# Start using Hammerhead

<span class="status-chip ready">Ready — RC Variant</span>

This page currently covers the **RC Variant**. Instructions for starting and controlling the Bluetooth Variant will be added later.

## Identify your variant

| Variant | How to identify it | Guide status |
|---|---|---|
| **RC Variant** | Uses a handheld RC transmitter and a receiver installed inside the robot | Ready below |
| **Bluetooth Variant** | Uses a Bluetooth controller interface instead of the RC transmitter | Coming soon |

If your Basic Hammerhead does not yet have a receiver, or you need to replace its receiver, complete [RC Variant installation](rc-receiver-installation.html) first.

## Before powering the RC Variant

1. Place the robot on a stable stand so both wheels are clear of the table.
2. Keep hands, tools, cables, and loose objects away from the wheels.
3. Confirm that the RC receiver and transmitter are paired.
4. Center the transmitter's steering and forward/reverse controls.
5. Connect the robot battery.

<div class="note"><strong>Safe power-on behavior:</strong> Connecting the battery powers the controller board and RC receiver, but the robot does not begin driving immediately. The motors remain stopped until you press <strong>SW2</strong> to start.</div>

## Understand the LED states

The three LEDs show whether the Hammerhead is waiting or running:

| LED display | Robot state |
|---|---|
| **One LED illuminated** | Standby. The illuminated LED shows the currently selected robot color. |
| **All three LEDs illuminated** | Running. The robot can respond to the RC transmitter. |
| **LEDs blinking after SW2 is held** | The robot is stopping and returning to standby. |

<figure class="guide-figure step-figure">
  <img src="../assets/images/hammerhead/getting-started/hh-start-05-confirm-start.webp" alt="Hammerhead controller board in standby with one green status LED illuminated" width="1600" height="900" loading="lazy">
  <figcaption><strong>Standby:</strong> only one LED is illuminated, showing the selected color.</figcaption>
</figure>

## Start and stop the robot

<ol class="guide-steps">
  <li>
    <p>Check that only <strong>one LED</strong> is illuminated. This means the robot is in standby.</p>
  </li>
  <li>
    <p>Press <strong>SW2 once</strong> to start the robot. All three LEDs illuminate using the selected color.</p>
    <figure class="guide-figure step-figure">
      <img src="../assets/images/hammerhead/getting-started/hh-start-04-cycle-green.webp" alt="Hammerhead controller board in the running state with all three status LEDs illuminated green while SW2 is pressed" width="1600" height="900" loading="lazy">
      <figcaption><strong>Running:</strong> all three LEDs illuminate in the selected color.</figcaption>
    </figure>
  </li>
  <li>
    <p>To stop, press and hold <strong>SW2</strong> until the LEDs begin blinking. Release the switch and wait for the display to return to <strong>one illuminated LED</strong>.</p>
  </li>
</ol>

<div class="note"><strong>Remember:</strong> one LED means standby; three LEDs mean running.</div>

## Robot color assigning

Use the status LEDs to assign a visible robot color before the match. Six colors are currently available.

<ol class="guide-steps">
  <li>
    <p>Make sure the robot is in standby with only <strong>one LED</strong> illuminated. If all three LEDs are illuminated, press and hold <strong>SW2</strong> until they blink and return to one LED.</p>
  </li>
  <li>
    <p>Press and keep holding the <strong>SW1 detent switch</strong> to enter color selection. Only one LED remains illuminated while you choose.</p>
    <figure class="guide-figure step-figure">
      <img src="../assets/images/hammerhead/getting-started/hh-start-01-red-ready.webp" alt="User holding SW1 while one red Hammerhead status LED is illuminated during color selection" width="1600" height="900" loading="lazy">
      <figcaption><strong>Color selection:</strong> hold SW1. A single LED shows the currently selected color.</figcaption>
    </figure>
  </li>
  <li>
    <p>While continuing to hold <strong>SW1</strong>, press <strong>SW2</strong> to move through the six available colors. Only one LED should be illuminated as the color changes.</p>
    <figure class="guide-figure step-figure">
      <img src="../assets/images/hammerhead/getting-started/hh-start-02-color-select.webp" alt="User holding SW1 while one blue Hammerhead status LED is illuminated during color selection" width="1600" height="900" loading="lazy">
      <figcaption>Each press of SW2 selects the next color; this example shows blue on one LED.</figcaption>
    </figure>
  </li>
  <li>
    <p>When the required color appears, release <strong>SW1</strong>. The robot remains in standby with one LED illuminated.</p>
  </li>
  <li>
    <p>Press <strong>SW2 once</strong> to start. All three LEDs illuminate using the color you selected.</p>
    <figure class="guide-figure step-figure">
      <img src="../assets/images/hammerhead/getting-started/hh-start-03-cycle-blue.webp" alt="Hammerhead controller board running with all three status LEDs illuminated blue" width="1600" height="900" loading="lazy">
      <figcaption><strong>Selected color active:</strong> three blue LEDs show that the robot is running.</figcaption>
    </figure>
  </li>
  <li>
    <p>To exit the running state, press and hold <strong>SW2</strong> again until the LEDs blink. The robot returns to standby with one LED illuminated.</p>
  </li>
</ol>

## Perform the first RC control test

Keep the robot supported with both wheels raised.

1. Move the forward/reverse control only a small amount.
2. Confirm that both wheels produce the expected forward and reverse response.
3. Check left and right steering.
4. Release the controls and confirm that both motors stop at neutral.
5. Press and hold SW2 to stop the robot after the test.

Do not place the robot on the floor until the controller returns reliably to neutral and every direction responds correctly.

## Before normal use

- [ ] Battery connection is secure.
- [ ] Receiver LED indicates a stable connection.
- [ ] Transmitter controls are centered.
- [ ] The intended color is shown on one LED in standby and all three LEDs while running.
- [ ] Both motors stop at neutral.
- [ ] The first movement test was completed with the wheels raised.
- [ ] Wheels and gears passed the [pre-use check](hardware/wheels-gears-checkup.html).

[Return to Hammerhead guides](./)
