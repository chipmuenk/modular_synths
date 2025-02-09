[Back to Teensy](./teensy.md)

---

# FFT Analysis of an Audio Stream with Teensy

In this example an audio stream with sample rate of 44.1 kHz is mixed with a sine signal and analysed with a 1024 point FFT, the first 25 bins (0 ... 1.1 kHz) are printed to the serial monitor. This is based on the example `File -> Examples -> Audio -> ...`. Additionally, the maximum value, its index and the corresponding frequency is printed.

When a button is pressed, the bin with the current maximum of the FFT is stored and the frequency of the notch filter is adapted correspondingly. The notched output is also analyzed with an FFT, here, only the maximum and its index are printed.

Every pin of the Teensy can be configured as a digital input or output, an integrated pullup can be activated for input pins (`pinMode(pin_no, INPUT_PULLUP)`). The numbering scheme corresponds to the numbers printed on the Teensy board, ranging between 0 and 23.

See also ["FFT on the Teensy with Hackster.io Teensy Audio"](https://youtu.be/S8A7ZuupS_M) and ["FFT: Fun with Fourier Transform"](https://learn.adafruit.com/fft-fun-with-fourier-transforms/overview-1).

## Teensy GUI

<img src="../img/teensy_gui_audio_fft_notch.png" alt="Teensy GUI: FFT analysis of audio stream and filter configuration" width="50%"/>

## Code

### Class AudioAnalyzeFFT1024

The class `AudioAnalyzeFFT1024` (instantiated e.g. as `fft1024`) supports the following methods and objects:

- `fft1024.available()` returns `True` every time the FFT has produced new data (approx. 86 times per second).

- `fft1024.read(bin)` returns the magnitude of the corresponding bin (0 ... 511) as a float. A sine input with amplitude 1.0 with the "bin frequency" yields an output of 0.5 (double-sideband scaling). 

- `fft1024.read(firstBin, lastBin)` returns the sum of the specified bins. The higher audio octaves contain many bins, which can be read as a group for audio visualization.

- The array `fft1024.output` contains the 512 raw (unscaled) `uint16_t` output bins. For some reason (probably for optimum numeric accuracy), the scaling is `read(bin) = output[bin] / (1024 * 16)`.

- The window function is set with `fft1024.windowFunction(window)` where the default window function is `AudioWindowHanning1024` (i.e. a Hann window). `fft1024.windowFunction(NULL)` yields rectangular windowing.

The names of the `AudioAnalyzeFFT256` methods comply to a similar scheme.

### Library teensy_lib

Functions are stored in a separate library in order to keep the main file short. To create header and library files `teensy_lib.h` and `teensy_lib.cpp`, you need to open a new tab in the Arduino IDE ('...' on the right hand side). Or you simply copy the files into the sketch directory and restart the IDE.

#### teensy_lib.h

```C
#ifndef TEENSY_LIB_H
#define TEENSY_LIB_H

void findMax(uint16_t myArray[], int size, uint16_t &max_idx, uint16_t &max_value);

void printNumber(float n);
void printNumberInt(int n);

#endif //TEENSY_LIB_H
```

#### teensy_lib.cpp

```C
#include <Arduino.h> //needed for Serial.println()
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

const float noteFrequency[12] = {
  220.00,  // A3
  233.08,  // A#3
  246.94,  // B3
  261.63,  // C4
  277.18,  // C#4
  293.66,  // D4
  311.13,  // D#4
  329.63,  // E4
  349.23,  // F4
  369.99,  // F#4
  392.00,  // G4
  415.30   // G#4
};

void findMax(uint16_t myArray[], int size, uint16_t &max_idx, uint16_t &max_value) {
    /* search for array index of maximum element. Return the index in max_idx and the value in
       max_value, both variables are passed by reference.
     */
    assert(myArray && size);
    size_t i;
    max_value = myArray[0];
    max_idx = 0;

    for (i = 1; i < size; ++i) {
        if ( myArray[i] > max_value ) {
            max_value = myArray[i];
            max_idx = i;
        }
    }
}

void printNumber(float n) {
  
  if (n >= 0.004) {
    Serial.print(n, 3); // three fractional places
    Serial.print(" ");
  } else {
    Serial.print("   -  "); // don't print "0.00"
  }
}
```

`void findMax(uint16_t myArray[], int size, uint16_t &max_idx, uint16_t &max_value)` finds the maximum value in `myArray[]` with size `size` and returns it as `max_value` at index `max_idx`. Both variables are passed as references.

The `assert()` statement 'enforces the contract', i.e. that a valid array with at least one member is passed to the max function.

The `for` loop starts with the second element of the array, because `max_value` is already initialized with the first element.

```C
#include <Audio.h>  //  includes from library
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "teensy_lib.h"  // includes from sketch folder

// GUItool: begin automatically generated code
AudioSynthWaveformSine sine1;  //xy=311,118
AudioInputI2S i2s2;             //xy=312,153
AudioMixer4 mixer1;             //xy=460,137
AudioFilterBiquad biquad1;      //xy=618,137
AudioAnalyzeFFT1024 fft1024_1;  //xy=623,176
AudioOutputI2S i2s1;  //xy=770,138

AudioConnection patchCord1(sine1, 0, mixer1, 0);
AudioConnection patchCord2(i2s2, 0, mixer1, 1);
AudioConnection patchCord3(i2s2, 1, mixer1, 2);
AudioConnection patchCord4(mixer1, biquad1);
AudioConnection patchCord5(mixer1, fft1024_1);  // direct
AudioConnection patchCord6(biquad1, 0, i2s1, 0);
AudioConnection patchCord7(biquad1, 0, i2s1, 1);
//AudioConnection          patchCord8(biquad1, fft1024_2);  // this freezes first FFT ?
// GUItool: end automatically generated code

AudioControlSGTL5000 sgtl5000_1;  //xy=512,428
// GUItool: end automatically generated code

// const int ledPin = 6;
const int buttonPin = 11;
const int testPin = 12;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(testPin, OUTPUT);
  Serial.begin(9600);
  AudioMemory(15);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);
  sgtl5000_1.inputSelect(AUDIO_INPUT_MIC);
  delay(300);
  sine1.frequency(16 * 44100 / 1024);
  sine1.amplitude(0.5);
  mixer1.gain(0, 0.5);
  mixer1.gain(1, 0.5);
  mixer1.gain(2, 0.5);
  biquad1.setNotch(0, 300);
  // fft1024_1.windowFunction(NULL);  // set rect window

  // Initialize the system
  Serial.println("setup done");
}
byte buttonPreviousState = HIGH;  // what state was the button last time
unsigned long last_time_perf = millis();
unsigned long last_time_button = millis();
uint16_t max_idx, max_value, max_filt_idx, max_filt_value;
float max_freq = 500.0;
float max_filt_freq = 500;
bool bPrintFFTValues = false;

void loop() {
  // print Fourier Transform data to the Arduino Serial Monitor
  // when new data becomes available
  if (fft1024_1.available()) {
    if (bPrintFFTValues) {
      Serial.print("FFT: ");
      for (int i = 0; i < 30; i++) {    // 0-25  -->  DC to 1.25 kHz
        float S_i = fft1024_1.read(i);  // scaled, float FFT
        printNumber(S_i);
        // uint16_t n_raw = fft1024_1.output[i];  // raw, unscaled FFT
        // printNumberInt((int)n_raw); // type cast from uint16_t to int
      }
    }

    findMax(fft1024_1.output, 512, max_idx, max_value);
    // findMax(fft1024_2.output, 512, max_filt_idx, max_filt_value);
    max_freq = (float)max_idx * 44100.0 / 1024.0;
    max_filt_freq = (float)max_filt_idx * 44100.0 / 1024.0;
    if (bPrintFFTValues) {
      Serial.print("Max = ");
      Serial.print(max_value);
      Serial.print(" @ ");
      Serial.print(max_idx);
      Serial.print(" = ");
      Serial.print(max_freq);
      Serial.print(" Hz");
      Serial.print("|| Max (filt.)= ");
      Serial.print(max_filt_value);
      Serial.print(" @ ");
      Serial.print(max_filt_idx);
      Serial.print(" = ");
      Serial.print(max_filt_freq);
      Serial.println(" Hz");
    }
    float freq = 100.0 + (float)analogRead(15);  // scale from 100 ... 1123
    //Serial.print(freq);
    //Serial.print(" Hz ");
    sine1.frequency(freq);
  }
  // read button every 100 ms - this also performs de-bouncing
  if (millis() - last_time_button >= 100) {

    byte buttonState = digitalRead(buttonPin);
    if (buttonState == LOW && buttonPreviousState == HIGH)
    {
      biquad1.setNotch(0, max_freq);
    }
    buttonPreviousState = buttonState;
    digitalWrite(testPin, buttonState);       // copy state to another pin for debugging
    digitalWrite(LED_BUILTIN, !buttonState);  // turn on LED when button is pressed
    last_time_button = millis();              // update time variable
  }

  // print information about processor and memory usage every 2500 ms
  if (millis() - last_time_perf >= 2500) {
    Serial.print("Proc = ");
    Serial.print(AudioProcessorUsage());  // usage in percent
    Serial.print(" (");
    Serial.print(AudioProcessorUsageMax());  // max. processor usage
    Serial.print("),  Mem = ");
    Serial.print(AudioMemoryUsage());  // memory usage in blocks
    Serial.print(" (");
    Serial.print(AudioMemoryUsageMax());  // max. memory usage in blocks
    Serial.println(")");
    last_time_perf = millis();  // update time variable
  }
}

```

## Measurement

Generate an audio signal with 44100 Hz sampling frequency, overlayed with a sine or a chirp signal and feed it into the Teensy.

A sine source is added on the Teensy, its frequency can be set with the potentiometer. The FFT of the mixed signals is calculated and printed to the serial monitor. The notch frequency of the filter is set according to the maximum of the FFT.

## Further experiments / ideas

### Real-time update of coefficients
The filter can also be defined by calculating and setting the coefficients:

```c++
double koeffizienten[5];
float c;
float r = 0.95;

// calc koeffs
c = (1 + 2*r*cos(2*PI*freq_est/fS) + r*r)/(1 + 2*cos(2*PI*freq_est/fS) + 1);
// koeffizienten = [B0, B1, B2, A1, A2]
koeffizienten[0] = c;
koeffizienten[1] = (-2*cos(2*PI*freq_est/fS)) * c;
koeffizienten[2] = c;
koeffizienten[3] = -2*r*cos(2*PI*freq_est/fS);
koeffizienten[4] = r*r;
biquad1.setCoefficients(0, koeffizienten);
```

### Quadratic interpolation
The frequency of the sine disturbance can be measured more accurately by interpolating between the FFT bins. An algorithm for quadratic interpolation is described here:

https://ccrma.stanford.edu/~jos/sasp/Quadratic_Interpolation_Spectral_Peaks.html

```c++
double f0_estimated;
double y0_0, ym1, yp1;
 y0_0 = max_value;

ym1 = fft1024_1.output[max_idx - 1];
yp1 = fft1024_1.output[max_idx + 1];

double p = (yp1 - ym1) / (2 * (2 * y0_0 - yp1 - ym1));

f0_estimated = (max_idx + p) * fDeltaf;

```

---

[Back to Teensy](./teensy.md)
