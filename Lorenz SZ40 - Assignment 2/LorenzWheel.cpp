#include "LorenzWheel.h"

LorenzWheel::LorenzWheel()
	{
	}

LorenzWheel::LorenzWheel(int startValue, int pinValue)
	{
		size = pinValue;
		currentPin = new int [size];

		string pinSettings;		
		infile.open("pinsettings.dat"); // Read in the pin settings data file.
		getline(infile,pinSettings);
		infile.close();

		for(int i = 0; i < size; i++)
		{
			currentPin[i] = pinSettings[i + startValue]; //Calculate pin setting for each key on each wheel
		}
	}

int LorenzWheel::getValue()
{
	//This function simply returns current pin position by removing 48 from the value to get a 0 or 1
	return currentPin[pos]-48; //Remove -48 from the value to get a 0 or 1
}

void LorenzWheel::turnWheel()
{
	//This resets each wheel when called upon
	pos++;
	if(pos >= size)
	{
		pos = 0; //Reset position to 0 when it is > the size
	}
}

void LorenzWheel::Reset()
{
	//Reset the wheel pos to 0
	pos=0;//On reset set positions to 0
}