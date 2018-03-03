/*********************************************************************
** Program name: War Game with Dice Design
** Author: Devin Gendron
** Date: 1/28/17
** Description: War game with two players using a loaded and unloaded dice.
*********************************************************************/
#include "dieClass.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>

//constructor
Die::Die()
{

}

//getters
int Die::getN()
{
	return N;
}

int Die::getScore()
{
	return score;
}

//setters
void Die::setN(int& n)
{
	N = n;
}

void Die::setScore()
{
	score++;
}

//functions
int Die::rollDice()
{
	//randomize using range of 1-N
	return (rand() % N + 1);
}