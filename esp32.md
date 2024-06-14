[Back to main](./README.md)

<hr>

# Synth Projects on ESP32

## Arduino IDE

Due to good support and plenty of examples and tutorials, it is a good idea to use the Arduino Integrated Design Environment for people with little experience in microcontroller developments. There are two common misconceptions among beginners:

1. *The Arduino IDE can only be used for Arduino Hardware like the classic Arduino Uno, the Arduino Nano etc.* The Arduino people themselves and companies like Espressif (for a.o. their ESP-32 products) offer support for various uC families and lots of boards. Sometimes this requires installing additional libraries which is rather easy in Arduino IDE.

2. *Arduino is a special programming language.* No, it's C++. However, the IDE implements some shortcuts to make life easier for beginners:

    - automatically insert `include <some_library.h>`for detected libraries
    - automatically insert forward declaration for functions
    - add alternative names for some types (e.g. `boolean` instead of `bool` and `byte` instead of `unsigned char`)
    - add some functions / abstraction for easier interfacing of hardware
    - provide the `setup()` and `loop()` function structure for better understanding / clearer structure for beginners. It is not required to use this, both functions are thrown into `main()` (which *is* required but hidden before the eyes of the user) before compilation.

Even for experienced programmers it can make sense to install the Arduino IDE due to its excellent and simple to use library and board manager and the integrated port manager. And you can always use plain C/C++ in the Arduino IDE, you don't have to use the special features. You can write code in another editor / IDE (set IDE preferences to "External Editor", TODO: where?) and just use the Arduino IDE for compiling and / or file upload.

If you enable "verbose output" under `File -> Preferences` you can watch some of the Arduino magic going on.

You need to install the Arduino IDE and the ESP32 Board Support Package (described e.g. by [Random Nerd Tutorials (RNT)](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)). RNT has great tutorials and material for Arduino and ESP-32, highly recommended!
### Libraries
Libraries are installed in three different locations: In the Sketchbook folder (`File -> Preferences -> Sketchbook location`), in the user folder (e.g. `Documents\Arduino\libraries` under Windows) or in the installation folder for system libraries (requiring elevated rights).

