#ifndef VALUEENCODER_H
#define VALUEENCODER_H

#include "EncoderExtended.h"

#include <config.h>
#include <structures.h>


class ValueEncoder : public EncoderExtended
{
	public:
		ValueEncoder(menuData **ccList); // TODO: change argument to structure from MenuEncoder and assign Pos and Range properly
		~ValueEncoder();
		void readRotary();

		void changePos(int rotation);
		void changeRange(int rotation);

		void doActionOnClick();
		int getValue();


	private:
		
		menuData **p_menuDataList;
		int m_availableCcListLength;
		valuesData *p_currentValuesData;

		int m_currentMode = 0;
		int m_currentCC_idx = 0;
		int m_numberOfModes = MENU_NUMBER_OF_MODES; // valuePosition and valueRange
};
#endif