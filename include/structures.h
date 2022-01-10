#ifndef STRUCTURES_H
#define STRUCTURES_H

struct valuesData{ // Obsolete
			int *cc; // random number
			int *inputNumber;
};

struct menuData{ // TODO: clear up values and names
			int *cc; // random number
			int inputNumber = 0;
			int position = 0;
			int range = 0;
};

struct ccData{
	int cc; // random number
	int inputNumber = 0; // possibly place for pointer for InputDevice class
	int position = 0;
	int range = 0;
};

struct currentCc{
	ccData *currentCcData;
	
};

#endif