---
layout: default
title: Documentation changelog
description: A record of changes to the Twentynine Robotics online guides.
---

# Documentation changelog

## 0.3.0 setup visuals draft 2026 09 16

- Added the supplied release-page and Arduino board-selection screenshots to the setup guide.
- Added installed-library references for Adafruit GFX, SSD1306, and BusIO, plus the supplied three-file sketch-folder reference.
- Reused the existing BT0/RST and Device Manager references, added the supplied Arduino tabs screenshot, and replaced the startup placeholder with a code-checked OLED reconstruction.
- Added a modes control visual showing the latching MODE switch and momentary SW1/SW2 switches, with the OLED pins oriented to the right.
- Added a code-derived AUTO menu flow and documented that `NUM_RCRMT = 2` leaves the existing `JS MODE` display case outside the normal selector.
- Repositioned multi-image setup references directly beneath the instructions and outcomes they illustrate instead of grouping them as galleries after each procedure.
- Corrected the modes control visual to match the board reference's vertically arranged blue rectangular switches instead of generic tactile switches.
- Added sanitized installer warning and interrupted-run references plus a clearly labeled reconstructed success screen based on the current batch file.
- Removed the unnecessary STM32CubeProgrammer file screenshot placeholder and expanded the private `MH-SETUP-01` shot plan into three hardware photos.
- Expanded line-sensor calibration into a complete white/black test procedure with board potentiometer and OLED adjustment visuals.
- Added code-checked AUTO button instructions and simplified arena diagrams for default Modes 1–6, including the current attack-speed behavior.
- Standardized the Bluetooth guide on the final Mini Hunter V2.6 control-panel file and removed the earlier panel filename.
- Rebuilt calibration instructions around the two-second RC/RMT entry sequence, separated step-by-step technical SVGs, and added three- and five-sensor OLED and direction references.
- Moved each page's section list into the left guide sidebar beneath the active chapter, removing the competing right-side navigation column.
- Added red and green “Know Fact” callouts and introduced the Wheels &amp; Gears Check-up hardware guide with the first loose-wheel and set-screw procedure.
- Replaced the product-only sidebar with a four-kit guide tree, moved the mobile Contents control to the left, labeled unfinished guides as In progress or Pending, and removed the unverified wheel illustration.

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
