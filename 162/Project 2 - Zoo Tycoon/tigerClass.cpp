/*********************************************************************
** Program name: Zoo Tycoon
** Author: Devin Gendron
** Date: 2/4/17
** Description: Zoo Tycoon Game
*********************************************************************/
#include "tigerClass.hpp"

//constructor
Tiger::Tiger()
{

}

//overload with switch statement
Tiger::Tiger(int a)
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
	/*
	Animal::setBabies(1);
	Animal::setCost(10000);
	Animal::setFoodCost(baseFoodCost * 5);
	Animal::setPayoff(2000);
	*/

	babies = 1;
	cost = 10000;
	//foodCost = baseFoodCost * 5;
	payoff = 2000;
}
//getters

int Tiger::getTigerFoodMod()
{
	return tigerFoodMod;
}
/*int Tiger::getTigerCounter()
{
	return tigerCounter;
}

//setters
void Tiger::setTigerCounter(int n)
{
	switch (n)
	{
		case 1 : 
		{
			tigerCounter++;
		}
		break;

		case 2 :
		{
			tigerCounter--;
		}
		break;
	}
}*/