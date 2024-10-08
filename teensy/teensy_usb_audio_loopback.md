[Back to Teensy](./teensy.md)

---

# USB Audio Loopback with Teensy

A first experiment that requires only the Teensy board and Audacity (or another audio software) on the PC: An audio stream is generated, received and analyzed with Audacity, using the USB audio input and output of the Teensy board. The peak values of the audio signal are printed to the console which is helpful for debugging. In the end, the usage of `delay()` vs. `millis()` vs. `elapsedMillis` is discussed. 

## Audio Setup and Buffering

The TeensyDuino audio library is hard-coded for 16-bit, 44.1kHz sample rate, with a 128-sample buffer (2.9 ms latency). The USB connection is hard-coded for stereo. During compilation, the Arduino IDE needs to be set to `Tools -> USB Type -> Audio`. Otherwise, the `AudioInputUSB` and `AudioOutputUSB` classes won't be recognized. See also [PJRC: Teensy Audio Library](https://www.pjrc.com/teensy/td_libs_Audio.html) and, in more detail, [Github: Audio Library Internals](https://github.com/TeensyUser/doc/wiki/Audio-Library-internals).

When problems occur with loopback in Audacity (i.e. streaming one track and recording to a second track) it might help to switch the audio API between application (e.g. Audacity) and the sound device:

- MME ((Multimedia Events, released in 1991) is the Audacity default and should be most compatible with most audio devices, but I couldn't get loopback mode working.
- WASAPI (Windows Audio Session API, released in 2007) supposedly has the lowest latency and also supports 24 bits. It should be preferred for loopback (and helped in my case)
- Windows DirectSound supposedly is a Direct-X related interface to WASAPI, so there should not be much difference. There might be some extra buffering which can improve stability but (of course) increases latency.

The audio buffer size for all audio connections needs to be set with `AudioMemory(numberBlocks)` during `setup()` where `numberBlocks` is the number of 128 sample blocks, for a start a value of 10 (29 ms) is fine. Higher numbers reserve more memory that might be needed otherwise, lower numbers might cause "hiccups" due to buffer underflows. For debugging, use the function `AudioMemoryUsageMax()`. See the discussion [AudioMemory() - what parameter should I pass?](https://forum.pjrc.com/index.php?threads/audiomemory-what-parameter-should-i-pass.39245/). See the example [teensy_usb_audio_fir_filter.md](./teensy_usb_audio_fir_filter.md) for an example how to use these functions.

The roundtrip latency is higher than that, probably due to additional buffering by the operating system. If needed (e.g. for multi-track recordings) this can be accounted for in the Audacity settings.

The additional `delay()` statements in the `setup()` part help to avoid some initial glitches in the signal.

Further info: 

- [Teensy Audio over USB](https://openaudio.blogspot.com/2016/10/teensy-audio-over-usb.html)
- [Nuts & Volts (YouTube): "TEENSY - USB Audio Interface"](https://youtu.be/om9yePUsYps) walks through the hardware and software setup and shows how to connect the line input of the Teensy.
- [PJRC, Audio Connections & Memory](https://www.pjrc.com/teensy/td_libs_AudioConnection.html) shows a.o. how to setup Audacity for simultaneous playback and recording.
- [PJRC Forum, "USB Audio for Teensy 3.0"](https://forum.pjrc.com/index.php?threads/usb-audio-for-teensy-3-0.24309/page-2), developer discussions on the audio library

## Teensy GUI

<img src="../img/teensy_gui_usb_loopback.png" alt="Teensy GUI: USB loopback" width="40%"/>

## Code

Except for the `setup()` and `loop()` statements, the code has been generated by and exported from the Teensy Audio System Design Tool.

```C
#include <Audio.h>
#include <Wire.h>

// GUItool: begin automatically generated code
AudioInputUSB            usb1;           //xy=444,1395
AudioAnalyzePeak         peak1;          //xy=590,1360
AudioOutputUSB           usb2;           //xy=590,1395
AudioAnalyzePeak         peak2;          //xy=590,1431

AudioConnection          patchCord1(usb1, 0, usb2, 0);
AudioConnection          patchCord2(usb1, 0, peak1, 0);
AudioConnection          patchCord3(usb1, 1, usb2, 1);
AudioConnection          patchCord4(usb1, 1, peak2, 0);
// GUItool: end automatically generated code


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  // initialize Serial Monitor with 9600 baud
AudioMemory(10);  // 10 x 128 samples = 29 ms
delay(50);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  if (peak1.available()){
    Serial.print("Peak left channel = ");
    Serial.println(peak1.read());  // print peak value since last read()
  }
  if (peak2.available()){
    Serial.print("Peak right channel = ");
    Serial.println(peak2.read());
  }
}
```

## Audacity Setup

Select "Teensy Audio: USB Audio" as recording and playback device. This is only available when `USB Type: Audio` has been selected during compilitation and when a USB sink and source is used.

Under Linux, you can list playback and recording interfaces with `aplay -l` resp. `arecord -l` (ALSA soundsystem) and `alsamixer`. 

Generate a stereo track in Audacity with 44100 Hz sampling rate and e.g. a sine or a chirp signal with a duration of 5 s.

Generate another empty stereo track and press the record button. This should send the generated audio signal to the Teensy board and record the processed audio simultaneously, you should see a slightly delayed copy of the input signal.

In order to reduce "hiccups", Audacity needs some buffering. Starting with 100 ms you should be on the safe side. This latency and other delays can be compensated under "latency compensation" by entering a corresponding negative number.

### Variations

While the `delay()` function does not block the audio processing (audio processing is performed in frames of 128 samples, triggered by an interrupt), it *does* block other commands in the `loop()` part while "delaying".

For that reason, the `millis()` function should be used for more complex cases, it returns the number of milliseconds elapsed since powering up the uC. A "normal" int (16 bits) would overflow after less than 33 s, but with an `unsigned long` (32 bits) this takes nearly 50 days.

Using `millis()` allows a.o. to start multiple functions with different delays.

```C
const long interval = 100;
unsigned long previousMillis last_ms = 0;

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    if (peak1.available()){
        Serial.print("Peak left channel = ");
        Serial.println(peak1.read());  // print peak value since last read()
    }
    if (peak2.available()){
        Serial.print("Peak right channel = ");
        Serial.println(peak2.read());
    }
    previousMillis = currentMillis;
}
```

In the code above, a subtraction has to be performed. The built-in counter `elapsedMillis` is more efficient. Attention: When `elapsedMillis` is created as a local variable (inside a function), it automatically starts at zero each time the function executes. See [Using elapsedMillis & elapsedMicros](https://www.pjrc.com/teensy/td_timing_elaspedMillis.html) for details.

```C
const long interval = 100;
elapsedMillis delta_ms = 0;  // global variable

void loop() {
  if (delta_ms >= interval)
  {
    if (peak1.available()){
        Serial.print("Peak left channel = ");
        Serial.println(peak1.read());  // print peak value since last read()
    }
    if (peak2.available()){
        Serial.print("Peak right channel = ");
        Serial.println(peak2.read());
    }
    delta_ms = 0;
}
```

---

[Back to Teensy](./teensy.md)