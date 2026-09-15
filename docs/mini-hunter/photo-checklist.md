---
layout: default
title: Mini Hunter setup photo checklist
description: A numbered checklist for gradually adding supporting photos to the Mini Hunter setup guide.
---

# Mini Hunter setup photo checklist

This checklist matches the numbered image placeholders in the [Mini Hunter setup and first upload guide](setup-and-first-upload.html). The guide can be published before these photographs are ready. Add photos one at a time without waiting for the whole list.

Keep the original full-resolution files. Use bright, even light; avoid glare; clean the background; and make labels readable. Do not add arrows or text to the originals. Edited web copies can receive callouts later.

For hardware photos, disconnect the battery and USB before arranging the robot. Only recreate powered states that are already part of the verified procedure. Keep faces, account names, email addresses, license keys, serial numbers, unrelated files, and notifications out of screenshots.

## Progress checklist

- [ ] MH-SETUP-01 Equipment overview
- [ ] MH-SETUP-02 FullVision release download
- [ ] MH-SETUP-03 FullVision installer window
- [ ] MH-SETUP-04 CubeProgrammer setup file
- [ ] MH-SETUP-05 Arduino board selection
- [ ] MH-SETUP-06 Library Manager
- [ ] MH-SETUP-07 Complete sketch folder
- [ ] MH-SETUP-08 Controller controls
- [ ] MH-SETUP-09 Device Manager COM port
- [ ] MH-SETUP-10 Successful upload
- [ ] MH-SETUP-11 Normal startup screen

## MH-SETUP-01 Equipment overview

**Take:** one landscape photo from directly above. Arrange the Mini Hunter, its FullVision controller, a USB Type-C data cable, and a laptop or the edge of a computer. Keep the items separate enough to recognize.

**Must show:** the complete cable and the robot identity. Do not show a separate USB-to-serial adapter unless that exact photographed board actually requires one.

**Suggested filename:** `mh-setup-01-equipment-overview.jpg`

## MH-SETUP-02 FullVision release download

**Capture:** a browser screenshot of the FullVision v1.5.0 GitHub release with **Assets** expanded. Make `install-windows.bat` readable.

**Crop out:** browser account details, bookmarks, downloads, and unrelated tabs.

**Suggested filename:** `mh-setup-02-fullvision-release.png`

## MH-SETUP-03 FullVision installer window

**Capture:** the installer command window during a normal run. The stage number and description should be readable. A second capture of the final success message is useful but optional.

**Do not include:** private folder names or unrelated terminal output. Do not manufacture a success message if the installation failed.

**Suggested filename:** `mh-setup-03-installer-progress.png`

## MH-SETUP-04 CubeProgrammer setup file

**Capture:** File Explorer showing the extracted STM32CubeProgrammer download and the setup application to run. Include enough of the filename to distinguish it from the original ZIP.

**Do not include:** a downloaded installation key, email address, or unrelated files.

**Suggested filename:** `mh-setup-04-cubeprogrammer-setup.png`

## MH-SETUP-05 Arduino board selection

**Capture:** Arduino IDE 2 with the board selector open and **FullVision-STM32 V1.5 (STM32duino 2.12.0)** visible or selected.

**Must show:** the board name. A COM number is optional in this image because the board can be selected before connection.

**Suggested filename:** `mh-setup-05-board-selection.png`

## MH-SETUP-06 Library Manager

**Capture:** Arduino Library Manager showing the Adafruit GFX Library entry by Adafruit. Repeat for Adafruit SSD1306 if both cannot be shown clearly in one image.

**Must show:** library name, author, and installed state or Install button.

**Suggested filenames:** `mh-setup-06a-adafruit-gfx.png` and `mh-setup-06b-adafruit-ssd1306.png`

## MH-SETUP-07 Complete sketch folder

**Capture:** File Explorer showing the sketch folder and its `.ino`, `.h`, and `.cpp` files. A second Arduino IDE screenshot can show the corresponding tabs.

**Use:** a clean copy of the project with no personal customer data or secret code visible in thumbnails.

**Suggested filenames:** `mh-setup-07a-sketch-files.png` and `mh-setup-07b-arduino-tabs.png`

## MH-SETUP-08 Controller controls

**Take:** one straight-down close-up of the FullVision controller. Make the USB Type-C connector, BT0 button, RST button, and printed labels sharp and readable. If the Bluetooth module normally covers the buttons, take one installed view and one verified safely removed view.

**Before taking it:** disconnect every power source. Do not remove the Bluetooth module until its safe removal and orientation have been confirmed.

**Suggested filenames:** `mh-setup-08a-controller-overview.jpg` and `mh-setup-08b-bt0-rst-closeup.jpg`

## MH-SETUP-09 Device Manager COM port

**Capture:** Windows Device Manager with **Ports (COM & LPT)** expanded and the controller's CH340 serial entry visible.

**Must show:** the device description and its real COM number. The number does not need to match the example in the guide.

**Suggested filename:** `mh-setup-09-device-manager-com-port.png`

## MH-SETUP-10 Successful upload

**Capture:** Arduino IDE after a real successful upload. Include the selected FullVision board, the selected COM port, and the final successful result in the Output panel.

**Do not include:** unrelated source code, personal paths, tokens, or an error cropped to look like success.

**Suggested filename:** `mh-setup-10-upload-success.png`

## MH-SETUP-11 Normal startup screen

**Take:** a close-up of the OLED after BT0 has been released and RST pressed following a successful upload. Make the expected Mini Hunter menu readable.

**Also useful:** one wider photo showing that the screen belongs to the same secured robot. Keep drive power disconnected for this documentation step unless the exact tested setup requires and safely permits it.

**Suggested filenames:** `mh-setup-11a-oled-menu.jpg` and `mh-setup-11b-robot-after-upload.jpg`

## Adding a completed image to GitHub later

1. Make a web copy of the original photo; keep the original unchanged.
2. Crop the web copy and remove private information.
3. Add callouts only when they explain a control or choice.
4. Save it using the suggested filename in `documentation/assets/images/mini-hunter/`.
5. Replace the matching **Image to add later** box in the guide with Markdown like this:

```markdown
![FullVision controller with the USB Type-C connector, BT0 button, and RST button labeled](../assets/images/mini-hunter/mh-setup-08b-bt0-rst-closeup.jpg)

*Figure MH-SETUP-08. FullVision controller controls used during programming.*
```

Write alternative text that describes the useful information in the image. Keep the same information in the written procedure so the image remains supporting material.

[Back to the setup guide](setup-and-first-upload.html)
