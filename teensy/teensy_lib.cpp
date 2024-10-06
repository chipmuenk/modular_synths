#include<Arduino.h> //needed for Serial.println()
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

  void printNumberInt(int n) {
  
  if (n >= 20) {
    Serial.print(n, DEC);
    Serial.print(" ");
  } else {
    Serial.print("   -  "); // don't print "0.00"
  }
  
  /*
  if (n > 0.25) {
    Serial.print("***** ");
  } else if (n > 0.18) {
    Serial.print(" ***  ");
  } else if (n > 0.06) {
    Serial.print("  *   ");
  } else if (n > 0.005) {
    Serial.print("  .   ");
  }
  */
}