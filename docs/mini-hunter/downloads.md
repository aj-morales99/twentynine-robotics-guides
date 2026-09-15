---
layout: default
title: Mini Hunter downloads
description: Official and supplied downloads used with the Mini Hunter setup guide.
---

# Mini Hunter downloads and installation links

Use this page with the [setup and first upload guide](setup-and-first-upload.html). You do not need every download listed here. Start with the FullVision installer and follow the prompts for anything missing.

## Main downloads

| Download | When you need it |
| --- | --- |
| [FullVision v1.5.0 release](https://github.com/aj-morales99/FullVision-STM32V1.5/releases/tag/v1.5.0) | The board-package release covered by this guide. |
| [FullVision Windows installer](https://github.com/aj-morales99/FullVision-STM32V1.5/releases/download/v1.5.0/install-windows.bat) | Recommended setup entry point. This is an executable batch script, not the robot sketch. |
| [Latest FullVision release](https://github.com/aj-morales99/FullVision-STM32V1.5/releases/latest) | Check for updates and read their release notes before changing versions. |
| [Arduino IDE](https://www.arduino.cc/en/software) | Install Arduino IDE 2 if it is missing or the automatic prerequisite installation does not finish. |
| [STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html) | Install the Windows 64-bit package for the serial upload tool. |
| [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library) | Library information and source. Prefer installing through Arduino Library Manager. |
| [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306) | OLED library information and source. Prefer Library Manager. |
| [Adafruit BusIO](https://github.com/adafruit/Adafruit_BusIO) | Supporting library when required by the display-library versions installed. |

The FullVision board package is not the Mini Hunter robot program. Use the complete robot sketch supplied for your weight class and hardware configuration. Do not upload a different robot's sketch because it uses the same controller.

## Supplied Drive archive

These are the references carried forward from the supplied setup materials. Drive access and file contents can change. If a link requests access or does not download, use the main sources above or ask the maintainer; do not treat a Drive file as a newer release merely because it was downloaded today.

| Supplied reference | Note |
| --- | --- |
| [FullVision setup archive](https://drive.google.com/drive/u/0/folders/1qsGufWSzCc8_98n7x393DmpHfUxde8Ee) | Original collection of guides and supporting downloads. Older instructions may describe a different board-package workflow. |
| [STM32CubeProgrammer Drive copy](https://drive.google.com/file/d/1hZWxVY1UZ8AlvZpEAFazvlonHw3TwquL/view) | Identified in the previous guide as Windows 64-bit v2.20. Use ST's official download for the main procedure. Check the supplied copy's version and applicable terms before use. |
| [CH340 and CH341 driver ZIP](https://drive.google.com/file/d/1rIK8Ppsrp56YOTP3qDZx0YgryvHtBiEB/view) | Supplied CH341SER package. Needed only if Windows cannot use the board's CH340 serial connection. |
| [Adafruit GFX ZIP](https://drive.google.com/file/d/1yK7d-bpYhiMZoWpMAwYzKSuEhe4RDpyS/view) | Supplied library ZIP for the Add .ZIP Library method. |
| [Adafruit SSD1306 ZIP](https://drive.google.com/file/d/1D2EwTrAxy3Tkei8fI6w6Bzkc_sLgvlaw/view) | Supplied library ZIP; any required dependencies must also be available. |

Downloading one ZIP does not make the FullVision installation fully offline. The automatic installer normally retrieves the board package and supporting tools from the internet.

## Manual board-package installation

Use this alternative only if you are not using the automatic installer or are troubleshooting with help. It still requires Arduino IDE, STM32CubeProgrammer, and the sketch libraries.

1. Open **File > Preferences** in Arduino IDE.
2. Find **Additional Boards Manager URLs** and open its list editor.
3. Add each URL below on its own line. Preserve entries for other projects.
4. Save the preferences.
5. Open **Tools > Board > Boards Manager**, search for FullVision, and install version 1.5.0.
6. Select the FullVision board, then continue with the setup guide.

```text
https://github.com/aj-morales99/FullVision-STM32V1.5/releases/download/v1.5.0/package_fullvision_index.json
https://github.com/stm32duino/BoardManagerFiles/raw/main/package_stmicroelectronics_index.json
```

Both indexes are needed: the FullVision entry describes its package, and the STM32duino entry supplies supporting tool definitions. See the [maintainer's installation reference](https://github.com/aj-morales99/FullVision-STM32V1.5#manual-boards-manager-installation).

## Further installation help

- [Arduino IDE installation](https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE)
- [Arduino library installation](https://support.arduino.cc/hc/en-us/articles/5145457742236-Install-libraries-in-the-Arduino-IDE)
- [STM32CubeProgrammer installation](https://dev.st.com/stm32cube-docs/prog/2.23.0/en/docs/markup/CubeProg_How_To_Start/CubeProg_Installation.html)
- [FullVision package source and technical documentation](https://github.com/aj-morales99/FullVision-STM32V1.5)
