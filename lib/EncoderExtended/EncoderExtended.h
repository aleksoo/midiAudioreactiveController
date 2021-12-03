#ifndef ENCODEREXTENDED_H
#define ENCODEREXTENDED_H

#include <Encoder.h>
#include <Button.h>

class EncoderExtended
{
public:
  EncoderExtended() = default;
  EncoderExtended(const EncoderExtended &rhs);
  EncoderExtended &operator=(const EncoderExtended &rhs);
  virtual ~EncoderExtended();

  void init(int pinSw, int pinDt, int pinClk);
  int readButton();

private:
  virtual void doAction() = 0;

  int m_pinClk;
  Button *m_button;
  Encoder *m_encoder;
};
#endif
