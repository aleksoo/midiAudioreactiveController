#include "ValueEncoder.h"  
	
ValueEncoder::ValueEncoder(ccData *currentCcData)
{
    init(VALUE_ENCODER_DT_PIN, VALUE_ENCODER_CLK_PIN, VALUE_ENCODER_SW_PIN);
    p_currentCcData = currentCcData;
    // m_availableCcListLength = sizeof(p_menuDataList);

    // for(int i = 0; i < m_availableCcListLength; ++i)
    // {
    //     // this->m-mappedCclist[] = this->s_values(this->p_menuDataList[i], 63, 0); // TODO: Handle this somehow
    // }

}
	
ValueEncoder::~ValueEncoder()
{
	
}

void ValueEncoder::readRotary()
{
    int rotation = readEncoderRotation();

	if(rotation)
	{
		Serial.println("test");
		switch(m_currentMode)
		{
			case 0: // change position
				changePos(rotation);
				break;
			case 1: // change range
				changeRange(rotation);
				break;
		}	
	}	
}

void ValueEncoder::changePos(int rotation)
{
    if(rotation > 0)
	{
		if(p_currentCcData->position + rotation <= MAX_MIDI)
		{
			p_currentCcData->position += rotation;
			Serial.print("Rotation changePos +, current position: ");
			Serial.print(p_currentCcData->position);
			Serial.print(", current CC: ");
			Serial.println(p_currentCcData->cc);
		}
	}
	if(rotation < 0)
	{
		if(p_currentCcData->position + rotation >= MIN_MIDI)
		{
			p_currentCcData->position += rotation;
			Serial.print("Rotation changePos -, current position: ");
			Serial.print(p_currentCcData->position);
			Serial.print(", current CC: ");
			Serial.println(p_currentCcData->cc);
		}
	}
}

void ValueEncoder::changeRange(int rotation)
{
    if(rotation > 0)
	{
		if(p_currentCcData->range + rotation <= MAX_RANGE)
		{
			p_currentCcData->range += rotation;
			Serial.print("Rotation changeRange +, current range: ");
			Serial.print(p_currentCcData->range);
			Serial.print(", current CC: ");
			Serial.println(p_currentCcData->cc);
		}
	}
	if(rotation < 0)
	{
		if(p_currentCcData->range + rotation >= MIN_RANGE)
		{
			p_currentCcData->range += rotation;
			Serial.print("Rotation changeRange -, current range: ");
			Serial.print(p_currentCcData->range);
			Serial.print(", current CC: ");
			Serial.println(p_currentCcData->cc);
		}
	}
}

void ValueEncoder::doActionOnClick()
{
	m_currentMode = (m_currentMode + 1) % m_numberOfModes;
	Serial.println("Click on 2");
}

int ValueEncoder::getValue()
{
    return {};
}

void ValueEncoder::setCurrentCcData(ccData *newValueData)
{
	p_currentCcData = newValueData;
}