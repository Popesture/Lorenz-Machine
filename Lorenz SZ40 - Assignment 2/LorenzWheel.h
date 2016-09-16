#include "Baudot.h"

class LorenzWheel
{
private:
	string pinSettings;
	ifstream infile;
	int* currentPin;
	int pos;
	int size;

public:
	LorenzWheel();
	LorenzWheel(int startValue, int pinValue);

	int getValue();
	void turnWheel();

	void Reset();
};