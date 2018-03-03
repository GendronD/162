/*********************************************************************
** Program name: War Game with Dice Design
** Author: Devin Gendron
** Date: 1/28/17
** Description: War game with two players using a loaded and unloaded dice.
*********************************************************************/
#ifndef LOADEDDIECLASS_HPP
#define LOADEDDIECLASS_HPP
#include "dieClass.hpp"

class LoadedDie : public Die
{
	private:

		int score = 0;

	public:

		//constructor
		LoadedDie();

		//getters
		int getScore();

		//functions
		virtual int rollDice();	//rolls dice based off of N
};
#endif