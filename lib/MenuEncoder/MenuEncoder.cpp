#include "MenuEncoder.h"  
	
MenuEncoder::MenuEncoder()
{
	this->init(MENU_ENCODER_SW_PIN, MENU_ENCODER_DT_PIN, MENU_ENCODER_CLK_PIN);
	this->m_currentCC = this->m_CcList[0];
	// this->valueEncoder = new ValueEncoder(VALUE_ENCODER_SW_PIN, VALUE_ENCODER_DT_PIN, VALUE_ENCODER_CLK_PIN, this->m_CcList)
}
	
MenuEncoder::~MenuEncoder()
{
	
}

void MenuEncoder::doAction()
{
	this->m_currentMode = (this->m_currentMode + 1) % this->m_numberOfModes;
}

void MenuEncoder::changeCC()
{
	// TODO: handle both incrementation and decrementation
}

void MenuEncoder::changeInput()
{
	// TODO: handle both incrementation and decrementation
	this->m_currentInput = (this->m_currentInput + 1) % NUMBER_OF_INPUT_DEVICES;
}

void MenuEncoder::changeDisplay()
{
	// No idea what to do here
}

int *MenuEncoder::getCcList()
{
	return this->m_CcList;
}