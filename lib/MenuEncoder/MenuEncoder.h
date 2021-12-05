#ifndef MENUENCODER_H
#define MENUENCODER_H

#include "EncoderExtended.h"

#include <config.h>
	
class MenuEncoder : public EncoderExtended 
{
	public:
		MenuEncoder();
		~MenuEncoder();

		void readRotary();
		int getCurrentInput();	
		int *getCcList();		

	private:
		void doActionOnClick();

		void changeCC(int rotation);
		void changeInput(int rotation);
		void changeDisplay();

		// TODO: 
		// - fill CcList correctly
		// - every CC should contain info about its status (somehow coordinate it with valueEncoder)
		// - make currentCC assigned dynamically, in constructor 
		int m_ccList[NUMBER_OF_CCS] = {120, 121, 122, 123, 124, 125, 126, 127};; // TODO: const?
		int m_currentCC = m_ccList[0]; // again, garbage value
		int m_currentCC_idx = 0;
					
		int m_currentInput = 0;	
		  	

		int m_currentMode = 1; // TODO: change to 0 after debugging
};
#endif