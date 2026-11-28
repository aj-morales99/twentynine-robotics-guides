---
layout: default
title: Mini Hunter calibration setup
description: Choose the Mini Hunter V2.8 Sinyas calibration guide or the original V2.7 OLED guides.
permalink: /mini-hunter/calibration/
---

<div class="calibration-overview">
  <h1>Calibrate your Mini Hunter</h1>
  <p class="calibration-lead">Check that your robot can tell the white boundary from the dark floor and read distances before you run it.</p>

  <aside class="calibration-safety" aria-label="Before you start">
    <strong>Before you start</strong>
    <p>Put the robot on a secure stand. Keep the blade and the wheels clear.</p>
  </aside>

  <section aria-labelledby="choose-your-guide">
    <h2 id="choose-your-guide">Choose your firmware guide</h2>
    <p>Use the version you last uploaded to your robot.</p>
    <nav class="calibration-jump" aria-label="Jump to a firmware version">
      <a href="#new-guide--v28">V2.8 · Sinyas</a>
      <a href="#v27-guides">V2.7 · OLED</a>
    </nav>

    <div class="calibration-paths">
      <section class="calibration-path calibration-path--sinyas" id="new-guide--v28" aria-labelledby="calibration-v28">
        <h3 id="calibration-v28">V2.8 <span>with Sinyas</span></h3>
        <figure>
          <a href="../../assets/images/sinyas/calibration-line.png"><img src="../../assets/images/sinyas/calibration-line.png" width="1170" height="520" alt="Sinyas Line Detection showing live readings and the Line profile menu"></a>
          <figcaption>On the robot, look for <a href="../../assets/images/mini-hunter/calibration/mh-cal-v28-sensor-menu.png">Sensor Check</a> in CAL Mode. On the phone, this is <strong>Line Detection</strong>.</figcaption>
        </figure>
        <p>Check live readings, tune line recovery and steering, and balance the wheels.</p>
        <a class="primary-action" href="sinyas-v2-8.html">Open the Sinyas calibration guide</a>
      </section>

      <section class="calibration-path" id="v27-guides" aria-labelledby="calibration-v27">
        <h3 id="calibration-v27">V2.7 <span>with the OLED</span></h3>
        <figure>
          <img src="../../assets/images/sinyas/oled/line-adjust.png" width="576" height="172" alt="Simulated V2.7 OLED showing Line Sensor Adjust">
          <figcaption>In CAL MODE, tap <strong>SW1</strong> for Line Sensor Adjust.</figcaption>
        </figure>
        <p>Use the board’s screen and buttons to check the sensors.</p>
        <div class="calibration-links">
          <a href="line-sensors.html">Adjust the line sensors</a>
          <a href="enemy-detection.html">Check the distance sensors</a>
        </div>
      </section>
    </div>
  </section>

  <section class="calibration-reference" aria-labelledby="firmware-help">
    <h2 id="firmware-help">Firmware and menu help</h2>
    <p><strong>Using Sinyas?</strong> Update Mini Hunter V2.7 or earlier to Sinyas-compatible V2.8 firmware first.</p>

    <details class="calibration-detail">
      <summary>Check your version or request an update</summary>
      <div class="calibration-detail__body">
        <p>If you’re unsure which firmware you have, check the sketch name from the last upload.</p>
        <p>To request the latest compatible firmware, email <a href="mailto:twentyninerobotics@gmail.com">twentyninerobotics@gmail.com</a> or message Twentynine Robotics on Facebook. Include your robot’s weight class and firmware version if you know them.</p>
      </div>
    </details>

    <details class="calibration-detail" id="enter-cal-mode">
      <summary>Enter CAL MODE on V2.7</summary>
      <div class="calibration-detail__body">
        <ol>
          <li>Power on the robot while it is on the stand.</li>
          <li>Set the <strong>MODE</strong> switch so the OLED shows <strong>RC/RMT</strong>.</li>
          <li>Hold <strong>SW1 + SW2</strong> for two seconds. Release them when <strong>CAL MODE</strong> appears.</li>
          <li>Tap <strong>SW1</strong> once for <strong>Line Sensor Adjust</strong> or twice for <strong>Enemy Detection Check</strong>.</li>
        </ol>
        <p>Hold <strong>SW1 + SW2</strong> again to exit calibration. Power off before taking the robot off the stand.</p>
      </div>
    </details>
  </section>
</div>
