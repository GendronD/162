/*********************************************************************
** Program name: War Game with Dice Design
** Author: Devin Gendron
** Date: 1/28/17
** Description: War game with two players using a loaded and unloaded dice.
*********************************************************************/
#include "loadedDieClass.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>

//constructor
LoadedDie::LoadedDie()
{

}

int LoadedDie::getScore()
{
	return score;
}

//functions
int LoadedDie::rollDice()
{
	int rando = 0;

	for (int i = 0; i < 3; i ++)
	{
		rando = (rand() % N + 1);
		if (rando > N/2)
		{
			return rando;
		}
	}
	return rando;
}