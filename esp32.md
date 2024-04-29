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

## Hackerbox Audio DSP

> Welcome to HackerBox 0079. Let's explore audio signal generation, inter-IC sound (I2S) audio streams, and digital signal processing (DSP). Configure an ESP32-A1S Audio Development Kit featuring a dual-core ESP32 microcontroller coupled to an integrated audio CODEC and a variety of audio interface and peripheral components. Program several audio processing examples leveraging an advanced stream-based hardware abstraction layer for the ESP32-A1S. Examples include wave generators, simple synthesizers, MP3 decoders for online stream sources as well as MP3 files on SD flash cards. Use GNU Octave (or MATLAB) to design and test digital FIR filters that can be implemented on the ESP32 Audio Development Kit. Hack multi-channel audio connectors:

https://www.instructables.com/HackerBox-0079-Audio-DSP/ is a really nice first introduction into DSP on the ESP32, building upon the libraries of Phil Schatzmann (see below).

In general, I'm really impressed by the quality of audio and DSP libraries, repos and videos of Phil Schatzmann and Marcel License for the ESP32:

## Phil Schatzmann

https://www.pschatzmann.ch/home/2020/05/22/synthesizer-for-the-esp32/

### Arduino Audio Driver

the goal of the [arduino-audio-driver](https://github.com/pschatzmann/arduino-audio-driver) library is to provide an easy API to configure different audio codec chips via I2C to be able to stream audio via I2S. Supported codecs are a.o. AC101, ES8388, ES8311,CS43l22 and ES7243.

The library can be downloaded and installed as a ZIP file, it brings some examples for easy testing. Some of the examples require Arduino Audio Tools.

### Arduino Audio Tools

This [library](https://github.com/pschatzmann/arduino-audio-tools) mainly provides different audio sources and sinks, including sound generators, encoders and decoders, real-time FFT and logging. Sources and sinks are different kind of "streams":

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

This [library](./esp32_audiokit.md) is deprecated and should be replaced by [arduino-audio-driver](https://github.com/pschatzmann/arduino-audio-driver) (see above) for new projects. However, it is still widely used. 

## Marcel License

Marcel License's repo at https://github.com/marcel-licence has a lot of great music projects built around ESP-32:

### Little startup guide for ESP32 Arduino DIY MIDI Synthesizer Projects

A great [Youtube](https://youtu.be/ZNxGCB-d68g) video to get started with Arduino IDE and git and Marcel's audio projects.

### ESP32 based DIY polyphonic MIDI synthesizer module

The project is published on [Github](https://github.com/marcel-licence/esp32_basic_synth) and demonstrated on [Youtube](https://youtu.be/5XVK5MOKmZw). It has been tested on the ESP32 Audio Kit v2.2 (see above) and on the widely used ESP32 DEVKIT - DOIT. 

The project also uses the following software by the same author:

### USB MIDI for the ESP32

For more information refer to the MIDI related project: [esp32_usb_midi](https://github.com/marcel-licence/esp32_usb_midi). Using USB MIDI can be seen in the video [Mini USB host shield with ESP32 as MIDI interface](https://youtu.be/Mt3rT-SVZww).

## Hardware

### ESP32 Audio Kit

The [ESP32 Audio Kit v2.2 A247](https://docs.ai-thinker.com/en/esp32-audio-kit) board, available for ca. 15 € at [Aliexpress](https://de.aliexpress.com/i/33003284057.html), ticked all the right boxes for me: A powerful and widely used processor, audio codec included and lots of audio interfaces. The board is built around the [ESP32-A1S Audio break-out board](https://docs.ai-thinker.com/en/esp32-a1s) which also can/could be bought stand-alone.
The break-out board contains an ESP32-WROVER module, that is an ESP32-D0WDQ6-V3 chip with external 4 MB SPI Flash and 8 MB PSRAM. The "A1S" suffix relates to the CODEC that is cconnected via I2S. My version contains an ES8388 chip replacing the AC101 CODEC in older versions.

Besides the ESP32-A1S break-out board, the Audio Kit board encompasses:

- CP2102 USB2UART bridge
- 2 onboard microphones
- stereo headphone output, stereo line-in input
- 2 NS4150 Class D audio amplifiers for two speaker outputs (3W, 4 &Omega;)
- 6 general purpose push buttons

In the Arduino IDE, the board can be selected as Tools -> Board Manager -> esp32 -> ESP32 Dev Module

<hr>

[Back to main](./README.md)