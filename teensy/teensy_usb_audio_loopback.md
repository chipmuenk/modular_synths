# USB Audio Loopback with Teensy

    #include <Audio.h>
    #include <Wire.h>
    #include <SPI.h>
    #include <SD.h>
    #include <SerialFlash.h>

    // GUItool: begin automatically generated code
    AudioInputUSB            usb2;           //xy=303,504
    AudioAmplifier           amp1;           //xy=448,572
    AudioOutputUSB           usb1;           //xy=604,501
    AudioConnection          patchCord1(usb2, 0, usb1, 0);
    AudioConnection          patchCord2(usb2, 1, amp1, 0);
    AudioConnection          patchCord3(amp1, 0, usb1, 1);
    // GUItool: end automatically generated code

    void setup() {
    // put your setup code here, to run once:
    }

    void loop() {
    // put your main code here, to run repeatedly:
    }
