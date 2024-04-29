[Back to ESP32](./esp32.md)

<hr>

# Arduino Audiokit Library

Phil Schatzmann has written the [Arduino Audiokit Library](https://github.com/pschatzmann/arduino-audiokit) as a replacement for the [Espressif Audio Development Framework (ADF)](https://github.com/espressif/esp-adf) Drivers which cannot be used with the Arduino IDE:

> There are different ESP32 Audio boards available that can be programmed with the Espressif ADF Framework. The ADF Framework contains an abstraction layer to support different codec audio chips (ES8388, ES8311, AC101...) which need to be configured usually via I2C.

This library has been archived and should be replaced by [arduino-audio-driver](https://github.com/pschatzmann/arduino-audio-driver) (see below) for new projects. However, it is still widely used. It can be downloaded as a zip archive and simply added to the IDE.
In the freshly installed audiokit library, board and codec need to be selected in

    libraries/audiokit/src/AudioKitSettings.h

requiring for the ESP32 Audio Kit v2.2

    #define AUDIOKIT_BOARD 5

Additionally, the following setting should be present to enable the headphone socket

    #define AI_THINKER_ES8388_VOLUME_HACK 1

After the installation (and maybe a restart), you should see new examples under

    File -> Examples -> audiokit

The example 'output' generates a 1000 Hz sinusoidal tone, the example 'input' reads L and R channel of audio and plots them on the serial plotter.

The example `input` plots L and R channel of the audio input on the serial plotter. In order to use the onboard microphones instead, change

    cfg.adc_input = AUDIO_HAL_ADC_INPUT_LINE1;

to

    cfg.adc_input = AUDIO_HAL_ADC_INPUT_LINE2;

and open `Tools -> Serial Plotter` and set the baud rate to 115200.

However, this made no difference for me, the signal was just a few LSBs of noise in both cases.

<hr>

[Back to ESP32](./esp32.md)