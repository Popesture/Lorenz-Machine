#include "Baudot.h"

char baudotArray[32][6] = {
	{'*','0','0','0','0','0'}, {',','0','1','0','0','0'}, 
	{'-','0','0','0','1','0'}, {'.','1','1','1','1','1'},
	{'!','1','1','0','1','1'}, {'A','0','0','0','1','1'}, 
	{'B','1','1','0','0','1'}, {'C','0','1','1','1','0'}, 
	{'D','0','1','0','0','1'}, {'E','0','0','0','0','1'}, 
	{'F','0','1','1','0','1'}, {'G','1','1','0','1','0'},
	{'H','1','0','1','0','0'}, {'I','0','0','1','1','0'}, 
	{'J','0','1','0','1','1'}, {'K','0','1','1','1','1'}, 
	{'L','1','0','0','1','0'}, {'M','1','1','1','0','0'}, 
	{'N','0','1','1','0','0'}, {'O','1','1','0','0','0'}, 
	{'P','1','0','1','1','0'}, {'Q','1','0','1','1','1'},
	{'R','0','1','0','1','0'}, {'S','0','0','1','0','1'}, 
	{'T','1','0','0','0','0'}, {'U','0','0','1','1','1'}, 
	{'V','1','1','1','1','0'}, {'W','1','0','0','1','1'}, 
	{'X','1','1','1','0','1'}, {'Y','1','0','1','0','1'}, 
	{'Z','1','0','0','0','1'}, {' ','0','0','1','0','0'}};
	//Initialises array for Baudot or ITA2 code

Baudot::Baudot()
{
	tempChar = ' ';

	for(int i = 0; i < 32; i++)
	{
		for(int j = 1; j<6; j++)
		{
			baudotArray[i][j]-=48; //minus 48 from each Baudot row > row 1 to represent a 1 or a 0 instead or 48 or 49
		}
	}
}

void Baudot::ConvertToBaudot(char letter,int baudotValue[])
{
	//This function compares an input to the pinsettings file finds the conversion and then converts each pin
	for(int i = 0; i < 32; i++)
	{
		if(letter == baudotArray[i][0]) //If current character = baudotArray[i] then
		{
			for(int j = 0; j < 5; j++)//convert each pin to its needed value
			{
				baudotValue[j] = baudotArray[i][j+1]; //Set the next pin	
			}
		}
	}
}

char Baudot::ConvertToASCII(int baudotValue[5])
{	
	//This function determines the baudot values for each wheel value to return the encoded or decoded letter
	for(int i = 0; i < 32; i++)
	{
		if(baudotValue[0] == baudotArray[i][1] && baudotValue[1] == baudotArray[i][2] && 
			baudotValue[2] == baudotArray[i][3] && baudotValue[3] == baudotArray[i][4] &&
			baudotValue[4] == baudotArray[i][5])//Compares pins from encryption to Baudot or ITA2 code to produce correct character
		{
			tempChar = baudotArray[i][0]; //TempChar hold the character (encrypted or decrypted)
		}
	}
	return tempChar;//Returned to print
}


