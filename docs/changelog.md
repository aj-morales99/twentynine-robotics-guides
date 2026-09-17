---
layout: default
title: Documentation changelog
description: A record of changes to the Twentynine Robotics online guides.
---

# Documentation changelog

## 0.3.9 white-circle favicon 2026 09 17

- Rebuilt the website favicon from the supplied Twentynine Robotics SVG logo.
- Replaced the yellow square with a white circular badge, subtle gray edge, and transparent outer corners.
- Updated every favicon size and the Apple touch icon, with a new cache version so browsers request the revision.

## 0.3.8 site identity and Mini Hunter showcase 2026 09 17

- Added a multi-size Twentynine Robotics favicon for browser tabs and bookmarks, plus an Apple touch icon.
- Added the supplied Mini Hunter multi-angle product photograph to the Mini Hunter overview page.
- Optimized the large photograph for fast web delivery while keeping the full collage visible and selectable.

## 0.3.7 receiver locator visuals 2026 09 17

- Added focused F-10A and F-06A receiver pictures immediately before their binding procedures.
- Circled and labeled each receiver's physical BIND button and status LED location without changing the hardware image.
- Added an English LED-state key for no signal, pairing, and connected states.

## 0.3.6 English RC manual diagrams 2026 09 17

- Replaced all Chinese-language HotRC manual crops in the RC controller guide with complete English recreations.
- Preserved the official HT-10A binding sequence, CH3/CH1 1500 center values, Channel Trim behavior, and Stick Calibration procedure.
- Preserved the official CT-6A binding order and made the TH TRIM and SH TRIM directions immediately identifiable for Mini Hunter users.
- Kept the original manufacturer manuals linked through HotRC technical support for source verification.

## 0.3.5 official RC manual references 2026 09 17

- Removed the approximate RC Cable V1 opposite-bend illustration while retaining the written orientation instruction.
- Replaced the reconstructed binding flow with focused excerpts from the official HotRC HT-10A and CT-6A manuals.
- Split binding into the manufacturer's HT-10A/F-10A and CT-6A/F-06A sequences, including their documented receiver LED states.
- Added official-manual references for HT-10A CH3/CH1 center values, Channel Trim, and Stick Calibration.
- Added the CT-6A manual's TH TRIM and SH TRIM control reference and tied final centering to the Mini Hunter OLED's `Trig:0` and `Turn:0` readings.

## 0.3.4 visual RC controller guide 2026 09 17

- Added separate visual control maps for the bundled HotRC HT-10A joystick transmitter and CT-6A trigger transmitter, with the receiver removed from each product view.
- Documented HT-10A CH3/CH1 and CT-6A CH2/CH1 receiver-channel pairs instead of applying one mapping to both controllers.
- Added code-checked Mini Hunter OLED examples for neutral, forward/reverse, and turning input using the firmware's `Trig:` and `Turn:` display labels.
- Added a shared-header orientation diagram showing the Bluetooth cable bending left and RC Cable V1 bending right.
- Added visual binding flows for HT-10A/F-10A and CT-6A/F-06A, including the required blinking-to-steady receiver LED checkpoint.

## 0.3.3 first-use power and charging guide 2026 09 17

- Added Mini Hunter battery-level checking through the supplied 4-pin JST charge balancer and battery indicator.
- Added the JST-first, USB Type-C-second charging sequence, normal steady-LED behavior, blinking-LED checks, battery-damage warnings, and support contact information.
- Documented the XT30 connector as the normal main-power connection and explained the newer loop switch key as a rapid safety disconnect subject to event quarantine rules.
- Added explicit power-on and power-off procedures and warned against deliberately running a low battery completely flat.
- Clarified that the initial run-down is a supervised motor break-in and component warranty check, normally ending at one bar; no bars is an immediate stop condition.
- Added code-derived AUTO, RC/RMT, mode-selection, delay, countdown, and running OLED previews to the first-use guide.
- Documented the one-second SW1+SW2 exit action for BT, RC, AUTO, and Calibration modes.

## 0.3.2 operation-first navigation and programming references 2026 09 17

- Replaced the code-first Mini Hunter entry point with a no-programming-required guide for controls, safety checks, RC/RMT or AUTO selection, calibration, and first operation.
- Moved Arduino IDE setup, board installation, downloads, uploading, customization, and code references into the Programming section.
- Added a code-checked FullVision STM32 pin map covering motors, switches, line sensors, three- and five-sensor enemy layouts, shared Bluetooth/RC pins, OLED I²C, servo, and Serial1.
- Added a common firmware settings guide for selecting the 1KG or 3KG variable block and tuning scan, attack, speed, and delay values.
- Expanded the searchable function library with return behavior or expected physical/display output, corrected the `FRONT_PIN` example, and documented important sketch-level functions.
- Corrected the configuration note for the reviewed `1KG_MiniHunterV2_7_3SYSTEM_7Modes` source to `SYSTEM = 3` and `NUM_MODES = 7`.

