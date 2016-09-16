#include "LorenzMachine.h"	

LorenzMachine::LorenzMachine()
{		
}

void LorenzMachine::Execute(string inputText)
{
	//This function will begin to conversion of imput text into Baudot code or decrypt it back
	cout << "Output: ";

	for(size_t i = 0; i < inputText.length(); i++)
	{			
		letterConversion.ConvertToBaudot(inputText[i],baudotValue);	//Calls the convert to Baudot function
		LorenzWheelCollection().XOR(baudotValue);//Calls the XOR to take place

		LorenzWheelCollection().wheelTurn();//And subsequently any wheels to turn
		newLetter = letterConversion.ConvertToASCII(baudotValue);//Run through to ASCII to return encrypted Char value

		cout << newLetter;	
	}
	cout << endl;
}

void LorenzMachine::Reset()
{
	//This calls to reset the wheels
	LorenzWheelCollection().Reset();//Reset function
}