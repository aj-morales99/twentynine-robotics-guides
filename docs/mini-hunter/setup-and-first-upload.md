---
layout: default
title: Mini Hunter setup and first upload
description: A beginner-friendly Windows guide for preparing and programming a Mini Hunter with the FullVision STM32 V1.5 controller.
---

# Mini Hunter setup and first upload

Twentynine Robotics

This guide helps you prepare a Windows computer to program a Mini Hunter with a FullVision STM32 V1.5 controller. You will install the software, open the robot program, check it for errors, and learn how to upload it through the board's USB-to-serial connection.

You do not need to understand all the code before starting. Complete one section at a time and check the result before continuing. Photographs can help identify parts, but no step in this guide requires a photograph.

**Applies to:** the FullVision STM32 V1.5 package `FullVision:stm32@1.5.0`, based on STM32duino 2.12.0. The physical upload steps apply to the Mini Hunter controller described in the supplied hardware instructions: USB Type-C programming connection and buttons labeled **BT0** and **RST**. Other board revisions can use different controls.

## Find your starting point

- [Understand the tools](#1-understand-the-tools)
- [Prepare your computer and files](#2-prepare-your-computer-and-files)
- [Install the FullVision software](#3-install-the-fullvision-software)
- [Install STM32CubeProgrammer](#4-install-stm32cubeprogrammer)
- [Select the board and install libraries](#5-select-the-board-and-install-libraries)
- [Open and check the robot program](#6-open-and-check-the-robot-program)
- [Connect the controller and find its port](#7-connect-the-controller-and-find-its-port)
- [Upload and return to normal operation](#8-upload-and-return-to-normal-operation)
- [Troubleshoot by symptom](#9-troubleshoot-by-symptom)
- [Record your working setup](#10-record-your-working-setup)

All download links are collected on the [downloads page](downloads.html).

Visible boxes marked **Image to add later** are publishing placeholders. Each box has a reference number that matches the [photo checklist](photo-checklist.html). You can follow the procedure without those images.

## 1 Understand the tools

Your robot has a controller board. The board stores and runs a program that tells the robot what to do. Installing software on your computer does not, by itself, change the program on the robot. **Uploading** is the step that writes a program to the controller.

These names will appear during setup:

| Name | What it does |
| --- | --- |
| Arduino IDE | The computer application where you open, check, and upload code. |
| Sketch | Arduino's name for a program project. A sketch is a folder, not just one loose file. |
| FullVision board package | Tells Arduino how to build a program for this controller and which upload tools to use. |
| Arduino CLI | A helper used by the automatic installer. You do not need to learn commands for the normal setup. |
| STM32CubeProgrammer | STMicroelectronics software used to write the compiled program to the STM32 chip. |
| Library | Reusable code that helps the sketch operate hardware, such as its display. |
| COM port | The numbered serial connection Windows assigns to a connected device, for example COM7. |
| Bootloader mode | A startup mode in which the controller waits to receive a program. |
| Firmware | The program stored on the controller. |

The FullVision board package and Mini Hunter firmware are different downloads. Installing the board package does not install the Mini Hunter robot sketch.

### Why use the FullVision package

The FullVision package already includes the SoftwareSerial timer arrangement required by this project. Select this package instead of following the old instruction to edit `SoftwareSerial.cpp` inside the official STM32 package.

You may keep an official STM32 board package installed for other projects. Selecting a board in Arduino determines which package is used for the current sketch. See the [FullVision technical notes](https://github.com/aj-morales99/FullVision-STM32V1.5/blob/main/FULLVISION.md).

## 2 Prepare your computer and files

### What you need now

- A computer running 64-bit Windows 10 or newer; Windows 11 is suitable for this workflow.
- Internet access for the installer and its downloads.
- Permission to install software on the computer.
- A complete copy of the Mini Hunter sketch supplied for your robot.

Arduino lists its supported operating systems in the [official IDE installation guide](https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE). This walkthrough covers Windows; do not run the Windows batch installer on another operating system.

### What you need later

- Your Mini Hunter with the matching FullVision controller.
- A USB Type-C **data** cable for the documented controller. A cable that only supplies power cannot carry programming data.
- Access to the buttons labeled BT0 and RST.

> **Image to add later — MH-SETUP-01**  
> Equipment overview: Mini Hunter, FullVision controller, USB Type-C data cable, and Windows computer. See the [photo checklist](photo-checklist.html#mh-setup-01-equipment-overview).

For the documented board, the USB programming connection is already provided. A separate USB-to-serial adapter is not part of this main procedure. If your board requires loose programming wires, use its verified pinout and voltage instructions instead of guessing from this guide.

### Keep a backup before you change anything

1. Find the folder containing the supplied robot sketch.
2. Copy the whole folder to a safe location as your unchanged backup.
3. Make a second copy to use for editing and uploading.
4. Keep any release notes supplied with those files.

Uploading replaces the program on the board. Having the original source files makes it easier to rebuild and upload that program again. Simply connecting the robot to Arduino does not download an editable copy of its existing sketch.

**Checkpoint:** you have an unchanged backup and a separate working copy. The robot can remain disconnected while you complete the software and code checks below.

## 3 Install the FullVision software

### Download the correct installer

1. Open the [FullVision v1.5.0 release](https://github.com/aj-morales99/FullVision-STM32V1.5/releases/tag/v1.5.0).
2. Find the section named **Assets**. Expand it if necessary.
3. Download **install-windows.bat**. A [direct installer download](https://github.com/aj-morales99/FullVision-STM32V1.5/releases/download/v1.5.0/install-windows.bat) is also available.
4. Locate the downloaded file in your Downloads folder.

> **Image to add later — MH-SETUP-02**  
> GitHub release page with **Assets** expanded and `install-windows.bat` identified. See the [photo checklist](photo-checklist.html#mh-setup-02-fullvision-release-download).

The `.bat` ending means this file runs a sequence of Windows commands. The automatically generated **Source code** ZIP on GitHub is not the installer and is not your Mini Hunter sketch.

Use the release linked here for this guide. If you choose a newer release from the [latest release page](https://github.com/aj-morales99/FullVision-STM32V1.5/releases/latest), read its notes because versions, prompts, or steps may have changed.

### Run the installer

1. Save any work in Arduino IDE, then close every Arduino IDE window.
2. Double-click `install-windows.bat`.
3. Keep its command window open and read the prompts.
4. If Arduino IDE is missing, follow the installer's prompt to install it. If a browser opens instead, download Arduino IDE 2 from the [official Arduino software page](https://www.arduino.cc/en/software), complete its installation, and return to the waiting window. Keep Arduino IDE closed while the FullVision setup continues.
5. Let the installer finish downloading the required tools and board package.
6. If it requests STM32CubeProgrammer, complete section 4, then return to this window.

> **Image to add later — MH-SETUP-03**  
> FullVision installer command window showing its numbered progress stages. See the [photo checklist](photo-checklist.html#mh-setup-03-fullvision-installer-window).

Approve an administrator prompt only when you recognize the installation you started. If Windows or security software blocks a download, verify its source and follow your computer administrator's policy. Do not disable security protection to continue.

### Understand the progress messages

The v1.5.0 installer works through five checks:

1. Arduino IDE 2.
2. Arduino CLI.
3. The FullVision board package.
4. STM32CubeProgrammer.
5. The installed board packages.

Downloads may take time. A paused window may also be waiting for your response. Read the last visible message before closing it or starting another installer.

The normal success message for this release is:

```text
SUCCESS: FullVision:stm32@1.5.0 is installed.
```

**Checkpoint:** the installer reaches its success message. This confirms computer setup; it does not confirm that the robot has been connected or programmed. If the setup reports an error, resolve that error before uploading.

## 4 Install STM32CubeProgrammer

STM32CubeProgrammer is separate from Arduino IDE. Arduino uses its command-line component during the upload. You do not normally need to open its graphical application to upload from Arduino.

If the FullVision installer already finds STM32CubeProgrammer and succeeds, skip this section.

### Download from STMicroelectronics

1. Open the [official STM32CubeProgrammer download page](https://www.st.com/en/development-tools/stm32cubeprog.html).
2. Find the software download section and choose the Windows 64-bit package.
3. Complete any requested account or download details and review the license terms.
4. Wait for the download to finish.

Download **STM32CubeProgrammer**, not STM32CubeIDE or STM32CubeMX. Their similar names refer to different applications.

The CubeProgrammer version does not need to match the FullVision package number. For example, board-package version 1.5.0 is not an instruction to install CubeProgrammer 1.5.0.

### Extract and install

1. If the download is a ZIP, right-click it and choose **Extract All**.
2. Open the extracted folder.
3. Run the included setup application, whose name begins with `SetupSTM32CubeProgrammer`.
4. Follow the installation prompts. Keep the default installation folder for this beginner workflow.
5. Complete installation of the main application and its command-line tool. The optional Trusted Package Creator is not needed for this upload workflow.
6. Return to the waiting FullVision installer and continue when prompted. If that window has closed, run `install-windows.bat` again with Arduino IDE closed.

> **Image to add later — MH-SETUP-04**  
> Extracted STM32CubeProgrammer folder and the correct setup application. See the [photo checklist](photo-checklist.html#mh-setup-04-cubeprogrammer-setup-file).

ST documents ZIP extraction, the Windows setup application, and the optional component in its [installation instructions](https://dev.st.com/stm32cube-docs/prog/2.23.0/en/docs/markup/CubeProg_How_To_Start/CubeProg_Installation.html).

The usual command-line tool location is:

```text
C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin\STM32_Programmer_CLI.exe
```

You do not need to type this path during a normal installation. It is here to help you check a missing-tool error.

**Checkpoint:** FullVision setup reports `Found STM32CubeProgrammer` and eventually reaches its success message.

The [downloads page](downloads.html#supplied-drive-archive) also preserves the supplied Drive reference. The main walkthrough uses ST's official download; the FullVision installer itself does not bundle CubeProgrammer.

## 5 Select the board and install libraries

### Select the FullVision board

1. Open Arduino IDE 2 after setup has finished.
2. Open **Tools > Board** and locate the FullVision package's board entry. You can also use the board selector near the top of the window.
3. Select **FullVision-STM32 V1.5 (STM32duino 2.12.0)**.
4. If the board is not listed, close Arduino IDE, check that the installer completed successfully, and reopen Arduino IDE.

> **Image to add later — MH-SETUP-05**  
> Arduino IDE board selector with the FullVision board selected. See the [photo checklist](photo-checklist.html#mh-setup-05-arduino-board-selection).

You can select the board and compile a sketch while the robot is disconnected. A COM port is needed later for uploading.

Do not select an Arduino Uno, a different STM32 family, or the generic STM32F1 board as a substitute for a missing FullVision entry.

### Leave the package defaults in place

| Setting | Expected configuration for this package |
| --- | --- |
| Microcontroller | STM32F103C8T6, 64 KB flash |
| Upload method | STM32CubeProgrammer Serial |
| USB support | Native CDC, generic Serial supersedes UART |
| U(S)ART support | Enabled, generic Serial |
| USB speed | Low/Full Speed |
| Optimization | Smallest, `-Os` |
| Debug symbols and core logs | None |
| C runtime | Newlib Nano |

Some options are fixed by the package and may not appear as separate menus. Do not change unrelated settings just to make your screen match an older screenshot. These defaults are described in the [FullVision package notes](https://github.com/aj-morales99/FullVision-STM32V1.5/blob/main/FULLVISION.md).

### Install the display libraries

The supplied Mini Hunter code uses two Adafruit display libraries. The FullVision board installer does not install these project libraries for you.

1. In Arduino IDE, open **Tools > Manage Libraries**.
2. Search for **Adafruit GFX Library** and check that the author is Adafruit.
3. Install it. Accept its required dependencies if prompted.
4. Search for **Adafruit SSD1306**, also by Adafruit, and install it with its dependencies.
5. If **Adafruit BusIO** is required, install that dependency too.

> **Image to add later — MH-SETUP-06**  
> Arduino Library Manager showing the correct Adafruit GFX and SSD1306 entries. See the [photo checklist](photo-checklist.html#mh-setup-06-library-manager).

Use any library versions specified by the robot firmware release. If no versions were supplied, record the versions you install and complete the compilation check in section 6. A newly available library version is not automatically a tested Mini Hunter version.

For a supplied library ZIP, use **Sketch > Include Library > Add .ZIP Library** and select one library ZIP at a time. This is different from installing an application from a ZIP. See [Arduino's library installation instructions](https://support.arduino.cc/hc/en-us/articles/5145457742236-Install-libraries-in-the-Arduino-IDE).

The STM32 board package supplies its own compatible core libraries, including Wire, Servo, and SoftwareSerial. Do not install an unrelated library with the same name to fix a missing FullVision package.

**Checkpoint:** the FullVision board is selected and both Adafruit display libraries are installed.

## 6 Open and check the robot program

### Keep the sketch files together

The supplied legacy Mini Hunter sketches have three main files:

- An `.ino` file containing the robot program.
- `FullVision-STM32.h`, which declares the board functions and settings used by the program.
- `FullVision-STM32.cpp`, which contains their implementation.

All three belong in the same sketch folder. The main `.ino` name must match that folder's name. For example, the supplied 1 kg sketch uses this arrangement:

```text
1KG_MiniHunterV2_7_3SYSTEM_4Modes/
  1KG_MiniHunterV2_7_3SYSTEM_4Modes.ino
  FullVision-STM32.h
  FullVision-STM32.cpp
```

This shows the existing filenames, not a new naming standard. Do not rename the companion files during first-time setup. Their names must still match the code's `#include` statements.

1. Extract the complete sketch ZIP if your files were supplied in one.
2. Open the working-copy folder, not your backup.
3. Open the `.ino` file in Arduino IDE.
4. Confirm that the companion `.h` and `.cpp` files are present. They normally appear as tabs.
5. If Arduino offers to move the `.ino` into a matching folder, ensure the companion files also end up in that folder. Do not continue with only the `.ino`.

> **Image to add later — MH-SETUP-07**  
> File Explorer and Arduino tabs showing the three sketch files together. See the [photo checklist](photo-checklist.html#mh-setup-07-complete-sketch-folder).

### Check the configuration before uploading

The robot's weight class and its sensor/mode configuration are different choices. A folder name is not proof of the values compiled into its code.

In the supplied legacy library, `SYSTEM` controls the three- or five-enemy-sensor configuration, and `NUM_MODES` controls the autonomous-mode count. Both declarations are in `FullVision-STM32.cpp`:

| Intended legacy configuration | `SYSTEM` | `NUM_MODES` |
| --- | --- | --- |
| 3 systems and 4 modes | 3 | 4 |
| 5 systems and 7 modes | 5 | 7 |

**Important:** both code copies supplied for this revision contain `SYSTEM = 5` and `NUM_MODES = 7`, including the copy whose filename says `3SYSTEM_4Modes`. Before uploading one of these files, confirm the intended configuration for your physical robot. Do not assume the filename has already selected it.

These two settings do not convert all 1 kg behavior into 3 kg behavior. Use the correct weight-class program. The two supplied `.ino` files also differ in behavior and tuning.

For normal robot use, leave the production `loop()` active. The legacy `test()` routine is a Bluetooth configuration bridge, not a step required to install the board. Arduino repeatedly calls `loop()`; simply having a function named `test()` in the file does not run it. The separate Bluetooth service guide will explain the temporary function-renaming procedure and how to restore normal operation.

### Verify without uploading

1. Save your working sketch.
2. Confirm that the FullVision board remains selected.
3. Click **Verify**, the check-mark button, or choose **Sketch > Verify/Compile**.
4. Wait for compilation to finish. The first build can take longer than later builds.
5. Read the Output panel at the bottom of Arduino IDE.

Verify checks whether the code can be built. It does not write to the controller and cannot prove that wiring, sensor settings, or motor behavior are correct.

**Checkpoint:** compilation finishes without errors and shows a memory-use summary. If it fails, fix the first meaningful error before connecting or uploading. A final `exit status 1` line is only a summary; the useful explanation is usually above it.

This is a good place to stop if you do not have the robot available yet.

## 7 Connect the controller and find its port

### Prepare the robot safely

Disconnect the robot battery before this USB-only programming procedure. Keep wheels and mechanisms clear of hands and loose objects, and support the robot securely so it cannot drive away. Do not assume an uploaded program will wait for you before operating outputs.

Do not connect battery and USB power together unless the instructions for your exact controller explicitly allow it. If USB alone does not power the controller as expected, stop and confirm its power arrangement rather than trying different power pins.

Find the labels **BT0** and **RST** on your board:

- BT0 selects the programming startup mode when used during startup.
- RST resets, or restarts, the controller. Pressing reset is not a factory reset and does not restore an earlier program.

The supplied hardware instructions place these buttons below the Bluetooth module. If the module blocks access, do not pull it out while powered or force its connector. Obtain the removal procedure for that assembly before proceeding. Software installation and compilation do not require removing it.

> **Image to add later — MH-SETUP-08**  
> Straight-on controller close-up with USB Type-C, BT0, and RST clearly labeled. See the [photo checklist](photo-checklist.html#mh-setup-08-controller-controls).

If your board has different labels, switches instead of buttons, or an external programming adapter, stop here and use its revision-specific instructions.

### Find the COM port

1. With the controller disconnected from USB, right-click the Windows Start button and open **Device Manager**.
2. Look for **Ports (COM & LPT)**. The category may be absent until a serial device is connected.
3. Hold down the board's BT0 button.
4. While holding BT0, connect the controller's programming USB Type-C port to the computer with the data cable.
5. Wait for Windows to detect the connection, then release BT0. A connection sound may play, but use Device Manager as the check because sound can be disabled.
6. Look for the newly appearing serial entry. The documented board uses a CH340-style connection, which may appear as `USB-SERIAL CH340 (COM7)`.
7. Write down your own COM number. COM7 is only an example.

> **Image to add later — MH-SETUP-09**  
> Windows Device Manager showing the controller's CH340 COM-port entry. See the [photo checklist](photo-checklist.html#mh-setup-09-device-manager-com-port).

The BT0-while-connecting sequence comes from the supplied Mini Hunter upload instructions. It assumes the controller was not already powered by another source.

A blank OLED can occur while the controller waits for an upload. **A blank display alone does not prove programming mode:** power or display problems can also leave it blank. Likewise, a COM port proves the USB serial device is detected, not that the STM32 is ready for an upload.

If no serial entry appears, follow the no-COM-port checks in section 9 before continuing.

**Checkpoint:** you have identified the controller's actual COM port and prepared the matching controller for an upload.

## 8 Upload and return to normal operation

### Upload the checked program

1. Return to Arduino IDE with the working sketch open.
2. Confirm the selected board is **FullVision-STM32 V1.5 (STM32duino 2.12.0)**.
3. Select your COM number using **Tools > Port** or the board/port selector.
4. Close Serial Monitor, Serial Plotter, and other applications that may be connected to this port. Do not leave the CubeProgrammer graphical application connected to it.
5. Confirm that you completed the BT0 startup sequence in section 7. If you have reset or reconnected the controller normally since then, repeat that sequence.
6. Click **Upload**, the right-arrow button, or choose **Sketch > Upload**.
7. Wait through compilation and the transfer. Do not disconnect USB, press reset, or change the wiring while the tool is writing or verifying the program.
8. Read the final output. Continue only after the upload reports success without a programming error.

> **Image to add later — MH-SETUP-10**  
> Arduino IDE showing the selected board and port plus a successful upload result. See the [photo checklist](photo-checklist.html#mh-setup-10-successful-upload).

The normal **Verify** button compiles on the computer. A programming tool's later verification checks data written to the controller. These are different checks.

### Start the uploaded program

1. After the upload finishes, ensure BT0 is released.
2. Press and release RST once to restart the controller normally.
3. Keep the battery disconnected and the robot secured while observing startup. A servo or another USB-powered output may still move; keep clear of mechanisms.
4. Check for the startup behavior expected from the exact sketch you uploaded. The supplied Mini Hunter program normally uses the OLED for its menu, but an upload-success message does not guarantee that the display or every sensor is working.
5. If the program does not start as expected, use section 9 before enabling drive power.

> **Image to add later — MH-SETUP-11**  
> Mini Hunter OLED showing the expected menu after reset. See the [photo checklist](photo-checklist.html#mh-setup-11-normal-startup-screen).

**Checkpoint:** Arduino reports a successful upload and the controller starts the intended program. Motor testing, sensor calibration, and competition operation are separate procedures; do not start a match mode merely to check whether uploading worked.

Before reinstalling a removed module or changing connections, disconnect USB and all other power. Do not reconnect a module with uncertain orientation.

## 9 Troubleshoot by symptom

### The installer says Arduino IDE is still open

Save and close every Arduino IDE window, wait briefly, and run the installer again. On a shared computer, check whether another session is using Arduino before ending processes. Do not delete package folders as a first troubleshooting step.

### A software download fails

Read which file or stage failed. Check internet access and open the release page in your browser. An interrupted download is not evidence of a board fault. On a managed network, ask the administrator about blocked downloads. Do not substitute a random installer from a search advertisement.

### STM32CubeProgrammer is not found

Check for `STM32_Programmer_CLI.exe` in the default folder shown in section 4. If it is missing, complete or repair the official installation. If it exists, close and rerun FullVision setup. A custom installation directory can require additional path configuration; use the default location for this beginner walkthrough.

### No COM port appears

1. Try a cable known to transfer data, not just charge a device.
2. Try another computer USB port and, if possible, connect directly instead of through a hub.
3. Watch Device Manager while disconnecting and reconnecting the controller.
4. Look for a warning-marked or unknown device.
5. If Windows needs a driver for the CH340 connection, use the matching driver from the [downloads page](downloads.html), install it, and reconnect.

Do not install a CH340 driver for an unrelated adapter chip. Do not replace the serial device's driver with a DFU or ST-LINK driver: these are different programming interfaces.

### The board is detected but uploading reports no response

Check the selected COM number. Close programs using that port. With the battery disconnected, repeat the BT0-while-connecting sequence and try again. If the problem remains, record the complete upload error and confirm the controller revision. Do not experiment with option bytes, protection settings, or full-chip erase to solve a routine connection problem.

### A library header cannot be found

The exact filename tells you where to look:

| Error mentions | First check |
| --- | --- |
| `Adafruit_GFX.h` | Install Adafruit GFX Library. |
| `Adafruit_SSD1306.h` | Install Adafruit SSD1306. |
| `Adafruit_I2CDevice.h` | Check the Adafruit BusIO dependency. |
| `FullVision-STM32.h` | Restore the companion file in the sketch folder. |
| `stm32f1xx_ll_i2c.h` | Confirm the FullVision STM32 board package is selected and installed. |

If the compiler reports multiple matching libraries, note which one it actually uses before removing anything. Verify again after resolving the specific problem.

### There are too many or too few robot modes

Check the configuration inside the working sketch, not its folder name. In the supplied legacy files, review both `SYSTEM` and `NUM_MODES`. A successful upload does not establish that these settings match the physical robot.

### The program does not fit

Keep the intended FullVision 64 KB profile and size-optimization default. Save the full memory report and have the sketch reviewed. Do not select a larger flash size just to silence the error; that changes the assumed hardware capacity.

### Uploading succeeds but the OLED stays blank

Release BT0 and reset after programming has finished. Confirm that you uploaded the intended robot sketch. If it remains blank, disconnect power before checking display connections. The supplied library can stop during initialization if its OLED is not found, so repeated uploads alone may not solve the problem.

### You need help from Twentynine Robotics

Send the robot weight class, controller revision if known, sketch filename, configuration values, selected board, COM number, and the full error text. Explain which step failed and whether this setup worked previously. Text copied from the Output panel is useful even without a screenshot.

## 10 Record your working setup

Keep a short setup record with your working sketch:

```text
Date:
Robot weight class:
Controller revision:
Sketch filename and firmware version:
SYSTEM and NUM_MODES values:
FullVision board-package version:
Arduino IDE version:
STM32CubeProgrammer version:
Adafruit GFX version:
Adafruit SSD1306 version:
Adafruit BusIO version if installed:
Compilation result:
Upload result:
Observed startup behavior:
```

This makes it easier to repeat a working installation and explain what changed after an update. A successful first upload is the end of this setup procedure, not a complete test of the robot.

[Back to all guides](../) · [Downloads and installation links](downloads.html) · [Photo checklist](photo-checklist.html)
