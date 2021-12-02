#ifndef VALUEENCODER_H
#define VALUEENCODER_H

#include "EncoderExtended.h"

#include <config.h>

class ValueEncoder : public EncoderExtended
{
	public:
		ValueEncoder(int *ccList);
		~ValueEncoder();
		void doActionOnClick();
		int getValue();

	private:
		struct s_values{
			int cc = 60; // random number
			int position = 63; // Position of MIDI value - 0-127
			int range = 0; // Range of MIDI value - 0-127
		};
		int *m_availableCcList;
		int m_availableCcListLength;
		s_values *m_mappedCcList;

		int m_currentMode;
		int m_numberOfModes = 2; // valuePosition and valueRange
};
#endif