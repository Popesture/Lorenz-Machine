#include "LorenzMachine.h"

int main()
{	
	string inputText;

	char inputChoice;

	LorenzMachine Operate;	//Initialise the Class to be used from main as Operate
	do
	{
		Operate.Reset(); //Reset function for restart
		system("CLS");//Clear screen
		cout << "Enter text to encrypt or dycrypt: " << endl;
		cout << "Input: ";		

		getline(cin, inputText, '\n');	//Read in input text through a string

		for(size_t i = 0; i < inputText.length(); i++)
		{
			inputText[i]=toupper(inputText[i]);//Converts each inputted character to upper
		}

		Operate.Execute(inputText);//Execute the machine passing the inputText string
		do{
			cout << endl << "Enter '1' to retry or '2' to close: " << endl;
			cin >> inputChoice;
			cin.ignore();
			if (inputChoice == '2')//Exit if 2 is selected
			{
				exit(2);
			}	
		}while(inputChoice != '1');	//Do while inputChoice was not equal to 1
	}while(inputChoice == '1');//Do while inputChoice equal to 1
}