[Back to main](./README.md)

<hr>

# Hardware

- [Pinout](https://www.pjrc.com/teensy/pinout.html) and [schematic](https://www.pjrc.com/teensy/schematic.html) for all Teensy boards

- [Pinout](https://www.pjrc.com/audio-shield-for-teensy-4-0/) and [schematic](https://www.pjrc.com/store/teensy3_audio.html) for Teensy 4.0 audio shield

# Software
In order to use the Arduino IDE to upload binaries to Teensy boards, you need to install the [Teensyduino](https://www.pjrc.com/teensy/td_download.html) add-on in Arduino.

Under `File -> Preferences -> Additional boards manager URLs` add `https://www.pjrc.com/teensy/package_teensy_index.json`, separated by a comma without blanks from (maybe)
other entries.

Next, in the main Arduino window, open `Boards Manager` by clicking the left-side board icon, search for "teensy", and click "Install" Teensy (for Arduino IDE 2.04 or later). 
This covers all Teensy boards.


# Synth Projects with Teensy Microcontroller Boards

https://www.pjrc.com/store/audio_tutorial_kit.html

- [Lab 1: Faust Basics and Digital Musical Instrument](https://ccrma.stanford.edu/courses/250a-spring-2021/labs/1/)
- [Lab 2: Embedded Audio DSP with Faust and the Teensy](https://ccrma.stanford.edu/courses/250a-spring-2021/labs/2/) This also explains how to connect the Teensy and the Teensy audio shield via stackable headers
- [Lab 3: Sensors and Physical Interface Design (with Teensy)](https://ccrma.stanford.edu/courses/250a-spring-2021/labs/3/)
- [Lab 4: "Hybrid" Instruments](https://ccrma.stanford.edu/courses/250a-spring-2021/labs/4/)

## USB MIDI for Teensy

## USB Audio for Teensy
There are two good reasons for choosing the Teensy to create audio applications: Its fast (480 Mbit/s) USB port and the [Audio System Design Tool](https://www.pjrc.com/teensy/gui/) which 
is a browser based UI for drawing sources and sinks to process 16 bit 44.1 kHz streaming audio. "Export" will generate code that can be copied into the Arduino editor.

Before compiling, you need to configure the USB interface for audio under 
[img](img/teensy_arduino_usb_audio_settings.png)
<img src="img/teensy_arduino_usb_audio_settings.png" alt="USB audio settings for Arduino IDE" width="40%"/>

For uploading the binary to the Teensy board, you should select the board under Tools -> Ports -> [teensy ports]

In Audacity, select "Teensy Audio" for input and output. Then, you can use a stereo track with a recording or a generated signal as a source and another stereo track to record to.

[Notes and Volts, "Teensy as a USB audio interface"](https://youtu.be/om9yePUsYps)


https://www.pjrc.com/store/teensy41.html (usb audio)

https://forum.pjrc.com/index.php?threads/usb-audio-for-teensy-3-0.24309/page-2

# Daisy

https://electro-smith.com/products/daisy-seed?variant=45234245140772

https://forum.electro-smith.com/t/oscpocketd-base-1-2-midi-fx-unit-synth-sampler-modulator/1912/26

https://github.com/electro-smith/DaisyWiki/wiki

# Software

[PureData](https://en.m.wikipedia.org/w/index.php?title=Pure_Data&wprov=rarw1)

[Max/Gen](https://docs.cycling74.com/max8/vignettes/gen_topic)

<hr>

[Back to main](./README.md)