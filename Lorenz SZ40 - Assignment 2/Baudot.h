#include <fstream>
#include <string>
using namespace std;

#include <iostream>


class Baudot
{
private:
	char tempChar;

public:
	Baudot();
	void ConvertToBaudot(char letter, int baudotValue[]);	
	char ConvertToASCII(int baudotValue[5]);	
};