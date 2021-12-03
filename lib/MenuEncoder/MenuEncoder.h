#ifndef MENUENCODER_H
#define MENUENCODER_H

#include "EncoderExtended.h"

#include "config.h"

class MenuEncoder : public EncoderExtended
{
	public:
		MenuEncoder();

		void changeCc();
		void changeInput();
		void changeDisplay();
		int *getCcList();
		int getCurrentInput(); // TODO: fill it up

	private:
		void doAction(); // TODO: change name to doActionOnClick()

		// TODO:
		// - fill CcList correctly
		// - make currentCC assigned dynamically, in constructor
		int m_ccList[2] = {120, 121}; // TODO: Add length member and handle correctly (iterating through them and returning current CC and later input)
		// TODO: every CC should contain info about its status

		int m_currentInput = 0;
		int m_currentCc = m_ccList[0]; // again, garbage value should

		int m_currentMode = 1;
		int m_numberOfModes = 2;
		// 0 - changing CC value
		// 1 - changing input
};
#endif
