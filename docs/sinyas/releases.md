---
layout: default
title: Sinyas Releases
description: Download signed Sinyas Android APKs and read the release notes for each public version.
permalink: /sinyas/releases.html
---

# Sinyas releases

Download a signed Android APK and see what changed in each version. Sinyas requires Android 7.0 or later. For pairing and installation steps, see the [Sinyas setup guide](./#1-install-sinyas).

## V1.1

**Latest release** · November 25, 2026

### Drive and layout

- Balanced the joystick spacing on phones with camera cutouts. Speed presets and accessory buttons are stacked in the center.
- Made the headers, buttons, and footer spacing consistent across the Mini Hunter tuning screens. Board instructions and save confirmations sit alongside the buttons to leave more room for editing.

### Mini Hunter calibration

- Load and save Base Mode settings, flag servo angles, and PID tuning on compatible firmware.
- Test unsaved settings for Base Modes 1–4. Use separate **Open** and **Close** buttons to test flag angles.
- Choose whether to ignore either outer distance sensor after the flag drops. Use this when the flag covers a sensor.
- See both line sensors' live ADC readings and potentiometer thresholds beside the recovery settings. Set how many completed recovery attempts count as outside the arena.
- Run the line test with enemy detection off or on. The test starts at zero forward power, the slider limits tracking power, and line recovery takes priority.

For the new Mini Hunter calibration features, use the matching **MiniHunterV2.8_Advance** firmware from Twentynine Robotics.

### Assets

<div class="download-list">
  <a class="download-item" href="../downloads/sinyas/sinyas-v1.1.0.apk" download>
    <strong>Download Sinyas V1.1</strong>
    <span>Signed Android APK · 1.1.0</span>
  </a>
</div>

[SHA-256 checksum for V1.1](../downloads/sinyas/sinyas-v1.1.0.apk.sha256)

---

## V1.0 Initial Release

November 24, 2026

- First public Android release with two-thumb Bluetooth drive, speed presets, and programmable accessory buttons.
- Added Mini Hunter and Hammerhead profiles, Generic controller support, and configuration backup and restore.
- The V1.0 APK available here includes the correction for loading and saving custom Mini Hunter Auto modes with matching firmware.

### Assets

<div class="download-list">
  <a class="download-item" href="../downloads/sinyas/sinyas-v1.0.0.apk?rev=auto-save" download>
    <strong>Download Sinyas V1.0</strong>
    <span>Signed Android APK · 1.0.0</span>
  </a>
</div>

[SHA-256 checksum for V1.0](../downloads/sinyas/sinyas-v1.0.0.apk.sha256)
