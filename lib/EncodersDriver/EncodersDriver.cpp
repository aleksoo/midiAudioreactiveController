#include "EncodersDriver.h"  
	
EncodersDriver::EncodersDriver()
{
	this->menuEncoder = new MenuEncoder();
    this->valueEncoder = new ValueEncoder(this->menuEncoder->getCcList());
}
	
EncodersDriver::~EncodersDriver()
{
	
}