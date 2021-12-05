#include "EncoderExtended.h"  
	
EncoderExtended::EncoderExtended()
{

}

void EncoderExtended::init(int pinSw, int pinDt, int pinClk)      
{
    c_encoder = new Encoder(pinSw, pinDt);
    c_button = new Button(pinClk);
    c_button->begin();
    m_pinClk = pinClk;
}
	
EncoderExtended::~EncoderExtended()
{
	delete c_button;
    delete c_encoder;
}

int EncoderExtended::readButton()
{
    if(c_button->pressed() == Button::RELEASED)
    {
        doActionOnClick();
    }
    return 0; // TODO: to be changed
    // tbh I don't know if I should continue
    // this approach with returning value 
    // because it works with current approach
}

int EncoderExtended::readEncoderRotation()
{

    int newPosition = c_encoder->read() / 2;
    if(newPosition > m_encoderPos) // Turning right
    {
        // Serial.println(newPosition);
        m_encoderPos = newPosition;
        return 1;
    }
    else if(newPosition < m_encoderPos) // Turning left
    {
        // Serial.println(newPosition);
        m_encoderPos = newPosition;
        return -1;
    }


    return 0;
}