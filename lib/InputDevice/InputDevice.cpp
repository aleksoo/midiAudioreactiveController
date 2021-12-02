#include "InputDevice.h"  
	
InputDevice::InputDevice(int pin, int threshold)
{
	this->usedPin = pin;
    this->threshold = threshold;
    updateValues();
}
	
InputDevice::~InputDevice()
{
	
}

void InputDevice::updateValues()
{
    getSensorValue();
    this->absValue = abs(this->sensorValue - this->threshold);
}

int InputDevice::getSensorValue() 
{
    this->sensorValue = analogRead(this->usedPin);
    return this->sensorValue;
}