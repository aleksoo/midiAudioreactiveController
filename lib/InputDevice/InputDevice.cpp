#include "InputDevice.h"  
	
InputDevice::InputDevice(int pin, int treshold)
{
	usedPin = pin;
    treshold = treshold;
    updateValues();
}
	
InputDevice::~InputDevice()
{
	
}

void InputDevice::updateValues()
{
    getSensorValue();
    absValue = abs(sensorValue - treshold);
}

int InputDevice::getSensorValue() 
{
    this->sensorValue = analogRead(this->usedPin);
    return this->sensorValue;
}