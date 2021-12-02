#include "ValueEncoder.h"  
	
ValueEncoder::ValueEncoder(int *ccList)
{
    this->init(VALUE_ENCODER_SW_PIN, VALUE_ENCODER_DT_PIN, VALUE_ENCODER_CLK_PIN);
    this->m_availableCcList = ccList;
    this->m_availableCcListLength = sizeof(this->m_availableCcList);

    for(int i = 0; i < this->m_availableCcListLength; ++i)
    {
        // this->m-mappedCclist[] = this->s_values(this->m_availableCcList[i], 63, 0); // TODO: Handle this somehow
    }

}
	
ValueEncoder::~ValueEncoder()
{
	
}

void ValueEncoder::doAction()
{
	this->m_currentMode = (this->m_currentMode + 1) % this->m_numberOfModes;
}

int ValueEncoder::getValue()
{

}