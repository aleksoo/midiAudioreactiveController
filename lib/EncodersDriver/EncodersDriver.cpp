#include "EncodersDriver.h"  
	
EncodersDriver::EncodersDriver()
{
    for(int index = 0; index < NUMBER_OF_INPUT_DEVICES; ++index) 
    {
        inputDevices[index] = new InputDevice(inputPins[index], INPUT_TRESHOLD);
    }

    createAndMapCcList();
    
	menuEncoder = new MenuEncoder(ccList, currentCcData);
    valueEncoder = new ValueEncoder(currentCcData); // current zamiast listy?

    // valueEncoder->setCurrentCcData(menuEncoder->getCurrentMenuData());
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
    valueEncoder->readButton();
    valueEncoder->readRotary();
}

void EncodersDriver::createAndMapCcList()
{
    for(int i = 0; i < NUMBER_OF_CCS; ++i)
    {
        ccList[i].cc = MENU_CCLIST[i];
    }
    currentCcData = ccList;
}