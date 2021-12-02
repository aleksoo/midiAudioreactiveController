#include "ValueEncoder.h"  
	
ValueEncoder::ValueEncoder(int *ccList)
{
    init(VALUE_ENCODER_SW_PIN, VALUE_ENCODER_DT_PIN, VALUE_ENCODER_CLK_PIN);
    m_availableCcList = ccList;
    m_availableCcListLength = sizeof(m_availableCcList);

    for(int i = 0; i < m_availableCcListLength; ++i)
    {
        // this->m-mappedCclist[] = this->s_values(this->m_availableCcList[i], 63, 0); // TODO: Handle this somehow
    }

}
	
ValueEncoder::~ValueEncoder()
{
	
}

void ValueEncoder::doActionOnClick()
{
	m_currentMode = (m_currentMode + 1) % m_numberOfModes;
}

int ValueEncoder::getValue()
{
    return {};
}