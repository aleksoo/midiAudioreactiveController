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

  // Set up for encoders handling
  encodersDriver = new EncodersDriver();
  
}

void loop() {
  encodersDriver->checkEncodersAction();
  // update screen
  // read inputs
  // send midi
}