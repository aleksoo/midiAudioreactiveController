#include "MenuEncoder.h"  
	
MenuEncoder::MenuEncoder(ccData ccDataList[], ccData *currentCc)
{
	init(MENU_ENCODER_DT_PIN, MENU_ENCODER_CLK_PIN, MENU_ENCODER_SW_PIN);
	p_ccDataList = ccDataList;

	// p_currentCcData = currentCc;
	p_currentCcData = p_ccDataList;
	// 
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
	Serial.print("Current input: ");
	Serial.println(p_currentCcData->inputNumber);
	// update menu screen here
}

void MenuEncoder::changeCC(int rotation)
{
	if(rotation > 0)
	{
		if(m_currentCC_idx + rotation < NUMBER_OF_CCS)
		{
			m_currentCC_idx += rotation;
			p_currentCcData = &(p_ccDataList[m_currentCC_idx]);
			Serial.print("Rotation changeCC +, current CC: ");
			Serial.println(p_currentCcData->cc);
			// m_currentCC = m_ccList[m_currentCC_idx]; // obsolote probably
			// p_currentCC = p_menuDataList[m_currentCC_idx];
		}
	}
	if(rotation < 0)
	{
		if(m_currentCC_idx + rotation >= 0)
		{
			m_currentCC_idx += rotation;
			p_currentCcData = &(p_ccDataList[m_currentCC_idx]);
			Serial.print("Rotation changeCC -, current CC: ");
			Serial.println(p_currentCcData->cc);
			// m_currentCC = m_ccList[m_currentCC_idx]; // obsolote probably
			// p_currentCcData = p_menuDataList[m_currentCC_idx];
		}
	}

	// update menu screen here
}

void MenuEncoder::changeInput(int rotation)
{
	if(rotation > 0)
	{
		if(p_currentCcData->inputNumber + rotation < NUMBER_OF_INPUT_DEVICES)
		{
			m_currentInput += rotation; // obsolote probably
			p_currentCcData->inputNumber += rotation;
			Serial.print("Rotation changeInput +, current input: ");
			Serial.print(p_currentCcData->inputNumber);
			Serial.print(", current CC: ");
			Serial.println(p_currentCcData->cc);
		}
	}
	if(rotation < 0)
	{
		if(p_currentCcData->inputNumber + rotation >= 0)
		{
			m_currentInput += rotation; // obsolote probably
			p_currentCcData->inputNumber += rotation;
			Serial.print("Rotation changeInput -, current input: ");
			Serial.print(p_currentCcData->inputNumber);
			Serial.print(", current CC: ");
			Serial.println(p_currentCcData->cc);
		}
	}

	// update menu screen here
}

void MenuEncoder::changeDisplay()
{
	// No idea what to do here yet
}

int *MenuEncoder::getCcList()
{
	// return m_ccList;
}

int MenuEncoder::getCurrentInput()
{
	return p_currentCcData->inputNumber;
}

ccData *MenuEncoder::getCurrentMenuData()
{
	return p_currentCcData;
}

menuData **MenuEncoder::getMenuDataList()
{
	// return p_menuDataList;
}