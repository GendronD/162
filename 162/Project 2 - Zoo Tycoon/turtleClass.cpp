/*********************************************************************
** Program name: Zoo Tycoon
** Author: Devin Gendron
** Date: 2/4/17
** Description: Zoo Tycoon Game
*********************************************************************/
#include "turtleClass.hpp"

//constructor
Turtle::Turtle()
{
	
}

//overload with switch statement
Turtle::Turtle(int a)
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
	Animal::setBabies(10);
	Animal::setCost(100);
	Animal::setFoodCost(baseFoodCost / 2);
	Animal::setPayoff(2000);
	*/

	babies = 10;
	cost = 100;
	//foodCost = baseFoodCost / 2;
	payoff = 5;
}
//getters
/*int Turtle::getTurtleCounter()
{
	return turtleCounter;
}*/

int Turtle::getTurtleFoodMod()
{
	return turtleFoodMod;
}

//setters
/*void Turtle::setTurtleCounter(int n)
{
	switch (n)
	{
		case 1 : 
		{
			turtleCounter++;
		}
		break;

		case 2 :
		{
			turtleCounter--;
		}
		break;
	}
}*/