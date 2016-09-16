#include "LorenzWheelCollection.h"

LorenzWheel Psi[5]={LorenzWheel(0,43),LorenzWheel(43,47),LorenzWheel(90,51),LorenzWheel(141,53),LorenzWheel(194,59)};
LorenzWheel Mu[2]={LorenzWheel(253,37),LorenzWheel(290,61)};
LorenzWheel Chi[5]={LorenzWheel(351,41),LorenzWheel(392,31),LorenzWheel(423,29),LorenzWheel(452,26),LorenzWheel(478,23)};
//Initialisation of wheels and their pin counts/amounts

LorenzWheelCollection::LorenzWheelCollection()
{

}

void LorenzWheelCollection::XOR(int baudotValue[]) 
{
	//The XOR or exclusive or function uses values to determine is we are encoding or decoding an input then finds the opposite value
	for(int i = 0; i < 5; i++) //XOR function for each 5 pins
	{
		baudotValue[i] = (((Psi[i].getValue() + Chi[i].getValue()) %2) + baudotValue[i]) %2; 
	}   //combine Psi, Chi and current Baudot value then mod 2 to find the new Baudot value
}

void LorenzWheelCollection::wheelTurn()
{
	//This function simulates the wheel turning process inside the machine as a wheel is casued to turn
	for(int i = 0; i < 5; i++)
	{
		Chi[i].turnWheel(); // Each time [i] Chi wheel is turned check..

		if(Mu[0].getValue() == 1) //If Mu wheel value is 1
		{
			Psi[i].turnWheel(); //turn Psi wheel
		}
	}
	if(Mu[1].getValue() == 1)//If Mu wheel 1 value is 1
	{
		Mu[0].turnWheel();//turn Mu wheel 2
	}
	Mu[1].turnWheel(); //turn Mu wheel 1
}

void LorenzWheelCollection::Reset()
{
	//This function resets each wheel and the Mu wheel if it is needed
	for(int i = 0; i<5; i++)
	{
		Psi[i].Reset();//Reset each wheel values/pins
		Chi[i].Reset();		
		if(i<2)
		{
			Mu[i].Reset();
		}
	}
}
