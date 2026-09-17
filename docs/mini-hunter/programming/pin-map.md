---
layout: default
title: FullVision STM32 pin map
description: Firmware-to-hardware pin mapping for the FullVision STM32 board used by Mini Hunter.
---

# FullVision STM32 pin map

<span class="status-chip ready">Code-checked reference</span>

This page maps the names used by the Mini Hunter firmware to STM32F103C8 pins and their jobs on the FullVision STM32 board. It was checked against the supplied `FullVision-STM32.h` and `FullVision-STM32.cpp` files.

<div class="warning note"><strong>Do not rewire from this table alone.</strong> This is a firmware reference, not a connector-orientation diagram. Turn off the robot and use the board labels or an approved wiring guide before moving a physical cable.</div>

## Drive motors

| Firmware name | STM32 pin | Board use | Signal |
|---|---|---|---|
| `M1_IN1` | PB6 | Left motor driver, direction/PWM input 1 | Output / PWM |
| `M1_IN2` | PB7 | Left motor driver, direction/PWM input 2 | Output / PWM |
| `M1_IN3` | PB3 | Left motor driver auxiliary input | Output |
| `M2_IN1` | PB9 | Right motor driver, direction/PWM input 1 | Output / PWM |
| `M2_IN2` | PB8 | Right motor driver, direction/PWM input 2 | Output / PWM |
| `M2_IN3` | PB4 | Right motor driver auxiliary input | Output |

The movement helpers write PWM to the IN1 and IN2 pairs. The supplied initialization sets all six motor pins as outputs and uses an 8 kHz PWM frequency.

## Board switches

| Firmware name | STM32 pin | Board label | Signal |
|---|---|---|---|
| `MODE` | PB12 | MODE latching switch | Input with pull-up |
| `SW1` | PB13 | SW1 momentary switch | Input with pull-up |
| `SW2` | PB14 | SW2 momentary switch | Input with pull-up |

Because these inputs use pull-ups, a pressed/active switch is commonly read as `LOW` in the supplied code.

## Line sensors and adjustment potentiometers

| Firmware name | STM32 pin | Board use | Signal |
|---|---|---|---|
| `POTLINE1` | PB0 | Left line-sensor threshold potentiometer | Analog input |
| `LINE1_PIN` | PA6 | Left line sensor | Analog input |
| `POTLINE2` | PB1 | Right line-sensor threshold potentiometer | Analog input |
| `LINE2_PIN` | PA5 | Right line sensor | Analog input |

`lineDetection()` compares each line-sensor reading with its matching potentiometer. It then updates the `LINE1` and `LINE2` true/false variables.

## Enemy-detection sensors

| Firmware name | STM32 pin | Sensor direction | Used by |
|---|---|---|---|
| `LEFT_PIN` | PA0 | Left | 5-system build |
| `FLEFT_PIN` | PA1 | Front-left | 3- and 5-system builds |
| `FRONT_PIN` | PA2 | Front | 3- and 5-system builds |
| `FRIGHT_PIN` | PA3 | Front-right | 3- and 5-system builds |
| `RIGHT_PIN` | PA4 | Right | 5-system build |

The current distance conversion is written for the Sharp GP2Y0A21 sensor and clamps displayed results to approximately 10–80 cm.

## Bluetooth and RC receiver — shared pins

| Firmware name | STM32 pin | Bluetooth use | RC use |
|---|---|---|---|
| `BT_TX` | PA8 | Software serial transmit | Receiver pulse input handled by an interrupt |
| `BT_RX` | PB15 | Software serial receive | Receiver pulse input handled by an interrupt |

<div class="warning note"><strong>Shared connection:</strong> Bluetooth and RC input use PA8 and PB15. The firmware ends Bluetooth serial before calling <code>setupInterrupts()</code> for RC Mode. Do not run both input methods on these pins at the same time.</div>

The RC Cable V1 guide identifies the receiver-side CH1/CH3 arrangement. The variable names `ch1_pulse` and `ch2_pulse` inside the library describe the two captured pulse streams; do not assume those internal names are the printed channel labels on every receiver cable.

## OLED display

| Connection | STM32 pin | Firmware object |
|---|---|---|
| I²C2 SCL | PB10 | `Wire2` clock |
| I²C2 SDA | PB11 | `Wire2` data |

The supplied firmware uses a 128 × 32 SSD1306 OLED at I²C address `0x3C` and rotates the display by 180 degrees with `display.setRotation(2)`.

## Servo and serial service pins

| Firmware name/use | STM32 pin | Purpose |
|---|---|---|
| `SERVO` | PA7 | Flag servo signal |
| Serial1 TX | PA9 | Serial debugging and serial upload connection |
| Serial1 RX | PA10 | Serial debugging and serial upload connection |

The sketch starts `Serial1` at 115200 baud. The flag servo is attached to PA7 during `fullVisionInit()`.

## Pin map in code

The pin aliases are defined near the top of `FullVision-STM32.h`. Use the alias in normal code:

```cpp
float frontDistance = readDistance(FRONT_PIN);
```

Avoid placing raw pin names throughout a custom mode:

```cpp
// Harder to understand and maintain
float frontDistance = readDistance(PA2);
```

Using `FRONT_PIN` makes the purpose clear and keeps future board changes in one mapping file.
