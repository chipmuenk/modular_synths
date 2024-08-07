# Faust

> [Faust](https://faustdoc.grame.fr/) (Functional Audio Stream) is a functional programming language for sound synthesis and audio processing with a strong focus on the design of synthesizers, musical instruments, audio effects, etc. It is used in the academia and, of course, by musicians.

## Faust on Microcontrollers

Faust has also been implemented on low-cost uC platforms like ESP32 and Teensy.

It can be and is used as a base for hardware-oriented workshops:

* [Embedded DSP With Faust Workshop](https://ccrma.stanford.edu/workshops/faust-embedded-19/), Making Low Latency Guitar Pedals and Synthesizer Modules (Teensy based), CCRMA, Stanford University, 2019.
* [DSP on the ESP32 with Faust](https://faustdoc.grame.fr/tutorials/esp32/)
* [DSP on the Teensy with Faust](https://faustdoc.grame.fr/tutorials/teensy/)
* [A Faust Architecture for the ESP32 Microcontroller](https://hal.science/hal-02988312), 2020.

## First project

As a "Hello World" I tried to implement the Faust ESP32 example on https://faustdoc.grame.fr/tutorials/esp32/. 

### Using VSCode

I used VSCode as a code editor with the [Microsoft C/C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) (which also installs CMake Tools) and the [Espressif IDF Extension](https://marketplace.visualstudio.com/items?itemName=espressif.esp-idf-extension).

In Visual Studio Code, selecting menu "View" and "Command Palette" and typing [ESP-IDF: Configure ESP-IDF extension] installs the ESP-IDF and various prerequisites like idf-git and a suitable python version (which takes some time). I selected ESP-IDF version 4.3.6 and the suggested directories for the ESP-IDF container `C:\Users\Christian\esp\esp-idf` and the ESP-IDF Tools (IDF_TOOLS_PATH) `C:\Users\Christian\.espressif`. I copied the `esp\esp-idf\examples` folder to my working directory. This is also described in https://www.heise.de/ratgeber/Visual-Studio-Code-Installation-und-Konfiguration-fuer-ESP-IDF-6656091.html

When installation is completed, there is a new toolbar at the bottom of the VSCode window. 

As the Faust tutorial describes the older version of the board, some details need to be changed as described by [pschatzmann](https://www.pschatzmann.ch/home/2021/12/06/the-ai-thinker-audio-kit-experience-or-nothing-is-right/)
and in [ESP32 Audio Kit Grundlagen](https://radio-bastler.de/forum/showthread.php?tid=17786) (German). The differences between the AC101 and the ES8388 version are described in more detail in https://www.docdroid.net/L6LX9SK/esp32-a1s-esv23zh-cnen-pdf and in https://github.com/marcel-licence/esp32_midi_sampler/discussions/50 .

Although not mentioned in the tutorial, the ES8388 Codec is supported by `faust2esp32`.

### Arduino Design Flow

In the board manager, install esp32
