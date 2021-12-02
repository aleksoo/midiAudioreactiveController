#include <Arduino.h>

#include <config.h>
#include "InputDevice.h"
#include "EncodersDriver.h" 
// TODO: Midi handler class?

InputDevice *inputDevices[NUMBER_OF_INPUT_DEVICES];
EncodersDriver *encodersDriver;

void setup() 
{
  Serial.begin(9600); // setup serial

  // Set up classes for input devices
  for(int index = 0; index < NUMBER_OF_INPUT_DEVICES; ++index) 
  {
    inputDevices[index] = new InputDevice(inputPins[index], 500);
  }

  // Set up for encoders handling
  encodersDriver = new EncodersDriver();
  
}

void loop() {
  
} 
