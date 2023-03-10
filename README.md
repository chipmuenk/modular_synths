# modular_synths
Information, schematics and software for modular synths

<img src="kabel_vignette_r.JPG" alt="cables" width="50%"/>

The idea behind this repo is to collect ideas and links concerning electronic music gear using analog modular synths, MIDI modules and maybe FPGAs. And of course to develop own designs.

## General
* [**Moritz Klein**](https://www.youtube.com/c/MoritzKlein0/videos) certainly creates some of best synth related DIY stuff you can find on Youtube. Together with [Erica Synths](https://www.ericasynths.lv/) he even developed a series of educational DIY synth modules [mki x es.EDU](https://www.ericasynths.lv/news/mki-x-esedu/).
* [**Look Mum No Computer**](https://www.lookmumnocomputer.com/) and especially his [Youtube Channel](https://www.youtube.com/@LOOKMUMNOCOMPUTER/videos) breathe a true punky DIY spirit!  Many designs are described and can be bought at his [KosmoModularGrid Shop](https://www.kosmodulargrid.com/).
* Kevin's [Simple DIY Electro Music Projects](https://diyelectromusic.wordpress.com) and his [Youtube Channel](https://www.youtube.com/c/SimpleDIYElectroMusicProjects) provide tons of information on music electronics, especially for Arduino and RPi Pico.
* **Bamanya Brian** from Uganda is a true DIY synth guy, on his [Afrorack Youtube channel](https://www.youtube.com/channel/UCPfBqZQ2P8NqY7puxYzirtw) he shows what he calls [Africa's first home made modular synth](https://youtube.com/watch?v=ov2sEfUv1XY), what it's like to [how to make cheap synth modules](https://youtube.com/watch?v=eELTtd9Bv-k) and demonstrates [some African rhythms on modular synth](https://youtube.com/watch?v=RhWh21uvUZo). He also shows [how to make a MIDI to CV converter for 5$](https://youtube.com/watch?v=UYeJiPWZZNQ).
* [**Notes and Volts**](https://www.notesandvolts.com/) and his [Youtube Channel](https://www.youtube.com/c/NotesAndVolts) have lots of interesting audio projects, mainly built around uCs like the Teensy.
* [**Rene Schmitz**](https://www.schmitzbits.de/) Schmitzbits is a treasure trove for analog synth related circuits.
* [**Raymond Schouten**](www.rs-elc.nl) has some very reduced but interesting projects for mixed analog / Arduino synthesizers.

## Analog Hardware


## MIDI
### Electrical specification and interfaces
* [MIDI 1.0 DIN Electrical Specification](https://www.midi.org/specifications-old/item/midi-din-electrical-specification), straight from the horse's mouth for 3.3V and 5V. The full spec reveals that the receiver must require less than 5 mA to turn on and that rise and fall times should be less than 2 microseconds, limiting the choice of opto couplers.
* [Kevin's MIDI Cheatsheet](https://diyelectromusic.files.wordpress.com/2021/05/sdemp-midi-connections-cheat-sheet.pdf) is even better with an RX/TX schematic and pinnings
* Notes and Volts [MIDI for the Arduino - Circuit Analysis](https://youtube.com/watch?v=0L7WAMFWSgY) describes the MIDI In circuit in detail for a 6N138 opto coupler in detail, including the biasing resistor for faster turn-off.
* Even more details on opto coupler behaviour can be found in [Opto-couple confusion ??? 6N137 or 6N138?](https://gr33nonline.wordpress.com/2019/05/15/opto-couple-confusion-6n137-or-6n138/). Some common opto couplers are given below:
  * 4N37 / 4N38: Built with photo transistors, hence inherently slow with turn-on and turn-off times around 10 us. Should not be used
  * 6N137 / VO2601 / VO2611: Specified for 5 mA LED current, featuring a fast photo diode receiver (t_r typ. 23 ns, t_f typ. 7 ns) and a Shottky clamped open collector output. Min. VCC is specified with 5 V. VO2630 / VO2631 / VO4661 have two channels.
  * 6N138 / 139: Specified for LED currents in the range 0.5 ... 12 mA and min. current transfer ratios of 300% resp. 500% with a photo diode / darlington receiver. Min. VCC is specified as 5V, but it seems the collector of the output transistor (Pin 6) can be connected to 3.3V via 270 Ohm. The base of the output transistor (Pin 7) should be tied to ground with 4k7 resistor to speed up turn-off times. Propagation delays are specified with wide variations but 2 us should be achievable.
  * HC11A1: Receiver is built with a foto transistor, still non-saturated turn-on and turn-off times around 3 us are specified. A non-saturated current transfer ratio of around 100 % is specified. Usable?
* [Send and Receive MIDI With Arduino](https://www.instructables.com/Send-and-Receive-MIDI-with-Arduino/), basic MIDI connection and operation using Arduino / Arduino IDE.
* [Arduino MIDI shield](http://www.thebox.myzen.co.uk/Hardware/MIDI_Shield.html), another basic MIDI I/O circuit using a PNP transistor to buffer the output (Arduino-IDE).
### MIDI to CV converter
* [MIDI to CV Skull](https://learn.adafruit.com/circuitpython-midi-to-cv-skull), a MIDI to CV converter shaped like a skull (well ...) using an RPI Pico with an MCP4725 I2C 12 bit DAC (CircuitPython)
* [Basic MIDI to CV converter](https://www.hackster.io/janost/diy-good-ol-midi-to-cv-d0e2bf) using an AT Tiny and PWM (C)

### MIDI routing and decoding
* Kevin's diyelectromusic has a great set of basic MIDI project tutorials on a RPi Pico with Micropython to be up and running in no time at all:
  * [MIDI (out), MicroPython and the Raspberry Pi Pico](https://diyelectromusic.wordpress.com/2021/01/23/midi-micropython-and-the-raspberry-pi-pico/), a "Hello World" project to write some MIDI commands.
  * [MIDI In for 3.3V Microcontrollers](https://diyelectromusic.wordpress.com/2021/02/15/midi-in-for-3-3v-microcontrollers/) is counterpart
  * [Raspberry Pi Pico MIDI Channel Router](https://diyelectromusic.wordpress.com/2021/06/13/raspberry-pi-pico-midi-channel-router/) routes a MIDI In port to one of 8 MIDI Out ports, utilizing a.o. the RPi PIO functionality.  With detailled explanation of channel decoding - funtastic!
  * [Raspberry Pi Pico MIDI Channel Merger](https://diyelectromusic.wordpress.com/2021/12/19/raspberry-pi-pico-midi-channel-merger/) works the other way round, merging signals from eight MIDI Inputs to one MIDI output.
  * [Raspberry Pi Pico Multi MIDI Router](https://diyelectromusic.wordpress.com/2021/12/28/raspberry-pi-pico-multi-midi-router/) is a five part project for a general 6-IN, 6-OUT MIDI routing device.

## uC

* [Raspberry Pi Pico: Grundlagen der Energieversorgung / Stromversorgung](https://www.elektronik-kompendium.de/sites/raspberry-pi/2611061.htm), how to power a RPi Pico from (German) via Micro-USB connector, VBUS pin, 3V3 pin or VSYS pin without frying it
* [EuroPi](https://github.com/Allen-Synthesis/EuroPi) is a fully user reprogrammable module based on the Raspberry Pi Pico.
* [Arduino Beat Detector](https://projecthub.arduino.cc/mamifero/881c722e-1049-4d82-a91d-56f000ed7b60), using just a coupling capacitor and simple IIR filters to extract beat timing from audio data

## FPGAs

[Open Hardware Eurorack Compatible Audio FPGA Front End](https://hackaday.com/2023/02/13/an-open-hardware-eurorack-compatible-audio-fpga-front-end/) is a really cool project, built around a AK4619VN four-channel audio codec providing four analog inputs and four analog outputs on a narrow module. Sample code for an Icebreaker FPGA (Lattice) board is provided and all files are on [Github](https://github.com/schnommus/eurorack-pmod). There is even a [Plugin](https://github.com/schnommus/verilog-vcvrack) allowing to run Verilog code inside the VCV Rack audio simulator!
