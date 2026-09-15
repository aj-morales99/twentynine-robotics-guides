---
layout: default
title: FullVision code library
description: Searchable beginner reference for FullVision STM32 functions used by Mini Hunter firmware.
permalink: /mini-hunter/code-library/
---

# FullVision code library

Search by a function name or a word such as `motor`, `sensor`, `display`, `RC`, or `interrupt`. This reference describes the public functions found in the supplied `FullVision-STM32.h`; always check the library version bundled with the firmware you are editing.

<div class="function-search">
  <label for="function-search">Find a function</label>
  <input id="function-search" type="search" placeholder="Example: motorSTOP or sensor" autocomplete="off">
  <p id="function-count" aria-live="polite"></p>
</div>

## Start here

<div class="do-dont">
  <div><h3>Do</h3><ul><li>Call <code>fullVisionInit()</code> once from <code>setup()</code>.</li><li>Stop motors before waiting or changing control mode.</li><li>Refresh sensor values before making a decision.</li><li>Keep speeds within the tested 0–100 range.</li></ul></div>
  <div><h3>Don't</h3><ul><li>Do not call interrupt handlers yourself.</li><li>Do not run Bluetooth serial and RC pulse interrupts on the same shared pins at once.</li><li>Do not edit the installed library without recording the version and change.</li><li>Do not test new movement code with the blade or wheels touching a surface.</li></ul></div>
</div>

<div class="function-list">
  <section class="function-card"><h3><code>fullVisionInit()</code></h3><p class="function-meta">Setup · call once</p><p>Initializes the FullVision board hardware used by the library. Put it in Arduino's <code>setup()</code> before sensor, display, or movement work.</p><pre><code>void setup() {
  fullVisionInit();
}</code></pre><p><strong>Do:</strong> call it once. <strong>Don't:</strong> call it repeatedly inside <code>loop()</code>.</p></section>
  <section class="function-card"><h3><code>textDisplay(text1, size1, text2, size2, text3, size3)</code></h3><p class="function-meta">OLED display · lines 2 and 3 are optional</p><p>Centers up to three text lines on the robot's 128 × 32 OLED. Every supplied line has a text-size value.</p><pre><code>textDisplay("READY", 2);
textDisplay("MODE 1", 2, "PRESS SW2", 1);</code></pre><p><strong>Do:</strong> keep messages brief. <strong>Don't:</strong> update continuously when the text has not changed.</p></section>
  <section class="function-card"><h3><code>readDistance(pin)</code></h3><p class="function-meta">Enemy sensor · distance</p><p>Reads one supported analog distance sensor and returns a distance value used by the firmware. Current behavior is clamped to roughly 10–80 cm.</p><pre><code>int frontCm = readDistance(FRONT);</code></pre><p><strong>Do:</strong> compare readings using the same target and conditions. <strong>Don't:</strong> treat it as precision measurement outside its tested range.</p></section>
  <section class="function-card"><h3><code>readLine(sensorPin)</code></h3><p class="function-meta">Line sensor · declared but incomplete in reviewed source</p><p>The supplied header declares a percentage-returning line-reading helper, but the matching reviewed <code>.cpp</code> does not define it. The current firmware refreshes line states through <code>lineDetection()</code>.</p><pre><code>lineDetection();
bool leftBoundary = LINE1;</code></pre><p><strong>Do:</strong> use the implemented path and test dark/light surfaces. <strong>Don't:</strong> call <code>readLine()</code> until its implementation is added and verified.</p></section>
  <section class="function-card"><h3><code>readChannel(pulseValue, minLimit, maxLimit, defaultValue)</code></h3><p class="function-meta">RC input · pulse mapping</p><p>Maps a captured receiver pulse to the requested output limits. The current implementation applies a neutral deadband and returns the default for invalid pulse widths.</p><pre><code>int steering = readChannel(ch1_pulse, -100, 100, 0);</code></pre><p><strong>Do:</strong> establish neutral before enabling movement. <strong>Don't:</strong> pass a channel number; pass the captured pulse value.</p></section>
  <section class="function-card"><h3><code>setupInterrupts()</code></h3><p class="function-meta">RC input · setup</p><p>Attaches the interrupt handlers used to measure RC receiver pulses on PA8 and PB15.</p><pre><code>Bluetooth.end();
setupInterrupts();</code></pre><p><strong>Do:</strong> stop Bluetooth use first. <strong>Don't:</strong> attach RC capture while Bluetooth is active on the same pins.</p></section>
  <section class="function-card"><h3><code>stopInterrupts()</code></h3><p class="function-meta">RC input · cleanup</p><p>Detaches the RC pulse interrupts and returns stored channel pulses to neutral.</p><pre><code>stopInterrupts();
motorSTOP();</code></pre><p><strong>Do:</strong> stop motors during a control-source change. <strong>Don't:</strong> assume detaching interrupts alone physically removes power.</p></section>
  <section class="function-card"><h3><code>modeDisplay(number)</code></h3><p class="function-meta">Menu and mode display</p><p>Updates the OLED information for the supplied menu number.</p><pre><code>modeDisplay(modeSelected);</code></pre><p><strong>Do:</strong> preserve its button and display expectations when customizing menus. <strong>Don't:</strong> confuse a displayed mode number with sensor-system count.</p></section>
  <section class="function-card"><h3><code>enemyDetection()</code></h3><p class="function-meta">Enemy sensors · refresh</p><p>Refreshes the enemy-sensor values used by the behavior code. The active sensor set depends on <code>SYSTEM</code>.</p><pre><code>enemyDetection();