The easiest way to install new libraries directly from the internet is via the Library Manager in the left sidebar. Downloaded zipped libraries can be installed via `Sketch -> Include Library -> Add .ZIP Library` or installed manually as described e.g. [here](https://learn.sparkfun.com/tutorials/installing-an-arduino-library/all) or [here](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries/).

### Arduino ESP32 by Espressif

Espressif provides integration of ESP32 cores and boards into the Arduino IDE with their [Arduino ESP32](https://docs.espressif.com/projects/arduino-esp32/) project. Several [libraries](https://docs.espressif.com/projects/arduino-esp32/en/latest/libraries.html) add functionality for peripherals:

- [I2S](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/i2s.html)
- [ADC](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/adc.html)

As the [Audio Development Framework ADF](https://github.com/espressif/esp-adf) by Espressif is a bit overwhelming for many applications, some libraries have been developed by independent developers:

## Hackerbox Audio DSP

> Welcome to HackerBox 0079. Let's explore audio signal generation, inter-IC sound (I2S) audio streams, and digital signal processing (DSP). Configure an ESP32-A1S Audio Development Kit featuring a dual-core ESP32 microcontroller coupled to an integrated audio CODEC and a variety of audio interface and peripheral components. Program several audio processing examples leveraging an advanced stream-based hardware abstraction layer for the ESP32-A1S. Examples include wave generators, simple synthesizers, MP3 decoders for online stream sources as well as MP3 files on SD flash cards. Use GNU Octave (or MATLAB) to design and test digital FIR filters that can be implemented on the ESP32 Audio Development Kit. Hack multi-channel audio connectors:

https://www.instructables.com/HackerBox-0079-Audio-DSP/ is a really nice first introduction into DSP on the ESP32, building upon the libraries of Phil Schatzmann (see below).

## Phil Schatzmann

Phil has created the two libraries arduino-audio-driver and arduino-audio-tools that make it so much easier to do audio and DSP programming for ESP32 (and other microcontrollers) with the Arduino IDE. His videos and other repos are also worth checking out.

### Arduino Audio Driver

The [arduino-audio-driver](https://github.com/pschatzmann/arduino-audio-driver) library provides an easy API to configure different audio codec chips via I2C for streaming audio via I2S. Supported codecs are a.o. AC101, ES8388, ES8311, CS43L22 and ES7243.

The library can be downloaded and installed as a ZIP file including examples. Some of the examples require Arduino Audio Tools.

### Arduino Audio Tools

The [arduino-audio-tools](https://github.com/pschatzmann/arduino-audio-tools) library mainly provides different audio sources and sinks (i.e. streams), including sound generators, encoders and decoders, real-time FFT and logging:

- **I2S** (Inter-IC Sound), a synchronous serial standard for transmitting audio signals that is widely used by many ADCs and DACs, digital microphones or audio DSPs. 
- **A2DP** (Advanced Audio Distribution Profile), a Bluetooth profile and technique for transmitting stereo audio streams. This profile is supported by most platforms and operating systems, different codecs can be specified.
- **RTSP** (Real-Time Streaming Protocol) for *controlling* the streaming of audio-visual data via IP-based networks. The actual data is usually transmitted using the Real-Time Transport Protocol (RTP).

The library brings plenty of examples organized in subfolders:

- *examples-audiokit* for the deprecated audiokit library
- *examples-basic-api* with some basic stuff to demonstrate the API
- *examples-communication* for streaming with various network protocols (A2DP, HTTP, SPI, ...)
- *examples-dsp* for various DSP audio synthesis libraries like [Maximilian](https://github.com/micknoise/Maximilian), [Faust](./faust.md), [Mozzi](https://sensorium.github.io/Mozzi/), [PureData](https://puredata.info/) and [SythesisToolKit](https://ccrma.stanford.edu/software/stk/) (STK) from CCRMA Stanford.
- *examples-player* demonstrates the audioplayer streaming from SD-card, URLs etc. to I2S, A2DP, FFT or analog
- *examples-stream* connects streams, e.g. for format conversion
- *examples-tts* provides text-to-speech using different platforms
- *examples-vs1053* shows how to interface to the [VS1053 SOC](https://cdn-shop.adafruit.com/datasheets/vs1053.pdf), a chip supporting mp3, FLAC, OGG and other audio coding formats.

### Arduino Audiokit Library

This [library](./esp32_audiokit.md) is deprecated, [arduino-audio-driver](https://github.com/pschatzmann/arduino-audio-driver) (see above) should be used instead for new projects.

## Marcel License

Marcel License's repo at https://github.com/marcel-licence has a lot of great music projects built around ESP-32:

### Little startup guide for ESP32 Arduino DIY MIDI Synthesizer Projects

A great [Youtube](https://youtu.be/ZNxGCB-d68g) video to get started with Arduino IDE and git and Marcel's audio projects.

### ESP32 based DIY polyphonic MIDI synthesizer module

The project is published on [Github](https://github.com/marcel-licence/esp32_basic_synth) and demonstrated on [Youtube](https://youtu.be/5XVK5MOKmZw). It has been tested on the ESP32 Audio Kit v2.2 (see above) and on the widely used ESP32 DEVKIT - DOIT. 

The project also uses the following software by the same author:

### USB MIDI for the ESP32

For more information refer to the MIDI related project: [esp32_usb_midi](https://github.com/marcel-licence/esp32_usb_midi). Using USB MIDI can be seen in the video [Mini USB host shield with ESP32 as MIDI interface](https://youtu.be/Mt3rT-SVZww).

## NA5Y

- Using the ESP32 A1S with the Expressif ADF
- [ESP32 A1S with Arduino Audio Tools](https://youtu.be/oqtkR2FRKYI): Various examples for streaming audio (generated, I2S, HTTP, Bluetooth) with the ESP32 A1S using the Arduino IDE.
- [Repo](https://github.com/thaaraak/es8388) with code for controlling the ES8388 codec

## TBD Module

An open-source soft- and hardware Eurorack module based on ESP32 module by [Robert Manzke](https://github.com/ctag-fh-kiel) of University Kiel with lots of code for various audio modules, including a collection of various digital implementations of the Moog VCF.

## Synthux

Although the Synthux modules are built around Daisy Seed (STM32) microcontrollers, the open source code is interesting to look at under https://github.com/Synthux-Academy. For uploading files to the Daisy Seed, the [STM32CubeProg](https://www.st.com/en/development-tools/stm32cubeprog.html) needs to be installed to get the required drivers. This is described [here](https://github.com/electro-smith/DaisyWiki/wiki/1a.-Getting-Started-(Arduino-Edition)) and in detail [here](https://github.com/stm32duino/Arduino_Core_STM32/wiki/Getting-Started) ("Extra Step"). With the drivers installed, binaries can be installed on the Daisy Seed directly by using the [Daisy Web Programmer](https://electro-smith.github.io/Programmer/) (Chrome or Edge only, unfortunately). The platform "seed" has to be selected.

## Hardware

### ESP32 Audio Kit

The [ESP32 Audio Kit v2.2 A247](https://docs.ai-thinker.com/en/esp32-audio-kit) board is available for ca. 15 € at [Aliexpress](https://de.aliexpress.com/i/33003284057.html) and contains an audio codec as well as a stereo power amplifier - see [Details](./esp32_a1s.md).

<hr>

[Back to main](./README.md)