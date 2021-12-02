#include "EncoderExtended.h"  
	
EncoderExtended::EncoderExtended()
{

}

void EncoderExtended::init(int pinSw, int pinDt, int pinClk)      
{
    this->c_encoder = new Encoder(pinSw, pinDt);
    this->c_button = new Button(pinClk);
    this->m_pinClk = pinClk;
	Serial.print("AA");
}
	
EncoderExtended::~EncoderExtended()
{
	
}

int EncoderExtended::readButton()
{
    if(this->c_button->pressed() == Button::PRESSED)
    {
        this->doAction();
    }
    return 0; // TODO: to be changed
}