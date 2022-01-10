#ifndef ENCODERSDRIVER_H
#define ENCODERSDRIVER_H

#include "InputDevice.h"
#include "MenuEncoder.h"
#include "ValueEncoder.h"

#include <config.h>

// Class for handling two encoders 
// and it's events between them

class EncodersDriver  
{
	private:	
		InputDevice *inputDevices; // list of input devices
		MenuEncoder *menuEncoder; // Temporary moved to public
		ValueEncoder *valueEncoder; // Temporary moved to public

		void checkMenuEncoder();
    	void checkValueEncoder();
		void createAndMapCcList(); 

		// menuData menu; // obsolete
		// valuesData values; // obsolete
		ccData ccList[NUMBER_OF_CCS]; // full list of available CCs with parameters
		ccData *currentCcData;

	public:
	
		
		EncodersDriver();
		EncodersDriver(ccData *ccDataList, ccData *currentCc);
		~EncodersDriver();
		void checkEncodersAction();
};
#endif