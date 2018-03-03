/*********************************************************************
** Program name: Zoo Tycoon
** Author: Devin Gendron
** Date: 2/4/17
** Description: Zoo Tycoon Game
*********************************************************************/
#include "penguinClass.hpp"

//constructor
Penguin::Penguin()
{
	
}

//overload with switch statement
Penguin::Penguin(int a)
{
	switch(a)
	{
		case 1 : //add animal
			{
				age = 1;
			}
			break;

		case 2 : //baby animal
			{
				age = 0;
			}
			break;

		case 3 : //buy animal
			{
				age = 3;
			}
			break;
	}


	//polymorphism
	/*
	Animal::setBabies(5);
	Animal::setCost(1000);
	Animal::setFoodCost(baseFoodCost * 1);
	Animal::setPayoff(100);
	*/

	babies = 5;
	cost = 1000;
	//foodCost = baseFoodCost * 1;
	payoff = 100;
}

//getters
/*int Penguin::getPenguinCounter()
{
	return penguinCounter;
}*/

int Penguin::getPenguinFoodMod()
{
	return penguinFoodMod;
}

//setters
/*void Penguin::setPenguinCounter(int n)
{
	switch (n)
	{
		case 1 : 
		{
			penguinCounter++;
		}
		break;

		case 2 :
		{
			penguinCounter--;
		}
		break;
	}
}*/