#include "EncodersDriver.h"  
	
EncodersDriver::EncodersDriver()
{
	menuEncoder = new MenuEncoder();
    valueEncoder = new ValueEncoder(menuEncoder->getCcList());
}
	
EncodersDriver::~EncodersDriver()
{
	
}

void EncodersDriver::checkEncodersAction()
{
    checkMenuEncoder();
    checkValueEncoder();
}

void EncodersDriver::checkMenuEncoder()
{
    menuEncoder->readButton();
    menuEncoder->readRotary();
}

void EncodersDriver::checkValueEncoder()
{
    
}