#ifndef ENCODERSDRIVER_H
#define ENCODERSDRIVER_H

#include "MenuEncoder.h"
#include "ValueEncoder.h"

// Class for handling two encoders 
// and it's events between them

class EncodersDriver  
{
	private:
		void checkMenuEncoder();
    	void checkValueEncoder();

		menuData menu;
		valuesData values;

	public:
	
		MenuEncoder *menuEncoder; // Temporary moved to public
		ValueEncoder *valueEncoder; // Temporary moved to public
		
		EncodersDriver();
		~EncodersDriver();
		void checkEncodersAction();
};
#endif