---
layout: default
title: Mini Hunter specifications and upgrade paths
description: Identify a Basic or Advanced Mini Hunter, compare specifications, and understand the modular path from a 1 kg build to a 3 kg configuration.
permalink: /mini-hunter/specifications-and-upgrades.html
---

# Mini Hunter specifications and upgrade paths

Use this page to identify your Mini Hunter build, understand its installed hardware, and plan upgrades without replacing the complete robot.

<span class="status-chip ready">Ready</span>

<div class="upgrade-flow" aria-label="Mini Hunter upgrade path">
  <section><small>START</small><strong>Basic Build</strong><span>3 enemy sensors<br>4 combat modes</span></section>
  <span class="upgrade-flow__arrow" aria-hidden="true">→</span>
  <section><small>MODULAR UPGRADES</small><strong>Advanced Build</strong><span>5 enemy sensors<br>7 combat modes</span></section>
  <span class="upgrade-flow__arrow" aria-hidden="true">→</span>
  <section><small>CATEGORY CONVERSION</small><strong>3 kg Build</strong><span>Steel conversion set<br>Wider drivetrain</span></section>
</div>

<div class="know-fact know-fact--success"><span class="know-fact__label">Upgradeable platform</span><p>A Basic Mini Hunter can be upgraded one module at a time until it reaches the Advanced configuration. An Advanced unit can then accept the 3 kg conversion hardware. Keep the original 1 kg parts so the robot can be converted back for a lower-weight category.</p></div>

## Is yours Basic or Advanced?

The fastest check is the number of forward enemy-detection sensors. Use the other differences as confirmation.

| Identification point | Basic Build | Advanced Build |
|---|---|---|
| Enemy-detection sensors | **3** front sensors | **5** sensors covering a wider detection pattern |
| Line sensors | 2 | 2 |
| Gearbox speed | 700–800 RPM | 900–1,000 RPM |
| Blade set | 0.2 mm spring-steel blade | 0.2 mm spring-steel blade plus 2 mm stainless-steel blade |
| Installed autonomous modes | 4 combat modes | 7 combat modes |
| Standard battery | 2S 2,500 mAh | 2S 2,500 mAh |
| Standard wheels | 30 mm wide × 10 mm thick silicone | 30 mm wide × 10 mm thick silicone |

### Quick identification procedure

1. Keep the robot powered off and look through the front sensor openings.
2. Count the enemy-detection sensors: three normally indicates Basic; five indicates Advanced.
3. Start the robot safely and check the number of installed autonomous modes on the OLED menu.
4. Check the included blade set and gearbox specification as secondary confirmation.

<div class="note"><strong>Not sure?</strong> Previous owners may have installed individual upgrades, so a robot can have a mixed configuration. Identify the installed parts instead of relying only on the original box or purchase name.</div>

## Shared core platform

Both Basic and Advanced builds use the same core architecture.

<div class="spec-grid">
  <section class="spec-card"><span class="spec-card__label">Control</span><h3>FullVision-STM32 V1.5</h3><p>Seven analog inputs, OLED display, and onboard buttons for navigation and configuration.</p></section>
  <section class="spec-card"><span class="spec-card__label">Motor drive</span><h3>Dual 40 A driver system</h3><p>Dual motor drivers operating with a 20 kHz PWM control frequency.</p></section>
  <section class="spec-card"><span class="spec-card__label">Power</span><h3>High-drain 2,500 mAh pack</h3><p>XT30 power connection with a loop-key safety system. The standard 1 kg Basic and Advanced configurations use 2S.</p></section>
  <section class="spec-card"><span class="spec-card__label">Sensing</span><h3>Enemy and line detection</h3><p>Sharp 10–80 cm enemy-detection sensors and two QRE1113 line sensors.</p></section>
  <section class="spec-card"><span class="spec-card__label">Traction</span><h3>Soft silicone wheels</h3><p>10 mm thick, Shore A 10 silicone tread for high grip, mounted on anti-slip locking wheel hubs.</p></section>
  <section class="spec-card"><span class="spec-card__label">Connectivity</span><h3>Bluetooth and RC ready</h3><p>Modified Bluetooth application support with compatibility for an RC receiver conversion.</p></section>
  <section class="spec-card"><span class="spec-card__label">Chassis</span><h3>Adjustable ABS frame</h3><p>Impact-resistant ABS construction with adjustable weight distribution.</p></section>
  <section class="spec-card"><span class="spec-card__label">Motors</span><h3>Serviceable high-RPM drive</h3><p>Modified high-RPM carbon-brush DC motors with replaceable or swappable gearboxes.</p></section>
