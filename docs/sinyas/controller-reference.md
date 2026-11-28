---
layout: default
title: Sinyas controller screen reference
description: Look up every Sinyas V1.0 menu, Drive control, connection status, setting, backup option, and diagnostic tool.
---

# Find a control in Sinyas

Open the **☰** menu beside the Sinyas logo. Stop Drive or the current test before changing screens. Use the [first-time setup guide](./) if you have just installed the app.

## Choose a screen

| Phone menu | Use it to |
| --- | --- |
| **Drive** | Start or stop driving, use both sticks, change the speed limit, and send accessory buttons. |
| **Bluetooth** | Open Android Bluetooth settings, view paired devices, connect or disconnect, and check whether the robot answers. |
| **Setup** | Change handedness, stick size, stick response, speed presets, button labels, and theme. |
| **Auto modes** | Edit and rehearse openings, set draft base speeds, or test the flag servo on a compatible Mini Hunter. |
| **Enemy Detection Tuning** | Compare Classic and PID Beta target tracking on a compatible Mini Hunter. |
| **Line Detection Tuning** | See readings and tune what the Mini Hunter does when it touches the boundary. |
| **Wheel Alignment** | Check whether the Mini Hunter drives straight and adjust the wheel power balance. |
| **Guide** | Read the quick connection and message-format notes inside the app. |
| **Configuration** | Export or import phone settings and presets as a JSON file. |
| **About** | Check the app version, replay the boot screen, and open **Diagnostics**. |
| **Exit** | Close Sinyas and its Bluetooth connection after you confirm. |

Drive, Bluetooth, Setup, Guide, Configuration, and About are available for general use. Mini Hunter pages appear after the board identifies itself. Some controls also need a matching tool open on the board. Hammerhead and Generic projects use Drive. Follow the [Hammerhead guide](hammerhead.html) or [Arduino guide](generic.html) for the board side.

## Bluetooth and the robot name

<figure class="guide-figure step-figure">
  <a href="../assets/images/sinyas/v111-bluetooth.png"><img src="../assets/images/sinyas/v111-bluetooth.png" width="1170" height="520" alt="Sinyas Bluetooth showing the paired robot, Bluetooth link, and Robot replies indicators" loading="lazy"></a>
  <figcaption><strong>In Sinyas.</strong> Check Robot replies as well as the Bluetooth link. The top-right profile tells you which robot replied.</figcaption>
</figure>

| What you see | What it tells you |
| --- | --- |
| **Paired device** | Android remembers this HC-05. Choose **Connect** in Sinyas to open the link. |
| **Connected** | The phone reached the Bluetooth module. |
| **Robot replies · Receiving** | The board answered. If this says **No recent reply**, check the robot’s mode, serial wiring, and data speed. |
| **Identifying robot…** | Sinyas is waiting for the board to announce which robot it is. |
| **Mini Hunter**, **Hammerhead**, or **Generic** | The profile appears below Connected in the top-right corner. Generic can be correct for your own project, even when it sends the normal Drive replies. |

If the module is missing, use **Open Android settings** to turn Bluetooth on and pair it, then return to Sinyas and use the refresh icon. If Sinyas asks for **Nearby devices**, allow it so the app can open a Bluetooth connection. Sinyas can try the last connected device again on launch. Check the device before starting, especially if two HC-05 modules have the same name.

## Drive and the numbers on screen

1. With the robot ready, wait for **Start** to become available.

    <figure class="guide-figure step-figure">
      <a href="../assets/images/sinyas/v111-drive.png"><img src="../assets/images/sinyas/v111-drive.png" width="1170" height="520" alt="Sinyas Drive with Start ready and throttle and steering both reading 1500" loading="lazy"></a>
      <figcaption><strong>Ready to start.</strong> Both sticks are centered. Link confirmed means the board is replying.</figcaption>
    </figure>

2. Tap **Start** and wait for the robot to confirm. **Waiting for Start ACK** means the phone is waiting for that confirmation.
3. Move the throttle stick forward or backward and the steering stick left or right. You can use both thumbs at once. Each stick returns to center when released.
4. Pick **1**, **2**, or **3** to change the speed limit. The percentage below the button is the limit you set in Setup.
5. Tap **A**, **B**, or **C** to switch an accessory signal on. Tap it again to switch it off. The robot’s program decides what each signal does.
6. Hold **Stop** until the bar fills at **2000 ms**, which is two seconds. The app sends a stop when you first touch the button. Releasing early can request a fresh run, so finish the hold when you want to end driving.

| Display | What it means |
| --- | --- |
| **Throttle** and **Steering** | Each stick sends 1000–2000, with **1500** at center. Forward is below 1500. Right is above 1500. |
| **Outgoing** | The message sent by the phone while driving. **Drive off** means Drive is stopped. |
| **Robot reply** | The link or Start status, or the latest reading sent by the board, such as battery voltage. |
| **Robot link timed out** | The board stopped replying. Sinyas ends the run. Check the board and wait for a fresh reply before pressing Start. |

<div class="note"><strong>Stop on Mini Hunter.</strong> A completed hold also asks a compatible Mini Hunter in BT Mode to exit to its board menu. A Generic or Hammerhead project clears its outputs according to its program. Start again only after checking the board.</div>

