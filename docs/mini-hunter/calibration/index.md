---
layout: default
title: Mini Hunter calibration setup
description: Choose the Mini Hunter V2.8 Sinyas calibration guide or the original V2.7 OLED guides.
permalink: /mini-hunter/calibration/
---

# Calibration setup

Calibration makes the sensor readings match the robot's real surroundings. Work on one sensor group at a time, support the robot securely, and keep the blade and wheels clear.

Choose the guide for the **firmware uploaded to your robot**. If you are unsure, check the sketch name used for the last upload.

## New guide · V2.8

Use this guide if your sketch is **MiniHunterV2.8_Advance**. Its calibration menu starts at **Sensor Check**. Sinyas can read line sensors, test adjustments, and save supported settings to the board.

<div class="card-grid">
  <a class="guide-card" href="sinyas-v2-8.html"><span class="status-chip ready">V2.8 · Sinyas</span><strong>Calibrate with Sinyas</strong><span>Check the sensors, choose a line profile, tune tracking, and balance the wheels.</span></a>
</div>

## Old guides · V2.7
{: #v27-guides}

Use these guides if your sketch is **MiniHunterV2.7**. This firmware uses the OLED and the board controls for calibration.

<div class="card-grid">
  <a class="guide-card" href="line-sensors.html"><span class="status-chip ready">Adjustment</span><strong>Line-sensor calibration</strong><span>Set each line sensor to distinguish the dark arena from the light boundary.</span></a>
  <a class="guide-card" href="enemy-detection.html"><span class="status-chip ready">Functional check</span><strong>Enemy-detection sensor check</strong><span>Confirm each distance sensor changes when a target moves closer.</span></a>
</div>

### Enter CAL MODE

1. Support the robot so it cannot drive away.
2. Power on the robot using the connector or power switch fitted to your revision.
3. Use the latching **MODE** switch to show the **RC/RMT** screen. Do not select BT MODE or RC MODE first.
4. Press **SW1** and **SW2** together and keep holding both buttons for **two seconds**.
5. When the OLED shows **CAL MODE**, release both buttons. The robot remains in CAL MODE after you release them.

Press **SW1 once** to cycle from CAL MODE to **LINE SENSOR ADJUST**. Press **SW1 again** to cycle to **ENEMY DETECTION CHECK**. Hold **SW1** and **SW2** together again to leave calibration, then power off before removing the robot from its stand.
