#include "MenuEncoder.h"  
	
MenuEncoder::MenuEncoder()
{
	init(MENU_ENCODER_DT_PIN, MENU_ENCODER_CLK_PIN, MENU_ENCODER_SW_PIN);
	// this->valueEncoder = new ValueEncoder(VALUE_ENCODER_SW_PIN, VALUE_ENCODER_DT_PIN, VALUE_ENCODER_CLK_PIN, this->m_CcList)
}
	
MenuEncoder::~MenuEncoder()
{
	
}

void MenuEncoder::readRotary()
{
	int rotation = readEncoderRotation();
	Serial.print(m_currentCC);
	Serial.print(" ");
	Serial.println(m_currentCC_idx);
	if(rotation)
	{
		switch(m_currentMode)
		{
			case 0: //change CC
				Serial.println("Change CC");
				changeCC(rotation);
				break;
			case 1: //change input
				Serial.println("change Input");
				changeInput(rotation);
				break;
		}	
	}
	
}

void MenuEncoder::doActionOnClick()
{
	// Cycle through available changable parameters (CC, Input)
	m_currentMode = (m_currentMode + 1) % MENU_NUMBER_OF_MODES;
	Serial.print("New mode: ");
	Serial.println(m_currentMode);
}

void MenuEncoder::changeCC(int rotation)
{
	if(rotation > 0)
	{
		if(m_currentCC_idx + rotation < NUMBER_OF_CCS)
		{
			m_currentCC_idx += rotation;
			m_currentCC = m_ccList[m_currentCC_idx];
		}
	}
	if(rotation < 0)
	{
		if(m_currentCC_idx + rotation >= 0)
		{
			m_currentCC_idx += rotation;
			m_currentCC = m_ccList[m_currentCC_idx];
		}
	}
	// TODO: handle both incrementation and decrementation
}

void MenuEncoder::changeInput(int rotation)
{
	// TODO: handle both incrementation and decrementation
	if(rotation > 0)
	{
		if(m_currentInput + rotation < NUMBER_OF_INPUT_DEVICES)
		{
			m_currentInput += rotation;
		}
	}
	if(rotation < 0)
	{
		if(m_currentInput + rotation >= 0)
		{
			m_currentInput += rotation;
		}
	}

	Serial.print("current input: ");
}

void MenuEncoder::changeDisplay()
{
	// No idea what to do here
}

int *MenuEncoder::getCcList()
{
	return m_ccList;
}

int MenuEncoder::getCurrentInput()
{
	return m_currentInput;
}