</div>

## Upgrade a Basic unit to Advanced

You do not need to replace the entire robot. The upgrade can be completed gradually as your competition requirements and budget change.

1. **Expand enemy detection:** add the two side enemy sensors to move from a 3-sensor to a 5-sensor system.
2. **Upgrade the drivetrain:** change from the 700–800 RPM anti-slip gearboxes to the 900–1,000 RPM Advanced drivetrain specification.
3. **Add the stainless blade:** retain the 0.2 mm spring-steel blade and add the 2 mm stainless-steel blade supplied with the Advanced configuration.
4. **Load the matching firmware configuration:** move from the four-mode Basic setup to the seven-mode Advanced setup after the required sensors and drivetrain have been installed.
5. **Recalibrate and test:** recalibrate the line and enemy sensors, then perform a raised-wheel motor test before arena use.

<div class="warning note"><strong>Match firmware to hardware.</strong> Do not enable a five-sensor or Advanced configuration before the corresponding sensors and hardware are installed and tested.</div>

## Convert an Advanced unit for the 3 kg category

The 3 kg upgrade changes the structure and drivetrain for heavyweight competition use.

| 3 kg conversion component | Purpose |
|---|---|
| Stainless-steel front, bottom, and inner plates | Adds mass, stiffness, and impact protection |
| Long-shaft double-spur gearboxes, 700–900 RPM | Supports the wider 3 kg drivetrain arrangement |
| 40 mm wide × 10 mm thick silicone wheels | Provides a wider contact patch for the heavier build |
| 3 mm stainless blade with 0.15 mm edge | Heavyweight front blade |
| 0.3 mm spring-steel blade | Flexible blade option for the 3 kg configuration |
| Conversion toolset | Supports installation and category changes |

### Return to a 1 kg category

The conversion is designed to be reversible when the original components are retained.

1. Remove the 3 kg steel plates, long-shaft gearbox set, wide wheels, and heavyweight blade hardware.
2. Reinstall the original 1 kg chassis parts, gearboxes, 30 mm wheels, blade, and weight arrangement.
3. Select the correct 1KG firmware values before testing.
4. Recalibrate the sensors and confirm motor direction.
5. Weigh the complete robot with its competition attachment and battery installed. Always follow the organizer's current category and safety rules.

<div class="know-fact know-fact--success"><span class="know-fact__label">One robot, multiple categories</span><p>An Advanced Mini Hunter can compete as a 3 kg build and later return to a 1 kg configuration. Store every removed part, screw, spacer, and original gearbox together so the conversion can be reversed safely.</p></div>

## Other upgrades and accessories

- **Robohockey Attachment V2:** approved custom attachment for compatible hockey games.
- **Joystick RC controller:** HOTRC joystick transmitter option with battery set.
- **Extra front plates:** separate Auto and RC front plates for the 1 kg category.
- **Protective cases:** hard-case options with fitted storage for the robot, controller, tools, chargers, and blades.
- **Battery packs:** replacement 2S packs and configuration-specific 3S packs.
- **Wheel parts:** standard Shore A 15 tires, extra-grip Shore A 10 tires, replacement hubs, and complete wheel assemblies.
- **Gearboxes:** replacement 1:35 and 1:45 modified anti-slip gearboxes.

<div class="warning note"><strong>Battery compatibility matters.</strong> A 3S battery listed as an available spare is not automatically compatible with every Mini Hunter configuration. Use only the battery, motors, controller settings, and wiring specified for your installed build. Never install a higher-voltage pack simply to increase speed.</div>

Specifications are based on the Mini Hunter V2.7 2026 brochure. Parts, bundles, and availability can vary by production batch; confirm current upgrade compatibility with Twentynine Robotics before ordering.

[Return to Mini Hunter guides](./)
