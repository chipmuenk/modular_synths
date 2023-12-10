# Faust
As a "Hello World" I tried to implement the Faust ESP32 example on my [ESP32 Audio Kit v2.2 A247](https://docs.ai-thinker.com/en/esp32-audio-kit) board which is built around the [ESP32-A1S Audio Module](https://docs.ai-thinker.com/en/esp32-a1s).
This module contains an ESP32-WROVER PCB, i.e. an ESP32-D0WDQ6 chip with external 4 MB SPI Flash and 8 MB PSRAM. The "A1S" suffix hints at the integrated DAC that is cconnected via I2S. My version contains an ES8388 chip and a CODEC 

Details are described by [pschatzmann](https://www.pschatzmann.ch/home/2021/12/06/the-ai-thinker-audio-kit-experience-or-nothing-is-right/)
and in [radiobastler.de](https://radio-bastler.de/forum/showthread.php?tid=17786) (German). The differences between the AC101 and the ES8388 version are described in [https://www.docdroid.net/L6LX9SK/esp32-a1s-esv23zh-cnen-pdf#page=6]

- CP2102 USB2UART bridge
- 2 onboard microphones
- 2 NS4150 Class D audio amplifiers
- 6 general purpose push buttons
