---
layout: default
title: Sinyas for Mini Hunter
description: A beginner's walkthrough for driving a Mini Hunter and using the Sinyas calibration tools.
---

# Use Sinyas with Mini Hunter

Start with the driving lesson. Once you can connect, drive, and stop, try the calibration lessons one at a time.

{% include mini-hunter-firmware-note.html %}

## 1 Get your equipment ready

- **Phone:** Android with [Sinyas installed](./#1-install-sinyas).
- **Robot:** Mini Hunter with an HC-05 and the matching **MiniHunterV2.8_Advance** program on its FullVision board. The program inside the board is called *firmware*. Ask your teacher or Twentynine Robotics which firmware your kit has.
- **Test stand:** A stable support that keeps both wheels and attachments clear. Have a teacher help with the first powered test.

| What you see | What it means |
| --- | --- |
| OLED | The little screen on the robot. |
| MODE | The switch that chooses between Remote and Auto. |
| SW1 | The board button that moves to the next menu choice. |
| SW2 | The board button that opens a choice. During a tool, hold it for two seconds to exit. |

<div class="warning note"><strong>Set the robot on its stand before connecting.</strong> Keep fingers, cables, and loose clothing clear. In a tuning test, even 0% forward speed can allow the wheels to turn in place.</div>

The blue OLED illustrations below are simulations of the **MiniHunterV2.8_Advance** screens. They use the firmware’s [bitmap font](../assets/images/sinyas/oled/FONT-LICENSE.txt).

## 2 Put the robot in Bluetooth Drive

1. Switch the robot on while it is on the stand.
2. Move the **MODE** switch until the OLED shows **REMOTE**.

    <figure class="guide-figure guide-figure--compact step-figure">
      <a href="../assets/images/sinyas/oled/remote.png"><img src="../assets/images/sinyas/oled/remote.png" width="576" height="172" alt="REMOTE. SW1 for BT/RC/IR. SW2 for START/STOP." loading="lazy"></a>
      <figcaption>The Remote menu shows what SW1 and SW2 do.</figcaption>
    </figure>

3. Tap and release **SW1** until you see **BT MODE**.

    <figure class="guide-figure guide-figure--compact step-figure">
      <a href="../assets/images/sinyas/oled/bt-menu.png"><img src="../assets/images/sinyas/oled/bt-menu.png" width="576" height="172" alt="BT MODE. SW2 for START/STOP." loading="lazy"></a>
      <figcaption>BT MODE is selected.</figcaption>
    </figure>

4. Tap and release **SW2**. The OLED should say **Waiting for Sinyas**.

    <figure class="guide-figure guide-figure--compact step-figure">
      <a href="../assets/images/sinyas/oled/bt-wait.png"><img src="../assets/images/sinyas/oled/bt-wait.png" width="576" height="172" alt="BT Mode. Waiting for Sinyas." loading="lazy"></a>
      <figcaption>The board is ready for the phone.</figcaption>
    </figure>


**Check:** When the robot says **Waiting for Sinyas**, it is ready for the phone. If you see **AUTO** or a numbered mode, return the MODE switch to **REMOTE**.

## 3 Pair the phone, then connect in Sinyas

{% include mini-hunter-bluetooth-name.html %}

1. In Sinyas, tap **☰ → Bluetooth → Open Android settings**.
2. Turn Bluetooth on. Pick your robot’s Bluetooth name from the list and enter its configured PIN if asked. This pairing step is normally needed once.
3. Return to Sinyas. If the module does not appear under **Paired devices**, tap the refresh icon.
4. Tap **Connect** beside your robot’s name.

    <figure class="guide-figure guide-figure--compact step-figure">
      <a href="../assets/images/sinyas/v111-bluetooth.png"><img src="../assets/images/sinyas/v111-bluetooth.png" width="1170" height="520" alt="Sinyas Bluetooth showing a connected MiniHunterV2.8_0082 and Robot replies Receiving" loading="lazy"></a>
      <figcaption><strong>In Sinyas.</strong> Find the name with your own serial number. This example shows robot 0082 after it has connected.</figcaption>
    </figure>

5. Check the upper-right corner. **Connected** means the phone has reached the Bluetooth module. **Mini Hunter**, shown below it, means the robot’s program has also identified itself.

    <figure class="guide-figure guide-figure--compact step-figure">
      <a href="../assets/images/sinyas/oled/bt-connected.png"><img src="../assets/images/sinyas/oled/bt-connected.png" width="576" height="172" alt="BT Mode. Sinyas connected." loading="lazy"></a>
      <figcaption>The board has received data from Sinyas.</figcaption>
    </figure>


**Check:** Wait for **MiniHunter** before looking for the tuning tools. If the screen stays on **Generic**, check the OLED, confirm the firmware, then disconnect and reconnect. The HC-05 name alone does not tell Sinyas which robot is connected.

## 4 Learn the controls on the stand

1. Tap **☰ → Drive**. Wait for **Start** to turn on.

    <figure class="guide-figure guide-figure--compact step-figure">
      <a href="../assets/images/sinyas/v111-drive.png"><img src="../assets/images/sinyas/v111-drive.png" width="1170" height="520" alt="Sinyas Drive with two centered sticks and Start ready" loading="lazy"></a>
      <figcaption><strong>In Sinyas.</strong> Link confirmed means the robot is ready for Start.</figcaption>
    </figure>

2. Choose speed button **1**. If its limit is higher than your teacher wants, change it under **Setup → Speed presets** while Drive is stopped.
3. Tap **Start**. Wait until the app says the robot accepted the run.
4. Move the **throttle** stick a little forward, then release it. Check that the wheels turn in the correct direction and stop when the stick centers.
5. Move the **steering** stick slightly left, then right. Release it after each check. Try both sticks together once you know what each one does.
6. Press and hold **Stop** for **2 seconds**, until the bar fills. The app sends the stop when the hold starts. Finish the hold so the app unlocks its menu and the robot can return to its board menu.

**Check:** The wheels stop, **Start** returns on the app, and the Mini Hunter returns to its menu after confirming the exit. Open **BT MODE** again with SW2 before the next Drive session. Buttons **A**, **B**, and **C** only operate an accessory if your robot's program assigns something to them.

## 5 Open a calibration tool

<div class="note"><strong>Pick one job to start.</strong> <a href="#6-check-the-line-sensors-before-changing-movement">Check the white boundary</a>, <a href="#7-practice-turning-toward-a-target">tune steering</a>, or <a href="#wheel-alignment">make the robot drive straight</a>. For the version chooser, see the <a href="../mini-hunter/calibration/">Mini Hunter Calibration overview</a>.</div>

*Calibration* means checking a sensor or adjusting how the robot reacts. Stop Drive and disconnect in Sinyas if it is already connected. **Open the calibration tool on the robot before connecting in Sinyas.**

1. Press and hold **SW1 and SW2 together**. Watch the calibration progress bar fill.

    <figure class="guide-figure guide-figure--compact step-figure">
      <a href="../assets/images/sinyas/oled/cal-start.png"><img src="../assets/images/sinyas/oled/cal-start.png" width="576" height="172" alt="Calibration. A partly filled progress bar." loading="lazy"></a>
      <figcaption>The bar fills while Calibration opens.</figcaption>
    </figure>

2. Release both buttons when the **CAL Mode** bar fills. The first entry is **Sensor Check**.

    <figure class="guide-figure guide-figure--compact step-figure">
      <a href="../assets/images/mini-hunter/calibration/mh-cal-v28-sensor-menu.png"><img src="../assets/images/mini-hunter/calibration/mh-cal-v28-sensor-menu.png" width="576" height="172" alt="Simulated V2.8 OLED reading Sensor Check" loading="lazy"></a>
      <figcaption>Sensor Check is the first calibration entry on V2.8.</figcaption>
    </figure>

3. Tap **SW1** until the OLED shows the tool name in the table below.
4. Tap **SW2** to open the tool on the robot. Leave it open.
5. In Sinyas, open **Bluetooth** and tap **Connect** beside your paired robot. Wait for **Mini Hunter** under **Connected**.
6. Open the matching app screen and wait for its board-ready message or live readings.
7. When you are finished, stop the test in Sinyas, then hold **SW2 for 2 seconds** to return to the tool menu. Releasing early cancels the exit hold.

**If you see Generic:** Disconnect, open the desired calibration tool on the robot, then reconnect in Sinyas.


| What you want to try | OLED label | Phone menu |
| --- | --- | --- |
| Detect the white boundary | **Line Tune** | **Line Detection Tuning** |
| Make the robot drive straight | **Wheel Alignment** (after Motor Check) | **Wheel Alignment** |
| Turn toward another robot | **PID Tune** | **Enemy Detection Tuning** |
| Rehearse the first movements | **Modes Tune** | **Auto modes → Opening** |
| Check the flag by itself | **Modes Tune** | **Auto modes → Flag servo** |

## 6 Check the line sensors before changing movement

A line sensor measures the surface underneath it. The **Pot** value comes from the small adjustment screw on the board, called a potentiometer. It sets the number that separates the floor from the line.

1. From **CAL MODE**, tap **SW1** until you see **Line Tune**.

    <figure class="guide-figure guide-figure--compact step-figure">
      <a href="../assets/images/sinyas/oled/line-menu.png"><img src="../assets/images/sinyas/oled/line-menu.png" width="576" height="172" alt="Line Tune. SW2 to start." loading="lazy"></a>
      <figcaption>Line Tune is selected.</figcaption>
    </figure>

2. Tap **SW2** to open **Line Tune**.

    <figure class="guide-figure guide-figure--compact step-figure">
      <a href="../assets/images/sinyas/oled/line-running.png"><img src="../assets/images/sinyas/oled/line-running.png" width="576" height="172" alt="Line Tune. Open Sinyas Setup. Hold SW2 to exit." loading="lazy"></a>
      <figcaption>Open Sinyas Setup is the wording on the board. The phone screen is called Line Detection Tuning.</figcaption>
    </figure>

3. Open **Line Detection Tuning** on the phone. Leave the test stopped. Put a piece of the normal arena surface under the left sensor and observe **ADC**, **Pot**, and the status. Then show it the white line.

    <figure class="guide-figure guide-figure--compact step-figure">
      <a href="../assets/images/sinyas/calibration-line.png"><img src="../assets/images/sinyas/calibration-line.png" width="1170" height="520" alt="Sinyas Line Detection with Live readings and Line profile in the footer" loading="lazy"></a>
      <figcaption><strong>On your phone.</strong> Check Live readings before starting a test. The Line profile dropdown loads the 1 kg, 3 kg, or custom recovery settings. The readings shown are examples.</figcaption>
    </figure>

4. With your teacher, adjust the left pot so the floor reads **No line** and the white boundary reads **Line detected**. On this firmware, a sensor number lower than the pot number counts as a hit. Repeat on the right.
5. Test one side at a time, then both, to check the app reacts to the correct sensor.

**Optional OLED check.** Open **Sensor Check** in CAL to see which side detects the line. A pair of dots means no line. A pair of hash marks means a line.

<figure class="guide-figure guide-figure--compact step-figure">
  <a href="../assets/images/mini-hunter/calibration/mh-cal-v28-check-line.png"><img src="../assets/images/mini-hunter/calibration/mh-cal-v28-check-line.png" width="576" height="172" alt="V2.8 Line Check OLED with two hash marks on the left and two dots on the right" loading="lazy"></a>
  <figcaption><strong>On the robot.</strong> The left sensor sees the line and the right sensor sees the floor. Tap SW1 to see distance readings. The <a href="../mini-hunter/calibration/sinyas-v2-8.html#sensor-check">Sensor Check walkthrough</a> shows the three- and five-sensor displays.</figcaption>
</figure>

### Adjust the robot’s response to the line

1. Pick **1 kg** or **3 kg** from the **Line profile** dropdown at the bottom. The profile loads recovery settings across all four tabs. To store your own settings on the phone, pick one of the three **Custom** slots, edit the settings, then use the pencil beside the dropdown to name and save the slot.
2. Open **Left**, **Right**, or **Both**. Pick the tab for the sensor condition you want to tune.
3. Change one field at a time. **Reverse power** controls how hard it backs away. **Minimum reverse** controls the minimum backing time. **Turn power** and **Turn time** control the turn that follows. **1000 ms** is one second.
4. Leave **Shared** alone on your first run. Those settings affect all three recovery tabs, including how quickly reverse power rises and how long the robot waits for the line to clear.
5. Start on the stand with **Forward speed** at **0%** and trigger each sensor with a sample of the line. When supervised on the test surface, increase forward speed gradually. Use **Stop test** before picking up the robot or saving.
6. Choose **Save to robot** to write the displayed settings to the board. **Load from robot** reads the board's saved values.

**Check:** A left hit and a right hit should produce different escape turns. Each sensor should still report floor and line correctly. Keep **Enemy detection** off to check line recovery by itself.

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

1. On the board, open **CAL → PID Tune**. After it opens, the display reads **Enemy Tune** in Classic or **PID Tune** in PID.
2. Open **Enemy Detection Tuning** in Sinyas. Choose **Classic** for fixed turn power and an adjustable delay, or **PID** to try steering power that changes as the target moves. **PID is in beta.**

    <figure class="guide-figure step-figure">
      <a href="../assets/images/sinyas/calibration-enemy.png"><img src="../assets/images/sinyas/calibration-enemy.png" width="1170" height="520" alt="Sinyas Enemy Detection with the Classic and PID choices and sensor readings" loading="lazy"></a>
      <figcaption><strong>On your phone.</strong> Pick the tracking method at the top and check the sensor readings before moving the robot.</figcaption>
    </figure>

The [full enemy tuning lesson](enemy-tuning.html) explains how to read the sensors, adjust each method, compare the results, and save the supported settings.

## 8 Build and test your first opening

An *opening* is a short list of moves that plays in order. The *base mode* is what the robot can do after the last move.

1. From **CAL Mode**, tap **SW1** until you see **Modes Tune**. Earlier compatible firmware may show **Auto Test**.

2. Tap **SW2** to open the tool. On the phone, open **Auto modes → Opening**.

    <figure class="guide-figure guide-figure--compact step-figure">
      <a href="../assets/images/mini-hunter/oled/v28-modes-tune.png"><img src="../assets/images/mini-hunter/oled/v28-modes-tune.png" width="576" height="172" alt="V2.8 Modes Tune OLED showing Sinyas Auto modes and Hold to Exit" loading="lazy"></a>
      <figcaption><strong>On the robot.</strong> Keep Modes Tune open while you work in Auto modes on the phone.</figcaption>
    </figure>

3. Pick slot **8** if it is empty, or select any slot marked **Needs setup**. Slots 5–7 contain example presets. Use **Mode details** to enter a short name such as **First turn**.
4. Tap **Add step**. Choose **Spin left**, enter **20%** power and **200 ms**, then tap **Apply step**.
5. Add **Wait** for **500 ms**. Open the three-dot menu on a step and choose **Move up** or **Move down** to change its order. If you try **Drive curve** later, give the left and right wheels different power values.

    <figure class="guide-figure guide-figure--compact step-figure">
      <a href="../assets/images/sinyas/calibration-opening.png"><img src="../assets/images/sinyas/calibration-opening.png" width="1170" height="520" alt="Sinyas Opening editor showing the mode list, two numbered steps, Add step, and Test draft" loading="lazy"></a>
      <figcaption><strong>On your phone.</strong> This is an example opening. Select a slot, then use Add step or tap a step to change it.</figcaption>
    </figure>

6. Check **After last step**. Leave **Include base mode in test** switched **off**. Tap **Test draft** and watch the short spin and pause. The wheels should then stay stopped.
7. If you want to see a handoff later with your teacher, select a base mode, lower its no-target speed in **Base modes**, and turn the switch on. Tap **Stop test** to finish. A line hit or command loss can also end the test.
8. Use **Save preset** to keep a copy on the phone. On boards that support saving, find this under **Phone presets**. Follow the steps below to save a mode you want to run from the OLED.

**Check:** With the switch off, **Opening complete. Robot stopped.** should appear after the last step.

### Save an opening to the robot

Use the current Sinyas APK and matching **MiniHunterV2.8_Advance** firmware. Check [Sinyas releases](releases.html) for app versions. Ask Twentynine Robotics for the firmware if your kit still has an earlier build.

1. Leave the board in **CAL → Modes Tune**. In Sinyas, stay on **Auto modes → Opening** and select the slot you want to change.
2. Stop the draft test. Tap **Save to robot** and wait for **Mode 5 saved to robot**, or the number you selected.
3. Tap **Load from robot** to check what the board saved. The app fills the opening steps, base mode and power, and flag angles from that slot.
4. Hold **SW2** to leave the tool, then leave CAL. Select the saved number in the robot’s **AUTO** menu. The opening runs first, then the selected base mode takes over. Verify the sequence after restarting the board.

Slots **5–7** use their built-in modes until you save a replacement. Slots **8–10** show **Empty - use Sinyas** until you program them. Names and descriptions stay on the phone. The OLED uses the mode number. The **Include base mode in test** switch is for draft testing. A saved opening hands off to its chosen base in normal Auto. A line hit interrupts the opening and starts the normal recovery.

If the app only offers **Save preset**, check [Sinyas releases](releases.html) for the current app version and confirm that the board has compatible firmware.

### Look up the Opening and Base modes controls

| Control | What it does |
| --- | --- |
| **Mode details** | Edit the phone preset’s name and description. Names allow up to 24 characters and descriptions up to 120. |
| **Add step** | Pick Move forward, Move backward, Drive curve, Spin left, Spin right, Drop flag, or Wait. You can keep up to eight steps. Movement and wait times are in milliseconds. Drop flag is a single action with no time field. |
| **Step card** | Tap it to edit. Use its three-dot menu to move it up, move it down, or remove it. |
| **After last step** | Choose the base mode for the handoff. **Include base mode in test** decides whether the test actually uses it. |
| **Base modes** | See what each numbered base does when no target is found. Set its draft power from 0% to 100%. Base 1 creeps forward, Base 2 spins left, Base 3 spins right, and Base 4 searches forward. |
| **Reload** | Return to the phone’s saved preset values. On boards that support saving, choose Reload phone preset in Phone presets. |
| **Save preset** | Keep a copy on the phone. Use Save to robot to write the selected opening slot to a compatible board. |

## 9 Test the flag without driving

1. Keep the robot in **CAL → Modes Tune** and change to **Auto modes → Flag servo** in Sinyas. Tap **Load from robot** to check the saved angles.
2. Enter the **Closed angle** and **Open angle** in degrees. Start from the kit’s known angles. Change one angle in small steps so the flag does not hit its mount.

    <figure class="guide-figure guide-figure--compact step-figure">
      <a href="../assets/images/sinyas/calibration-flag.png"><img src="../assets/images/sinyas/calibration-flag.png" width="1170" height="520" alt="Sinyas Flag servo showing closed and open angles with separate Close and Open buttons" loading="lazy"></a>
      <figcaption><strong>On your phone.</strong> Change one angle at a time and test it with the button below it. The angles shown are examples.</figcaption>
    </figure>

3. Tap **Open** to test the open position, then **Close** to check that the flag returns freely. The drive wheels stay stopped.
4. Tap **Save to robot** to keep the angles on the board. Use **Phone presets** for a copy on the phone.

**Check:** The flag moves freely in both directions. **Flag position set.** means the board finished moving it.

## Wheel alignment

Use Wheel Alignment if the robot pulls to one side when you tell it to drive straight. The robot can remember a different correction for each test speed.

1. On the board, open **CAL → Wheel Alignment**, just after **Motor Check**. Earlier compatible V2.8 builds may use **Modes Tune**. On the phone, open **Wheel Alignment** and tap **Load from robot**.

    <figure class="guide-figure step-figure">
      <a href="../assets/images/sinyas/calibration-wheel.png"><img src="../assets/images/sinyas/calibration-wheel.png" width="1170" height="520" alt="Sinyas Wheel Alignment with 25, 50 and 80 percent speed tabs, trim input, and Start" loading="lazy"></a>
      <figcaption><strong>On your phone.</strong> Pick a speed at the top, then use Start and Stop to check the run. The trim changes by 0.5 points per tap.</figcaption>
    </figure>
2. Put the robot on a clear, flat test surface with room to stop. Pick **Low · 25%**, then tap **Start**. Watch which way the robot drifts and tap **Stop**.
3. If the robot drifts left, use **+** to slow the right wheel. If it drifts right, use **−** to slow the left wheel. Each tap changes the trim by 0.5 percentage points. You can also type a value such as `+1.5` or `-1.5`. Use `0.0` for equal power.
4. Repeat until it drives straight. Then test **Medium · 50%** and **High · 80%** if you have room to run at those speeds.
5. Tap **Stop**, then **Save to robot**. The saved trim applies to forward driving in RC and Auto. The robot also stops the test if it sees a line or loses commands from the phone.

## Keep the robot ready for the next student

<div class="do-dont">
  <div><h3>Do</h3><ul><li>Start on a stand and test Stop early.</li><li>Change one tuning value at a time.</li><li>Record or load the original values before saving a change.</li></ul></div>
  <div><h3>Avoid</h3><ul><li>Lifting the robot during a test.</li><li>Starting an opening with the base-mode switch on for the first rehearsal.</li><li>Assuming a phone preset changes the robot’s onboard modes.</li></ul></div>
</div>

## If a step does not work

| Symptom | What to check first |
| --- | --- |
| **Connected** but **Start** is gray | Make sure SW2 opened **BT MODE**, then check the Robot replies indicator on the Bluetooth screen. |
| Sinyas shows **Generic** or the tuning pages are missing | Disconnect in Sinyas. Open the desired calibration tool on the board with **SW2**, then reconnect and wait for **Mini Hunter** under **Connected**. |
| A calibration button is gray | Open the matching tool on the OLED and wait for the app to confirm it. |
| The test stops as soon as it starts | Check whether a line sensor is already seeing the boundary or the Bluetooth link dropped. |
| The buttons still look right after changing a preset, but the robot acts differently | Check where it was saved. Phone presets live on the phone. Compatible Auto slots, line settings, and tracker settings use **Save to robot** in their respective tools. |

If the OLED says **SIGNAL LOST**, check the phone’s Bluetooth link before starting again.

<figure class="guide-figure guide-figure--compact step-figure">
  <a href="../assets/images/sinyas/oled/bt-lost.png"><img src="../assets/images/sinyas/oled/bt-lost.png" width="576" height="172" alt="BT Mode. SIGNAL LOST." loading="lazy"></a>
  <figcaption>The board stopped receiving Drive commands.</figcaption>
</figure>

[Back to Sinyas setup](./)
