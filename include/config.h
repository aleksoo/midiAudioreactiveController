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
#define NUMBER_OF_INPUT_DEVICES 4
<<<<<<< HEAD
#define INPUT_TRESHOLD 500
=======
>>>>>>> cd37c83954bb78ceb4d4b6213bee9ec41721b4e9

// I made it this way, so if number of input devices does not
// match declared number of pins, compilation should fail.
static const uint8_t inputPins[NUMBER_OF_INPUT_DEVICES] = {A0, A1, A2, A3};


// MenuEncoder values
// If you are using different pins, adjust accordingly.
#define MENU_ENCODER_SW_PIN 4 // pushbutton pin
#define MENU_ENCODER_DT_PIN 5
#define MENU_ENCODER_CLK_PIN 6

// Mode 0 - change CC
// Mode 1 - change input
// Mode 3 - amplify input <- TODO
#define MENU_NUMBER_OF_MODES 2

#define NUMBER_OF_CCS 8
static const uint8_t MENU_CCLIST[NUMBER_OF_CCS] = {120, 121, 122, 123, 124, 125, 126, 127};


// Value Encoder values
// If you are using different pins, adjust accordingly.
#define VALUE_ENCODER_SW_PIN 7 // pushbutton pin
#define VALUE_ENCODER_DT_PIN 8
#define VALUE_ENCODER_CLK_PIN 9

// Mode 0 - change position
// Mode 1 - change range
// Mode 3 - Change curve? some kind of logarithm should be implemented in ValueEncoder <- TODO 
#define MENU_NUMBER_OF_MODES 2


// LCD pins
#define LCD_SDL_PIN 2
#define LCD CLK_PIN 3 // names to be changed

#endif
