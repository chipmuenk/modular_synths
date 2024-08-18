[Back to Teensy](./teensy.md)

---

# Creating Custom Audio Objects with AudioRecordQueue and AudioPlayQueue

The previous experiment has shown how to implement an custom object using the queue objects `AudioRecordQueue` and `AudioPlayQueue`. Another solution is shown here which derives from the `AudioStream` class. The advantage of this approach is that the derived class takes care of memory management, communication with other objects and CPU usage tracking which other objects from the audio library have as well.

## Behind the Scenes

- [PJRC: Creating New Audio Objects](https://www.pjrc.com/teensy/td_libs_AudioNewObjects.html) explains in detail how to derive and implement a new object class derived from `AudioStream`.
- [Steven Hazel, Writing a custom effect from scratch with the Teensy Audio Library](https://blog.blacklightunicorn.com/writing-a-custom-effect-from-scratch-with-the-teensy-audio-library/) gives a complete tutorial on how to create a a tremolo effect as a custom object class.

Obviously, there is no representation for the new object class in the Teensy Audio System Design Tool. But the new class should be instantiated and connected to other audio objects exactly as "standard" audio objects due to inheritance.

## Code

The code is taken from the discussion [PJRC Forum, "Accessing 128 bit sample packets"](https://forum.pjrc.com/index.php?threads/accessing-128-bit-sample-packets.59171/).


```CPP
// taken from https://www.pjrc.com/teensy/td_libs_AudioNewObjects.html

#include <Arduino.h>
#include <AudioStream.h>

class AudioEffectTemplate : public AudioStream
{
public:
        AudioEffectTemplate() : AudioStream(1, inputQueueArray) {
          // any extra initialization
        }
        virtual void update(void);
private:
        audio_block_t *inputQueueArray[1];
}
```

---

[Back to Teensy](./teensy.md)