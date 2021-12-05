#include "ValueEncoder.h"  
	
ValueEncoder::ValueEncoder(menuData **menuDataList)
{
    init(VALUE_ENCODER_DT_PIN, VALUE_ENCODER_CLK_PIN, VALUE_ENCODER_SW_PIN);
    p_menuDataList = menuDataList;
    m_availableCcListLength = sizeof(p_menuDataList);

    for(int i = 0; i < m_availableCcListLength; ++i)
    {
        // this->m-mappedCclist[] = this->s_values(this->p_menuDataList[i], 63, 0); // TODO: Handle this somehow
    }

}
	
ValueEncoder::~ValueEncoder()
{
	
}

void ValueEncoder::readRotary()
{
    int rotation = readEncoderRotation();

	if(rotation)
	{
		switch(m_currentMode)
		{
			case 0: // change position
				break;
			case 1: // change range
				break;
		}	
	}	
}

void ValueEncoder::changePos(int rotation)
{
    // if( + rotation > 0)
	// {
	// 	if( + rotation < NUMBER_OF_CCS)
	// 	{
	// 		 += rotation;
	// 	}
	// }
	// if(rotation < 0)
	// {
	// 	if( + rotation >= 0)
	// 	{
	// 		 += rotation;
	// 	}
	// }
}

void ValueEncoder::changeRange(int rotation)
{
    // if(rotation > 0)
	// {
	// 	if( + rotation < NUMBER_OF_CCS)
	// 	{
	// 		 += rotation;
	// 	}
	// }
	// if(rotation < 0)
	// {
	// 	if( + rotation >= 0)
	// 	{
	// 		 += rotation;
	// 	}
	// }
}

void ValueEncoder::doActionOnClick()
{
	m_currentMode = (m_currentMode + 1) % m_numberOfModes;
}

int ValueEncoder::getValue()
{
    return {};
}