## 0.3.1 RC controller guide 2026 09 17

- Replaced the provisional RC controller page with a complete text-only setup procedure based on the supplied Twentynine Robotics demonstration.
- Recorded RC Cable V1 as the cable normally supplied with the Mini Hunter kit.
- Documented transmitter preparation, CH3/CH1 control mapping, receiver wire orientation, Bluetooth-module removal, binding, RC Mode selection, supported-wheel testing, and channel correction.
- Added explicit safety guidance distinguishing a complete CH1/CH3 plug swap from reversing signal, power, and ground wires.

## 0.3.0 setup visuals draft 2026 09 16

- Added the supplied release-page and Arduino board-selection screenshots to the setup guide.
- Added installed-library references for Adafruit GFX, SSD1306, and BusIO, plus the supplied three-file sketch-folder reference.
- Reused the existing BT0/RST and Device Manager references, added the supplied Arduino tabs screenshot, and replaced the startup placeholder with a code-checked OLED reconstruction.
- Added a modes control visual showing the latching MODE switch and momentary SW1/SW2 switches, with the OLED pins oriented to the right.
- Added a code-derived AUTO menu flow and documented that `NUM_RCRMT = 2` leaves the existing `JS MODE` display case outside the normal selector.
- Repositioned multi-image setup references directly beneath the instructions and outcomes they illustrate instead of grouping them as galleries after each procedure.
- Corrected the modes control visual to match the board reference's vertically arranged blue rectangular switches instead of generic tactile switches.
- Added sanitized installer-warning and in-progress references plus a clearly labeled reconstructed success screen based on the current batch file.
- Removed the unnecessary STM32CubeProgrammer file screenshot placeholder and expanded the private `MH-SETUP-01` shot plan into three hardware photos.
- Expanded line-sensor calibration into a complete white/black test procedure with board potentiometer and OLED adjustment visuals.
- Added code-checked AUTO button instructions and simplified arena diagrams for default Modes 1–6, including the current attack-speed behavior.
- Standardized the Bluetooth guide on the final Mini Hunter V2.6 control-panel file and removed the earlier panel filename.
- Rebuilt calibration instructions around the two-second RC/RMT entry sequence, separated step-by-step technical SVGs, and added three- and five-sensor OLED and direction references.
- Moved each page's section list into the left guide sidebar beneath the active chapter, removing the competing right-side navigation column.
- Added red and green “Know Fact” callouts and introduced the Wheels &amp; Gears Check-up hardware guide with the first loose-wheel and set-screw procedure.
- Replaced the product-only sidebar with a four-kit guide tree, moved the mobile Contents control to the left, labeled unfinished guides as In progress or Pending, and removed the unverified wheel illustration.
- Refined guide-status labels, corrected numbering around inline setup images, clarified the installer-progress screenshot, and added direct Mini Hunter Bluetooth APK and V2.6 panel downloads.

## 0.2.0 navigation and dark theme draft 2026 09 15

- Reorganized Mini Hunter documentation around setup, controllers, calibration, attachments, upgrades, modes, code, and troubleshooting.
- Added dark mode by default with a light/dark preference button.
- Replaced the crowded top navigation with a Mini Hunter chapter sidebar, current-page indicator, breadcrumbs, and Previous/Next guide controls.
- Added a mobile Guide menu drawer while keeping the full chapter list visible on larger screens.
- Simplified the homepage into one clear product chooser and removed duplicated Mini Hunter and Hammerhead sections.
- Reworked the guide navigation using established documentation patterns: grouped chapters, a quieter active-page marker, mobile Contents control, and an optional on-page outline for long articles.
- Reorganized the Mini Hunter overview into task-based sections with one recommended starting point.
- Added beginner-friendly Bluetooth, calibration, modes, code-library, and troubleshooting drafts.
- Kept unfinished hardware procedures clearly marked for verification.
- Removed the private photography checklist from the public repository and all public navigation.

## 0.1.0 text draft 2026 09 15

- Added a text-first Mini Hunter setup and first upload guide.
- Explained the tools before introducing installation steps.
- Separated computer setup and compilation from powered hardware work.
- Added written checkpoints and symptom-based troubleshooting.
- Collected official downloads and the supplied Drive archive references.
- Distinguished the FullVision board package from Mini Hunter robot firmware.
- Replaced the old manual SoftwareSerial timer-edit instruction with the current package workflow.
- Flagged the legacy filename and actual configuration mismatch.
- Reserved Hammerhead as a separate documentation topic without assuming shared hardware procedures.
- Added eleven visible image placeholders with stable `MH-SETUP` reference numbers.
- Added a matching photo and screenshot checklist with poses, required details, privacy checks, and suggested filenames.

This is a documentation draft for review, not a new firmware or board-package release. Hardware acceptance testing and publication are separate steps.
