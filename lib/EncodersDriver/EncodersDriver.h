#ifndef ENCODERSDRIVER_H
#define ENCODERSDRIVER_H

#include "MenuEncoder.h"
#include "ValueEncoder.h"

// Class for handling two encoders 
// and it's events between them

class EncodersDriver  
{
	private:
	MenuEncoder *menuEncoder;
	ValueEncoder *valueEncoder;

	public:
		EncodersDriver();
		~EncodersDriver();
};
#endif