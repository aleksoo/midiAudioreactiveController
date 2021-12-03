#ifndef VALUEENCODER_H
#define VALUEENCODER_H

#include "EncoderExtended.h"

#include "config.h"

class ValueEncoder : public EncoderExtended
{
  public:
		ValueEncoder(int *ccList);

		void doAction();
		int getValue();

	private:
		struct s_values
    {
			int cc = 60; // random number
			int position = 0;
			int range = 0;
		};

		int *m_availableCcList;
		int m_availableCcListLength;
		s_values *m_mappedCcList{};

		int m_currentMode{};
		int m_numberOfModes = 2; // valuePosition and valueRange
};
#endif
