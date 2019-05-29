# Arduino Sketches

A semi-regularly updated dump of my Arduino sketches with experiments, described wherever possible.

### may_29_epaper_154_experiment

First steps with driving an e-paper.

The code is basically the code from GxEPD examples https://github.com/ZinggJM/GxEPD/tree/master/examples/GxEPD_Example but stripped-down and modified with pinout for ESP32 based on Youtube video linked below.

Board: ESP32 Devkit, 2x15 pins.
E-paper module: Waveshare 1.54 B&W, aka GDEP015OC1.

Pin connections as in this Youtube video: https://www.youtube.com/watch?v=1xQqc6ZCXdw and described in article https://educ8s.tv/2-9-e-paper-display/ so basically:

* BUSY -> D4
* RST -> D21
* DC -> D22
* CS -> D5
* CLK -> D18
* DIN -> D23
* GND -> GND
* VCC -> 3V3

### bpw40_phototransistor_receive

First steps in using phototransistor for simple detection and measurement of moderately-fast (tens of miliseconds) light blinks.

Board: ESP8266 NodeMCU V1.0
Other hardware: BPW40 phototransistor, a set of resistors to use for sensitivity setting (between BPW's emitter and ground) from 1k to 10k Ohm.

Tested with Android app "Screen Flashlight" set to blink and put to BPW40.


