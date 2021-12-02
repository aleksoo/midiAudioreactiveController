#include "EncodersDriver.h"  
	
EncodersDriver::EncodersDriver()
{
	menuEncoder = new MenuEncoder();
    valueEncoder = new ValueEncoder(menuEncoder->getCcList());
}
	
EncodersDriver::~EncodersDriver()
{
	
}