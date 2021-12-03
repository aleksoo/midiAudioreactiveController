#include "InputDevice.h"

InputDevice::InputDevice(int pin, int treshold) : m_usedPin(pin),
                                                  m_treshold(treshold)
{
    updateValues();
}

void InputDevice::updateValues()
{
    getSensorValue();
    m_absValue = abs(m_sensorValue - m_treshold);
}

int InputDevice::getSensorValue()
{
    m_sensorValue = analogRead(m_usedPin);
    return m_sensorValue;
}
