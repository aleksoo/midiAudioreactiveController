#include "MenuEncoder.h"  
	
MenuEncoder::MenuEncoder()
{
	init(MENU_ENCODER_SW_PIN, MENU_ENCODER_DT_PIN, MENU_ENCODER_CLK_PIN);
	// this->valueEncoder = new ValueEncoder(VALUE_ENCODER_SW_PIN, VALUE_ENCODER_DT_PIN, VALUE_ENCODER_CLK_PIN, this->m_CcList)
}
	
MenuEncoder::~MenuEncoder()
{
	
}

void MenuEncoder::doActionOnClick()
{
	// Cycle through available changable parameters (CC, Input)
	m_currentMode = (m_currentMode + 1) % m_numberOfModes;
}

void MenuEncoder::changeCC()
{
	// TODO: handle both incrementation and decrementation
}

void MenuEncoder::changeInput()
{
	// TODO: handle both incrementation and decrementation
	m_currentInput = (m_currentInput + 1) % NUMBER_OF_INPUT_DEVICES;
}

void MenuEncoder::changeDisplay()
{
	// No idea what to do here
}

int *MenuEncoder::getCcList()
{
	return m_ccList;
}