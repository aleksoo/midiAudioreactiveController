#ifndef MENUENCODER_H
#define MENUENCODER_H

#include "EncoderExtended.h"

#include <config.h>
#include <structures.h>

	
class MenuEncoder : public EncoderExtended 
{
	public:
		MenuEncoder();
		~MenuEncoder();

		void readRotary();
		int *getCcList();
		int getCurrentInput(); // probably obsolete
		menuData *getCurrentMenuData();	
		menuData **getMenuDataList();

	private:
		void doActionOnClick();

		void changeCC(int rotation);
		void changeInput(int rotation);
		void changeDisplay();

		int m_currentMode = 0; 

		int m_ccList[NUMBER_OF_CCS] = {120, 121, 122, 123, 124, 125, 126, 127};; // TODO: const? move out to config
		int m_currentCC = m_ccList[0]; // again, garbage value, probably obsolete
		int m_currentCC_idx = 0;

		int m_currentInput = 0; // probably obsolete
					
		menuData *p_menuDataList[NUMBER_OF_CCS];
		menuData *p_currentCC;
		// pointer that should be passed to Driver, so when you change
		// it in here, updated version should be available in Driver (or valueencoder, not sure yet)
};
#endif