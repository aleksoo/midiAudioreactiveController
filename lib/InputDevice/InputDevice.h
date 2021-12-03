#ifndef INPUTDEVICE_H
#define INPUTDEVICE_H

#include <stdint.h>
#include "Arduino.h"

// Class for handling input devices
// and keeping track with them

class InputDevice
{
	public:
		InputDevice(int pin, int treshold = 500); // TODO: make default threshold in config

		void updateValues();
		int getSensorValue();

  private:
		uint8_t m_usedPin;
		int m_treshold;
		int m_sensorValue = 0; // it will change during runtime
		int m_absValue = 0; // it will change during runtime
};

#endif
