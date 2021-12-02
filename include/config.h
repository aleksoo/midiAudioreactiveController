// Configuration file will be prettier in the future

#ifndef CONFIG_H
#define CONFIG_H

#include "Arduino.h"
#include <stdint.h>

// Input devices are meant to be KY-037 modules with a modification.
// Instead of using built-in microphone, you should remove it and replace
// it with any mono socket (RCA or jack socket).
// Additionally, add 10K resistor (brown, black, orange, gold) between
// holes you used to solder socket into.
	
// Adjust value accordingly of how many modules you are going to use
#define NUMBER_OF_INPUT_DEVICES 2

// If you are using different pins, adjust accordingly.
#define MENU_ENCODER_SW_PIN 4
#define MENU_ENCODER_DT_PIN 5
#define MENU_ENCODER_CLK_PIN 6

#define VALUE_ENCODER_SW_PIN 7
#define VALUE_ENCODER_DT_PIN 8
#define VALUE_ENCODER_CLK_PIN 9

#define LCD_SDL_PIN 2
#define LCD CLK_PIN 3 // names to be changed

// I made it this way, so if number of input devices does not
// match declared number of pins, compilation should fail.
static const uint8_t inputPins[NUMBER_OF_INPUT_DEVICES] = {A0, A1};

#endif
