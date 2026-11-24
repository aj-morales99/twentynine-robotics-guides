---
layout: default
title: Sinyas for Mini Hunter
description: A beginner's walkthrough for driving a Mini Hunter and using the Sinyas calibration tools.
---

# Use Sinyas with Mini Hunter

Start with the driving lesson. Once you can connect, drive, and stop, try the calibration lessons one at a time.

## 1 Get your equipment ready

- **Phone:** Android with [Sinyas V1.0 installed](./#1-install-sinyas).
- **Robot:** Mini Hunter with an HC-05 and the matching **MiniHunterV2.8_Advance** program on its FullVision board. The program inside the board is called *firmware*. Ask your teacher or Twentynine Robotics which firmware your kit has.
- **Test stand:** A stable support that keeps both wheels and attachments clear. Have a teacher help with the first powered test.

| What you see | What it means |
| --- | --- |
| OLED | The little screen on the robot. |
| MODE | The switch that chooses between Remote and Auto. |
| SW1 | The board button that moves to the next menu choice. |
| SW2 | The board button that opens a choice. During a tool, hold it for two seconds to exit. |

<div class="warning note"><strong>Set the robot on its stand before connecting.</strong> Keep fingers, cables, and loose clothing clear. In a tuning test, even 0% forward speed can allow the wheels to turn in place.</div>

## 2 Put the robot in Bluetooth Drive

1. Switch the robot on while it is on the stand.
2. Move the **MODE** switch until the OLED shows **REMOTE**.
3. Tap and release **SW1** until you see **BT MODE**.
4. Tap and release **SW2**. The OLED should say **Waiting for Sinyas**.

**Check:** When the robot says **Waiting for Sinyas**, it is ready for the phone. If you see **AUTO** or a numbered mode, return the MODE switch to **REMOTE**.

## 3 Pair the phone, then connect in Sinyas

1. In Sinyas, tap **☰ → Bluetooth → Open Android settings**.
2. Turn Bluetooth on. Pick the HC-05 from the list of nearby devices and enter the PIN configured for your robot if asked. This pairing step is normally needed once.
3. Return to Sinyas. If the module does not appear under **Paired devices**, tap the refresh icon.
4. Tap **Connect** beside your HC-05.
5. Check the upper-right corner. **Connected** means the phone has reached the Bluetooth module. **MiniHunter**, under the Sinyas logo, means the robot’s program has also identified itself.

<figure class="guide-figure">
  <a href="../assets/images/sinyas/bluetooth.webp"><img src="../assets/images/sinyas/bluetooth.webp" width="800" height="400" alt="The Bluetooth page showing a connected HC-05 and Mini Hunter identification" loading="lazy"></a>
  <figcaption>Open Android settings to pair, select the HC-05 on the right, then confirm MiniHunter under the logo.</figcaption>
</figure>

**Check:** Wait for **MiniHunter** before looking for the tuning tools. If the screen stays on **Generic**, check the OLED, confirm the firmware, then disconnect and reconnect. The HC-05 name alone does not tell Sinyas which robot is connected.

## 4 Learn the controls on the stand

1. Tap **☰ → Drive**. Wait for **Start** to turn on.
2. Choose speed button **1**. If its limit is higher than your teacher wants, change it under **Setup → Speed presets** while Drive is stopped.
3. Tap **Start**. Wait until the app says the robot accepted the run.
4. Move the **throttle** stick a little forward, then release it. Check that the wheels turn in the correct direction and stop when the stick centers.
5. Move the **steering** stick slightly left, then right. Release it after each check. Try both sticks together once you know what each one does.
6. Press and hold **Stop** for **2 seconds**, until the bar fills. The app sends the stop when the hold starts. Finish the hold so the app unlocks its menu and the robot can return to its board menu.

<figure class="guide-figure">
  <a href="../assets/images/sinyas/drive.webp"><img src="../assets/images/sinyas/drive.webp" width="800" height="400" alt="Two joystick pads, speed presets and Stop in Sinyas" loading="lazy"></a>
  <figcaption>Use the sticks to move, the numbered buttons to set a limit, and Stop to end the run.</figcaption>
</figure>

**Check:** The wheels stop, **Start** returns on the app, and the Mini Hunter returns to its menu after confirming the exit. Open **BT MODE** again with SW2 before the next Drive session. Buttons **A**, **B**, and **C** only operate an accessory if your robot's program assigns something to them.

## 5 Open a calibration tool

*Calibration* means checking a sensor or adjusting how the robot reacts. Stop Drive first. At the board’s normal menu:

1. Press **SW1 and SW2 together**. Keep them pressed until the calibration screen appears, then release both.
2. From **CAL MODE**, tap **SW1** until the OLED shows the tool name in the table below.
3. Tap **SW2** to enter the tool. Leave the phone connected and open the matching Sinyas screen.
4. Wait for the app’s board-ready message or live readings. To leave the board tool, hold **SW2 for 2 seconds**. Releasing early cancels the exit hold.

| What you want to try | OLED label | Phone menu |
| --- | --- | --- |
| Detect the white boundary | **Line Tune** | **Line Detection Tuning** |
| Turn toward another robot | **Enemy Detection** or **PID Tune** | **Enemy Detection Tuning** |
| Rehearse the first movements | **Auto Test** | **Auto modes → Opening** |
| Check the flag by itself | **Auto Test** | **Auto modes → Flag servo** |

## 6 Check the line sensors before changing movement

A line sensor measures the surface underneath it. The **Pot** value comes from the small adjustment screw on the board, called a potentiometer. It sets the number that separates the floor from the line.

1. Enter **CAL → Line Tune** on the board and open **Line Detection Tuning** on the phone.
2. Leave the test stopped. Put a piece of the normal arena surface under the left sensor and observe **ADC**, **Pot**, and the status. Then show it the white line.
3. With your teacher, adjust the left pot so the floor reads **Clear** and the white line shows a hit. On this firmware, a sensor number lower than the pot number counts as a hit. Repeat on the right.
4. Test one side at a time, then both, to check the app reacts to the correct sensor.

<figure class="guide-figure">
  <a href="../assets/images/sinyas/line.webp"><img src="../assets/images/sinyas/line.webp" width="800" height="400" alt="Live readings and recovery fields in Sinyas Line Detection Tuning" loading="lazy"></a>
  <figcaption><strong>Calibrate in this order.</strong> Compare live readings, choose the hit condition, then adjust its power and timing.</figcaption>
</figure>

### Adjust the robot’s response to the line

1. Open **Left**, **Right**, or **Both**. Pick the tab for the sensor condition you want to tune.
2. Change one field at a time. **Reverse power** controls how hard it backs away. **Minimum reverse** controls the minimum backing time. **Turn power** and **Turn time** control the turn that follows. **1000 ms** is one second.
3. Leave **Shared** alone on your first run. Those settings affect all three tabs, including how quickly reverse power rises and how long the robot waits for the line to clear.
4. Start on the stand with **Forward speed** at **0%** and trigger each sensor with a sample of the line. When supervised on the test surface, increase forward speed gradually. Use **Stop test** before picking up the robot or saving.
5. Choose **Save to robot** to write the line-recovery settings to the board. **Load from robot** reads its saved values. **Phone presets** lets you keep a named copy on your phone.

**Check:** A left hit and a right hit should produce different escape turns. Each sensor should still report floor and line correctly. This tool uses the line sensors without target tracking.

### Look up the Shared settings

Change these after you have checked Left, Right, and Both. They apply to all three recovery cases.

| Field | What it changes |
| --- | --- |
| **Initial reverse (%)** | How much reverse power the robot uses when the ramp begins. |
| **Reverse ramp (ms)** | How long it takes to build up to the reverse power for that case. |
| **Neutral pause (ms)** | A short pause at zero motor output before reversing and again before turning. |
| **Line clear time (ms)** | How long both sensors must stay clear before the robot can finish backing up. |
| **Reverse limit (ms)** | The longest the robot may reverse before it stops the test. Make it at least as long as the clear time and each minimum reverse time. |
| **Settle time (ms)** | How long the robot waits after the recovery turn before continuing. |

If the app reports the recovery limit, stop and check the placement and sensor readings. A larger time value will not fix a sensor that still sees the line after the robot has moved away.

## 7 Practice turning toward a target

Open **CAL → Enemy Detection** or **PID Tune** on the board. Then open **Enemy Detection Tuning** in Sinyas. Choose **Classic** for fixed turn power and a turn delay you can set. Choose **PID** to try steering power that changes as the target moves. **PID is in beta.** Try both on your own robot and keep the one that behaves best for you.

The [full enemy tuning lesson](enemy-tuning.html) explains how to read the sensors, adjust each method, compare the results, and save the supported settings.

## 8 Build and test your first opening

An *opening* is a short list of moves that plays in order. The *base mode* is what the robot can do after the last move.

1. Open **CAL → Auto Test** on the board and **Auto modes → Opening** in Sinyas.
2. Pick slot **8** if it is empty, or select any slot marked **Needs setup**. Slots 5–7 contain example presets. Use **Mode details** to enter a short name such as **First turn**.
3. Tap **Add step**. Choose **Spin left**, enter **20%** power and **200 ms**, then tap **Apply step**.
4. Add **Wait** for **500 ms**. Open the three-dot menu on a step and choose **Move up** or **Move down** to change its order. If you try **Drive curve** later, give the left and right wheels different power values.
5. Check **After last step**. Leave **Include base mode in test** switched **off**. Tap **Test draft** and watch the short spin and pause. The wheels should then stay stopped.
6. If you want to see a handoff later with your teacher, select a base mode, lower its no-target speed in **Base modes**, and turn the switch on. Tap **Stop test** to finish. A line hit or command loss can also end the test.
7. Use **Save preset** to keep your draft on the phone. The robot uses it temporarily for testing. Its onboard competition modes remain separate.

<figure class="guide-figure">
  <a href="../assets/images/sinyas/opening.webp"><img src="../assets/images/sinyas/opening.webp" width="800" height="400" alt="Opening editor showing steps, the base mode selector, the Include base mode in test switch, and Test draft" loading="lazy"></a>
  <figcaption><strong>Opening test sequence.</strong> Arrange the steps, choose whether the test continues into the base mode, then tap Test draft.</figcaption>
</figure>

**Check:** With the switch off, **Opening complete. Robot stopped.** should appear after the last step.

### Look up the Opening and Base modes controls

| Control | What it does |
| --- | --- |
| **Mode details** | Edit the phone preset’s name and description. Names allow up to 24 characters and descriptions up to 120. |
| **Add step** | Pick Move forward, Move backward, Drive curve, Spin left, Spin right, Drop flag, or Wait. You can keep up to eight steps. Movement and wait times are in milliseconds. Drop flag is a single action with no time field. |
| **Step card** | Tap it to edit. Use its three-dot menu to move it up, move it down, or remove it. |
| **After last step** | Choose the base mode for the handoff. **Include base mode in test** decides whether the test actually uses it. |
| **Base modes** | See what each numbered base does when no target is found. Set its draft power from 0% to 100%. Base 1 creeps forward, Base 2 spins left, Base 3 spins right, and Base 4 searches forward. |
| **Reload** | Return to the phone’s saved preset values. Save anything you want to keep first. |
| **Save preset** | Keep changes to this tab on the phone. The board’s competition modes remain separate. |

## 9 Test the flag without driving

1. Keep the robot in **CAL → Auto Test** and change to **Auto modes → Flag servo** in Sinyas.
2. Enter the **Closed angle** and **Open angle** in degrees. Start from the kit’s known angles. Change one angle in small steps so the flag does not hit its mount.
3. Tap **Test servo**. The flag opens and returns to the closed angle. The drive wheels stay stopped.
4. Use **Save preset** to remember the angles on this phone.

<figure class="guide-figure">
  <a href="../assets/images/sinyas/servo.webp"><img src="../assets/images/sinyas/servo.webp" width="800" height="400" alt="Flag servo tab with closed angle, open angle, and a Test servo button" loading="lazy"></a>
  <figcaption><strong>Test the flag on its own.</strong> Set the angles, then tap Test servo and check that the mechanism clears its mount.</figcaption>
</figure>

**Check:** The flag moves freely in both directions. **Servo test complete.** means the board finished the test.

## Keep the robot ready for the next student

<div class="do-dont">
  <div><h3>Do</h3><ul><li>Start on a stand and test Stop early.</li><li>Change one tuning value at a time.</li><li>Record or load the original values before saving a change.</li></ul></div>
  <div><h3>Avoid</h3><ul><li>Lifting the robot during a test.</li><li>Starting an opening with the base-mode switch on for the first rehearsal.</li><li>Assuming a phone preset changes the robot’s onboard modes.</li></ul></div>
</div>

## If a step does not work

| Symptom | What to check first |
| --- | --- |
| **Connected** but **Start** is gray | Make sure SW2 opened **BT MODE**, then check the Robot replies indicator on the Bluetooth screen. |
| You cannot find Auto modes or the tuning pages | Wait for **MiniHunter** under the Sinyas logo and check that your board reports the matching features. |
| A calibration button is gray | Open the matching tool on the OLED and wait for the app to confirm it. |
| The test stops as soon as it starts | Check whether a line sensor is already seeing the boundary or the Bluetooth link dropped. |
| The buttons still look right after changing a preset, but the robot acts differently | Check where it was saved. Auto presets live on the phone. Supported line and Classic/track selection settings use **Save to robot**. |

[Back to Sinyas setup](./)
