#ifndef VALUEENCODER_H
#define VALUEENCODER_H

#include "EncoderExtended.h"

#include <config.h>
#include <structures.h>


class ValueEncoder : public EncoderExtended
{
	public:
		ValueEncoder(ccData *ccDataList); // TODO: change argument to structure from MenuEncoder and assign Pos and Range properly
		~ValueEncoder();
		void readRotary();

		void changePos(int rotation);
		void changeRange(int rotation);

		void doActionOnClick();
		int getValue();

		void setCurrentCcData(ccData *newValueData);


	private:
		
		// menuData **p_menuDataList;
		// int m_availableCcListLength;
		// menuData *p_currentMenuData;
		// valuesData *p_currentValuesData; // obsolete

		ccData *p_ccDataList;
		ccData *p_currentCcData;

		int m_currentMode = 0;
		int m_currentCC_idx = 0;
		int m_numberOfModes = MENU_NUMBER_OF_MODES; // valuePosition and valueRange
};
#endif