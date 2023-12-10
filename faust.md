# Faust

> [Faust](https://faustdoc.grame.fr/) (Functional Audio Stream) is a functional programming language for sound synthesis and audio processing with a strong focus on the design of synthesizers, musical instruments, audio effects, etc. It is used in the academia and, of course, by musicians.

Faust has also been implemented on low-cost uC platforms like ESP32 and Teensy.

It can be and is used as a base for hardware-oriented workshops:
* https://ccrma.stanford.edu/workshops/faust-embedded-19/
* https://faustdoc.grame.fr/tutorials/esp32/
* https://hal.science/hal-02988312

## Hardware

The [ESP32 Audio Kit v2.2 A247](https://docs.ai-thinker.com/en/esp32-audio-kit) board, available for ca. 15 € at [Aliexpress](https://de.aliexpress.com/i/33003284057.html), ticked all the right boxes for me: A powerful and wide-spread processor, audio codec included and lots of audio interfaces. The board is built around the [ESP32-A1S Audio break-out board](https://docs.ai-thinker.com/en/esp32-a1s) which also can be bought stand-alone for 
This module contains an ESP32-WROVER PCB, an ESP32-D0WDQ6-V3 chip with external 4 MB SPI Flash and 8 MB PSRAM. The "A1S" suffix hints at an CODEC that is cconnected via I2S. My version contains an ES8388 chip that replaces the AC101 CODEC in older version.

- CP2102 USB2UART bridge
- 2 onboard microphones
- 2 NS4150 Class D audio amplifiers
- 6 general purpose push buttons

## First project
As a "Hello World" I tried to implement the Faust ESP32 example on https://faustdoc.grame.fr/tutorials/esp32/. 

I used VSCode as a code editor with the [Microsoft C/C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) (which also installs CMake Tools) and the [Espressif IDF Extension](https://marketplace.visualstudio.com/items?itemName=espressif.esp-idf-extension) and 

As the Faust tutorial describes the older version of the board, some details need to be changed as described by [pschatzmann](https://www.pschatzmann.ch/home/2021/12/06/the-ai-thinker-audio-kit-experience-or-nothing-is-right/)
and in [ESP32 Audio Kit Grundlagen](https://radio-bastler.de/forum/showthread.php?tid=17786) (German). The differences between the AC101 and the ES8388 version are described in more detail in https://www.docdroid.net/L6LX9SK/esp32-a1s-esv23zh-cnen-pdf and in https://github.com/marcel-licence/esp32_midi_sampler/discussions/50 .
