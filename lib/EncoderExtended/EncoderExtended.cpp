#include "EncoderExtended.h"  
	
EncoderExtended::EncoderExtended()
{

}

void EncoderExtended::init(int pinSw, int pinDt, int pinClk)      
{
    c_encoder = new Encoder(pinSw, pinDt);
    c_button = new Button(pinClk);
    m_pinClk = pinClk;
}
	
EncoderExtended::~EncoderExtended()
{
	delete c_button;
    delete c_encoder;
}

int EncoderExtended::readButton()
{
    if(c_button->pressed() == Button::PRESSED)
    {
        doActionOnClick();
    }
    return 0; // TODO: to be changed
}