#include "EncoderExtended.h"

EncoderExtended::EncoderExtended(const EncoderExtended &rhs) : m_pinClk(rhs.m_pinClk),
                                                               m_button(new Button(*m_button)),
                                                               m_encoder(new Encoder(*m_encoder))
{
}

EncoderExtended &EncoderExtended::operator=(const EncoderExtended &rhs)
{
    if (this != &rhs)
    {
      m_pinClk = rhs.m_pinClk;
      m_button = new Button(*m_button);
      m_encoder = new Encoder(*m_encoder);
    }
    return *this;
}

EncoderExtended::~EncoderExtended()
{
    delete m_button;
    delete m_encoder;
}

void EncoderExtended::init(int pinSw, int pinDt, int pinClk)
{
    m_encoder = new Encoder(pinSw, pinDt);
    m_button = new Button(pinClk);
    m_pinClk = pinClk;

	  Serial.print("AA");
}

int EncoderExtended::readButton()
{
    if (m_button->pressed() == Button::PRESSED)
    {
        doAction();
    }
    return 0; // TODO: to be changed
}