// decide movement using refreshed values</code></pre><p><strong>Do:</strong> call it before a decision that needs current distances. <strong>Don't:</strong> configure five sensors on a robot that only has three.</p></section>
  <section class="function-card"><h3><code>lineDetection()</code></h3><p class="function-meta">Line sensors · refresh</p><p>Refreshes both boundary-sensor states for the behavior code.</p><pre><code>lineDetection();
// react to LINE1 and LINE2 states</code></pre><p><strong>Do:</strong> calibrate first. <strong>Don't:</strong> ignore boundary detection while increasing speed.</p></section>
  <section class="function-card"><h3><code>motorSTOP()</code></h3><p class="function-meta">Movement · stop</p><p>Commands both drive motors to stop.</p><pre><code>motorSTOP();</code></pre><p><strong>Do:</strong> use it before delays, menus, and fault handling. <strong>Don't:</strong> treat software stop as a substitute for disconnecting power during mechanical work.</p></section>
  <section class="function-card"><h3><code>motorFWD(speed)</code></h3><p class="function-meta">Movement · forward</p><p>Drives both motors forward at the requested speed.</p><pre><code>motorFWD(30);</code></pre><p><strong>Do:</strong> begin at a low tested value. <strong>Don't:</strong> exceed the expected 0–100 range.</p></section>
  <section class="function-card"><h3><code>motorREV(speed)</code></h3><p class="function-meta">Movement · reverse</p><p>Drives both motors in reverse at the requested speed.</p><pre><code>motorREV(30);</code></pre><p><strong>Do:</strong> check rear clearance. <strong>Don't:</strong> reverse blindly after a line event without timing limits.</p></section>
  <section class="function-card"><h3><code>motorSLEFT(speed)</code></h3><p class="function-meta">Movement · spin left</p><p>Commands an in-place left spin.</p><pre><code>motorSLEFT(25);</code></pre><p><strong>Do:</strong> test direction on a stand. <strong>Don't:</strong> assume motor wiring gives the expected direction after hardware changes.</p></section>
  <section class="function-card"><h3><code>motorSRIGHT(speed)</code></h3><p class="function-meta">Movement · spin right</p><p>Commands an in-place right spin.</p><pre><code>motorSRIGHT(25);</code></pre><p><strong>Do:</strong> test direction on a stand. <strong>Don't:</strong> start at full speed.</p></section>
  <section class="function-card"><h3><code>leftMotorControl(pwm1, pwm2)</code></h3><p class="function-meta">Movement · advanced</p><p>Controls the two direction inputs of the left motor directly. Each value is expected in the 0–100 range.</p><pre><code>leftMotorControl(forwardPower, reversePower);</code></pre><p><strong>Do:</strong> keep one direction at zero in normal use and copy a verified call pattern. <strong>Don't:</strong> drive both directions at once.</p></section>
  <section class="function-card"><h3><code>rightMotorControl(pwm1, pwm2)</code></h3><p class="function-meta">Movement · advanced</p><p>Controls the two direction inputs of the right motor directly. Each value is expected in the 0–100 range.</p><pre><code>rightMotorControl(forwardPower, reversePower);</code></pre><p><strong>Do:</strong> keep one direction at zero in normal use. <strong>Don't:</strong> change only one side without understanding the resulting turn.</p></section>
  <section class="function-card"><h3><code>servoFlag(value)</code></h3><p class="function-meta">Servo output</p><p>Moves the supported flag servo using the library's expected value.</p><pre><code>servoFlag(value);</code></pre><p><strong>Do:</strong> use values already verified for the mechanism. <strong>Don't:</strong> force the servo against a mechanical stop.</p></section>
  <section class="function-card"><h3><code>exitMode()</code></h3><p class="function-meta">Mode control</p><p>Handles the library's exit behavior for the active mode.</p><pre><code>exitMode();</code></pre><p><strong>Do:</strong> study the matching sketch's control flow before moving this call. <strong>Don't:</strong> remove a safe exit path from a custom mode.</p></section>
  <section class="function-card"><h3><code>handlePA8()</code> / <code>handlePB15()</code></h3><p class="function-meta">Internal interrupt handlers · do not call directly</p><p>Capture RC pulse edges on the pins shared with the Bluetooth serial connection. They are registered by <code>setupInterrupts()</code>.</p><p><strong>Do:</strong> leave them to the interrupt system. <strong>Don't:</strong> call them from <code>loop()</code> or add slow display, serial, or delay work inside them.</p></section>
</div>

## Next library-guide improvements

The next pass will add the exact parameter types, return values, shared global variables, pin map, and complete examples for each supported firmware version. It will also separate beginner functions from internal and advanced functions so users can modify code without accidentally entering timer or interrupt internals.

[Modes customization](../modes/customization.html) · [Back to Mini Hunter guides](../)