Leaving Sinyas during Drive or a test stops that session. Return to the app and press Start again when the board is ready.

## Setup and personalize your controls

Open **Setup** while Drive is stopped. Changes save to the phone as you make them.

<figure class="guide-figure">
  <a href="../assets/images/sinyas/v111-setup.png"><img src="../assets/images/sinyas/v111-setup.png" width="1170" height="520" alt="Sinyas Setup showing throttle side, stick size, and stick sensitivity controls" loading="lazy"></a>
  <figcaption><strong>In Sinyas.</strong> Scroll down for speed presets, button labels, and theme.</figcaption>
</figure>

| Setting | How to use it |
| --- | --- |
| **Throttle side** | Put forward and reverse on the left or right. Steering uses the other side. |
| **Stick size** | Choose Medium, Large, or XL. Try a larger pad if you need more room for thumb movement. |
| **Throttle** and **Steering** curves | **Linear** spreads the response evenly. **Precision** gives finer movement near center. **Quick** gives more response with a small movement. |
| **Throttle sensitivity** and **Steering sensitivity** | Set each from **50% to 150%**. Start at 100%. Move one slider a little and compare the same thumb movement on Drive. |
| **Speed presets** | Edit buttons 1, 2, and 3 separately. The default limits are **40%, 70%, and 100%**. For a first test, lower the preset your class will use. |
| **Programmable buttons** | Give A, B, and C short names of up to eight characters. Renaming a button changes its label. Its signal keeps the same number. |
| **Theme** | Choose Dark or Light, then a red, blue, green, purple, or amber highlight. |

**Example.** For gentler turns, leave the throttle settings as they are and choose **Precision** under **Steering**. Return to Drive and compare small steering movements at a low speed limit.

## Mini Hunter tools and what gets saved

| Screen | What you can test | How to keep it |
| --- | --- | --- |
| **Auto modes → Opening** | Arrange steps, run without a base mode, or include the base after the opening. | **Save to robot** writes slots 5–10 on compatible firmware. **Phone presets** keeps a separate phone copy. |
| **Auto modes → Base modes** | Test search, attack, and steering settings for a base mode. | **Save to robot** writes the selected mode’s settings on compatible firmware. |
| **Auto modes → Flag servo** | Check open and closed angles without moving the wheels. | **Save to robot** stores the angles on compatible firmware. |
| **Line Detection Tuning** | Read each sensor, check its threshold, and choose a recovery profile. | **Save to robot** writes recovery settings. The pencil next to a Custom profile saves a named copy on the phone. Adjust the physical pots on the robot. |
| **Wheel Alignment** | Run a straight test and adjust the trim at 25%, 50%, or 80% power. | **Save to robot** applies the three trims to forward RC and Auto driving. See [Wheel alignment](mini-hunter.html#wheel-alignment). |
| **Enemy Detection Tuning** | Compare Classic and PID Beta while pivoting or approaching a target. | **Save to robot** writes supported tracker settings, including PID gains. Forward speed and the search switch are for the live test. |

Open the matching tool on the robot before connecting in Sinyas. The [illustrated Mini Hunter calibration walkthrough](../mini-hunter/calibration/sinyas-v2-8.html#tune-with-sinyas) shows the OLED and app screens beside the steps that use them.

## Back up your settings

1. Open **Configuration**. Tap **Export configuration**.

    <figure class="guide-figure step-figure">
      <a href="../assets/images/sinyas/v111-configuration.png"><img src="../assets/images/sinyas/v111-configuration.png" width="1170" height="520" alt="Sinyas Configuration with Import configuration and Export configuration controls" loading="lazy"></a>
      <figcaption><strong>In Sinyas.</strong> Export saves a copy of the phone’s settings before you import another file.</figcaption>
    </figure>

2. Choose a location in Android’s file picker. Keep the JSON file where you can find it later.
3. To restore or copy settings to another phone, open **Configuration → Import configuration** and select the file.
4. Read the confirmation. Import replaces the app settings and phone presets with those in the file. Export your current settings first if you may need them again.

A JSON file is a text file with settings in a form the app can read. The backup includes the phone’s controller layout, sensitivity, speed presets, button names, theme, and saved line and Auto presets. To copy line settings from a robot, tap **Load from robot**, then save the values in a **Custom** line-profile slot before exporting. Use **Save to robot** in the matching calibration screen to apply restored values to a board.

## Read the in-app Guide or check a problem

Open **Guide** to see how the stick numbers, accessory buttons, command messages, and robot replies fit together. If you are programming a new board, follow the [Arduino lesson](generic.html) to make an LED work before attaching any motors.

Under **About**, find the app version, replay the boot screen, or open **Diagnostics**. Diagnostics can help you report connection, timeout, and serial-write issues.

1. Reproduce the issue on the stand, then stop the robot.
2. Open **About → Diagnostics** and choose **Copy logs**.
3. When asking for help, include the app version, robot or board model, what screen you used, and which step failed. Send the logs only if you choose to share them.
4. Use **Clear logs** after you have saved any entries you still need.

Serial timing in Diagnostics measures when Android writes data. It does not measure when the robot receives a command or moves its motors.

[Back to Sinyas setup](./)
