#ifndef ENCODEREXTENDED_H
#define ENCODEREXTENDED_H
#pragma once

#include <Encoder.h>
#include <Button.h>
	
class EncoderExtended
{
	private:

		int m_pinClk;
		Button *c_button;
		Encoder *c_encoder; 

		virtual void doAction() = 0;
	public:
		
		EncoderExtended();
		void init(int pinSw, int pinDt, int pinClk);
		~EncoderExtended();
		int readButton();

};
#endif