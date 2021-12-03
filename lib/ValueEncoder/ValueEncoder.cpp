#include "ValueEncoder.h"

ValueEncoder::ValueEncoder(int *ccList) : m_availableCcList(ccList),
                                          m_availableCcListLength(sizeof(m_availableCcList))
{
    init(VALUE_ENCODER_SW_PIN, VALUE_ENCODER_DT_PIN, VALUE_ENCODER_CLK_PIN);

    for(int i = 0; i < this->m_availableCcListLength; ++i)
    {
        // this->m-mappedCclist[] = this->s_values(this->m_availableCcList[i], 63, 0); // TODO: Handle this somehow
    }
}

void ValueEncoder::doAction()
{
	  m_currentMode = (m_currentMode + 1) % m_numberOfModes;
}

int ValueEncoder::getValue()
{
    return 0;
}
