#include "MenuEncoder.h"  
	
MenuEncoder::MenuEncoder()
{
	init(MENU_ENCODER_DT_PIN, MENU_ENCODER_CLK_PIN, MENU_ENCODER_SW_PIN);
	
	for(int i=0; i < NUMBER_OF_CCS; ++i)
	{
		p_menuDataList[i]->cc = &(m_ccList[i]);
	}
	
	p_currentCC = p_menuDataList[0];
	// this->valueEncoder = new ValueEncoder(VALUE_ENCODER_SW_PIN, VALUE_ENCODER_DT_PIN, VALUE_ENCODER_CLK_PIN, this->m_CcList)
}
	
MenuEncoder::~MenuEncoder()
{
	
}

void MenuEncoder::readRotary()
{
	int rotation = readEncoderRotation();
	if(rotation)
	{
		switch(m_currentMode)
		{
			case 0: // change CC
				changeCC(rotation);
				break;
			case 1: // change input
				changeInput(rotation);
				break;
		}	
	}	
}

void MenuEncoder::doActionOnClick()
{
	// Cycle through available changable parameters (CC, Input)
	m_currentMode = (m_currentMode + 1) % MENU_NUMBER_OF_MODES;
}

void MenuEncoder::changeCC(int rotation)
{
	if(rotation > 0)
	{
		if(m_currentCC_idx + rotation < NUMBER_OF_CCS)
		{
			m_currentCC_idx += rotation;
			m_currentCC = m_ccList[m_currentCC_idx]; // obsolote probably
			p_currentCC = p_menuDataList[m_currentCC_idx];
		}
	}
	if(rotation < 0)
	{
		if(m_currentCC_idx + rotation >= 0)
		{
			m_currentCC_idx += rotation;
			m_currentCC = m_ccList[m_currentCC_idx]; // obsolote probably
			p_currentCC = p_menuDataList[m_currentCC_idx];
		}
	}
}

void MenuEncoder::changeInput(int rotation)
{
	if(rotation > 0)
	{
		if(m_currentInput + rotation < NUMBER_OF_INPUT_DEVICES)
		{
			m_currentInput += rotation; // obsolote probably
			p_currentCC->inputNumber += rotation;
		}
	}
	if(rotation < 0)
	{
		if(m_currentInput + rotation >= 0)
		{
			m_currentInput += rotation; // obsolote probably
			p_currentCC->inputNumber += rotation;
		}
	}
}

void MenuEncoder::changeDisplay()
{
	// No idea what to do here yet
}

int *MenuEncoder::getCcList()
{
	return m_ccList;
}

int MenuEncoder::getCurrentInput()
{
	return p_currentCC->inputNumber;
}

menuData *MenuEncoder::getCurrentMenuData()
{
	return p_currentCC;
}

menuData **MenuEncoder::getMenuDataList()
{
	return p_menuDataList;
}