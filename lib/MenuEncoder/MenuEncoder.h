#ifndef MENUENCODER_H
#define MENUENCODER_H

#include "EncoderExtended.h"
#include "InputDevice.h"

#include <config.h>
#include <structures.h>

	
class MenuEncoder : public EncoderExtended 
{
	public:
		MenuEncoder(ccData ccDataList[], ccData *currentCc);
		~MenuEncoder();

		void readRotary();
		int *getCcList();
		int getCurrentInput(); // probably obsolete
		ccData *getCurrentMenuData();	
		menuData **getMenuDataList();

	private:
		void doActionOnClick();

		void changeCC(int rotation);
		void changeInput(int rotation);
		void changeDisplay();

		int m_currentMode = 0; 
		int m_currentCC_idx = 0;
		int m_currentInput = 0; // obsolete
					
		menuData *p_menuDataList[NUMBER_OF_CCS]; // Collection of every field available for every CC

		ccData *p_ccDataList;
		ccData *p_currentCcData;		
		// pointer that should be passed to Driver, so when you change
		// it in here, updated version should be available in Driver (or valueencoder, not sure yet)
};
#endif