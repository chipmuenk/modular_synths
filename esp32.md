# Synth Projects on ESP32

## Arduino IDE

Due to good support and plenty of examples and tutorials, it is a good idea to use the Arduino Integrated Design Environment for people with little experience in microcontroller developments. There are two common misconceptions among beginners:

1. "The Arduino IDE can only be used for Arduino Hardware like the classic Arduino Uno, the Arduino Nano etc." The Arduino people themselves and companies like Espressif (for a.o. their ESP-32 products) offer support for various uC families and lots of boards. Sometimes this requires installing additional libraries which is rather easy in Arduino IDE.

2. "Arduino is a special programming language." No, it's C++. However, the IDE implements some shortcuts to make life easier for beginners:

    - automatically insert `include <some_library.h>`for detected libraries
    - automatically insert forward declaration for functions
    - add alternative names for some types (e.g. `boolean` instead of `bool` and `byte` instead of `unsigned char`)
    - add some functions / abstraction for easier interfacing of hardware
    - provide the `setup()` and `loop()` function structure for better understanding / clearer structure for beginners. It is not required to use this, both functions are thrown into `main()` (which *is* required but hidden before the eyes of the user) before compilation.

Even for experienced programmers it can make sense to install the Arduino IDE due to its excellent and simple to use library and board manager and the integrated port manager. And you can always use plain C/C++ in the Arduino IDE, you don't have to use the special features. You can write code in another editor / IDE (set IDE preferences to "External Editor", TODO: where?) and just use the Arduino IDE for compiling and / or file upload.

If you enable "verbose output" under `File -> Preferences` you can watch some of the Arduino magic going on.

 You need to install the Arduino IDE and the ESP32 Board Support Package (described e.g. by [Random Nerd Tutorials](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)).

Phil Schatzmann has developed the [Arduino Audiokit](https://github.com/pschatzmann/arduino-audiokit) as a replacement for the Espressiv ADF which cannot be used with the Arduino IDE. 
> There are different ESP32 Audio boards available that can be programmed with the Espressif ADF Framework. The ADF Framework contains an abstraction layer to support different codec audio chips (ES8388, ES8311, AC101...) which need to be configured usually via I2C.

This library has been archived and should be replaced by [arduino-audio-driver](https://github.com/pschatzmann/arduino-audio-driver) for new projects. 

The libraries can be downloaded as zip archives via `Sketch -> Include Library -> Add .ZIP Library` or installed manually as described e.g. [here](https://learn.sparkfun.com/tutorials/installing-an-arduino-library/all) or [here](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries/).

Libraries are installed in three different locations: In the Sketchbook folder (File -> Preferences -> Sketchbook location), in the user folder (e.g. Documents\Arduino\libraries under Windows) or in the installation folder (requiring elevated rights).

### Audiokit Library

In the freshly installed audiokit library, board and codec need to be selected in

    libraries/audiokit/src/AudioKitSettings.h

requiring for the ESP32 Audio Kit v2.2 

    #define AUDIOKIT_BOARD 5

Additionally, the following setting should be present to enable the headphone socket

    #define AI_THINKER_ES8388_VOLUME_HACK 1

After the installation (and maybe a restart), you should see new examples under

File -> Examples -> audiokit

The example 'output' generates a 1000 Hz sinusoidal tone, the example 'input' reads L and R channel of audio and plots them on the serial plotter.

The example `input` monitors the line input on the serial plotter. In order to use the onboard microphones instead, change

    cfg.adc_input = AUDIO_HAL_ADC_INPUT_LINE1;

to

    cfg.adc_input = AUDIO_HAL_ADC_INPUT_LINE2;

(This made no difference for me, the signal was just a few LSBs of noise in both cases.)

and open `Tools -> Serial Plotter` and set the baud rate to 115200.

## ESP32 Audio Kit

The [ESP32 Audio Kit v2.2 A247](https://docs.ai-thinker.com/en/esp32-audio-kit) board, available for ca. 15 € at [Aliexpress](https://de.aliexpress.com/i/33003284057.html), ticked all the right boxes for me: A powerful and widely used processor, audio codec included and lots of audio interfaces. The board is built around the [ESP32-A1S Audio break-out board](https://docs.ai-thinker.com/en/esp32-a1s) which also can/could be bought stand-alone.
The break-out board contains an ESP32-WROVER module, that is an ESP32-D0WDQ6-V3 chip with external 4 MB SPI Flash and 8 MB PSRAM. The "A1S" suffix relates to the CODEC that is cconnected via I2S. My version contains an ES8388 chip replacing the AC101 CODEC in older versions.

Besides the ESP32-A1S break-out board, the Audio Kit encompasses:

- CP2102 USB2UART bridge
- 2 onboard microphones
- stereo headphone output, stereo line-in input
- 2 NS4150 Class D audio amplifiers for two speaker outputs (3W, 4 &Omega;)
- 6 general purpose push buttons

In the Arduino IDE, the board can be selected as Tools -> Board Manager -> esp32 -> ESP32 Dev Module

## Hackerbox Audio DSP

> Welcome to HackerBox 0079. Let's explore audio signal generation, inter-IC sound (I2S) audio streams, and digital signal processing (DSP). Configure an ESP32-A1S Audio Development Kit featuring a dual-core ESP32 microcontroller coupled to an integrated audio CODEC and a variety of audio interface and peripheral components. Program several audio processing examples leveraging an advanced stream-based hardware abstraction layer for the ESP32-A1S. Examples include wave generators, simple synthesizers, MP3 decoders for online stream sources as well as MP3 files on SD flash cards. Use GNU Octave (or MATLAB) to design and test digital FIR filters that can be implemented on the ESP32 Audio Development Kit. Hack multi-channel audio connectors:

https://www.instructables.com/HackerBox-0079-Audio-DSP/

## Marcel License

Marcel License's repo at https://github.com/marcel-licence has a lot of great music projects built around ESP-32:

### Little startup guide for ESP32 Arduino DIY MIDI Synthesizer Projects

A great [Youtube](https://youtu.be/ZNxGCB-d68g) video to get started with Arduino IDE and git and Marcel's audio projects.

### ESP32 based DIY polyphonic MIDI synthesizer module

The project is published on [Github](https://github.com/marcel-licence/esp32_basic_synth) and demonstrated on [Youtube](https://youtu.be/5XVK5MOKmZw). It has been tested on the ESP32 Audio Kit v2.2 (see above) and on the widely used ESP32 DEVKIT - DOIT. 

The project also uses the following software by the same author:

### USB MIDI for the ESP32

For more information refer to the MIDI related project: https://github.com/marcel-licence/esp32_usb_midi Using USB can be seen here: https://youtu.be/Mt3rT-SVZww

