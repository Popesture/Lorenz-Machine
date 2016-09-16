#include "LorenzWheelCollection.h"

class LorenzMachine
{
private:
	int baudotValue[5];
	string inputText;
	char newLetter;
	Baudot letterConversion;

public:
	LorenzMachine();	
	void Execute(string inputText);
	void Reset();
};