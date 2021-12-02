#ifndef INPUTDEVICE_H
#define INPUTDEVICE_H

#include <stdint.h>
#include "Arduino.h"

// Class for handling input devices
// and keeping track with them

class InputDevice  
{
	public:
		InputDevice(int pin, int treshold = 500); // TODO: make default treshold in config
		~InputDevice();
		void updateValues();
		int getSensorValue();

	private:
		uint8_t usedPin;
		int treshold = 0;
		int sensorValue = 0; // it will change during runtime
		int absValue = 0; // it will change during runtime
};
#endif