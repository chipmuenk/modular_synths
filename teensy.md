[Back to main](./README.md)

<hr>

# Hardware

Recent Teensy microcontroller boards are build around 32 bit ARM controllers (see [details](https://www.pjrc.com/teensy/techspecs.html)):

- Teensy 3.6 with a 180 MHz Cortex M4F controller (32 bit floating point unit, DSP instructions), 256k RAM and 1024k flash, two twelve bit DACs
- Teensy 4.0 with a 600 MHz Cortex M7 controller (32 and 64 floating point unit, DSP), 1024k RAM and 1984k flash, no DAC
- Teensy 4.1 with a 600 MHz Cortex M7 controller (32 and 64 floating point unit, DSP), 1024k RAM and 7936k flash, no DAC

# Software

## Teensyduino

In order to use the Arduino IDE to upload binaries to Teensy boards, you need to install the [Teensyduino](https://www.pjrc.com/teensy/td_download.html) add-on in the Arduino IDE as described in this [tutorial](https://www.pjrc.com/teensy/tutorial.html).

Add the Teensy URL under `File -> Preferences -> Additional boards manager URLs` add `https://www.pjrc.com/teensy/package_teensy_index.json`, separated by a comma without blanks from other entries (if any).

Next, in the main Arduino window, open `Boards Manager` by clicking the left-side board icon, search for "teensy", and click "Install" Teensy (for Arduino IDE 2.04 or later). This covers all Teensy boards.

Under Linux, you need to download [00-teensy.rules](http://www.pjrc.com/teensy/00-teensy.rules) and copy it to your rules via

`sudo cp 00-teensy.rules /etc/udev/rules.d/00-teensy.rules`

in order to give non-root users access to the Teensy via the USB port. This text file contains some more info and trouble shooting tips.

## 

# Synth Projects with Teensy Microcontroller Boards

https://www.pjrc.com/store/audio_tutorial_kit.html

- [Lab 1: Faust Basics and Digital Musical Instrument](https://ccrma.stanford.edu/courses/250a-spring-2021/labs/1/)
- [Lab 2: Embedded Audio DSP with Faust and the Teensy](https://ccrma.stanford.edu/courses/250a-spring-2021/labs/2/)
- [Lab 3: Sensors and Physical Interface Design (with Teensy)](https://ccrma.stanford.edu/courses/250a-spring-2021/labs/3/)
- [Lab 4: "Hybrid" Instruments](https://ccrma.stanford.edu/courses/250a-spring-2021/labs/4/)

## USB MIDI for Teensy

## USB Audio for Teensy



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