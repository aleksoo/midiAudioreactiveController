#ifndef INPUTDEVICE_H
#define INPUTDEVICE_H
#pragma once

#include <stdint.h>
#include "Arduino.h"

// Class for handling input devices
// and keeping track with them

class InputDevice  
{
  	private:
		uint8_t usedPin;
		int threshold = 0;
		int sensorValue = 0; // it will change during runtime
		int absValue = 0; // it will change during runtime

	public:

		InputDevice(int pin, int threshold = 500); // TODO: make default threshold in config
		~InputDevice();
		void updateValues();
		int getSensorValue();

};

#endif