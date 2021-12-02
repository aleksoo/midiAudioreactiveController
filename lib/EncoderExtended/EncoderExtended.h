#ifndef ENCODEREXTENDED_H
#define ENCODEREXTENDED_H

#include <Encoder.h>
#include <Button.h>
	
class EncoderExtended
{
	public:
		EncoderExtended();
		~EncoderExtended();
		void init(int pinSw, int pinDt, int pinClk);
		int readButton();

	private:
		virtual void doActionOnClick() = 0;

		int m_pinClk;
		Button *c_button;
		Encoder *c_encoder;
};
#endif