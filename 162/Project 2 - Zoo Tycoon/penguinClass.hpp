/*********************************************************************
** Program name: Zoo Tycoon
** Author: Devin Gendron
** Date: 2/4/17
** Description: Zoo Tycoon Game
*********************************************************************/
#ifndef PENGUINCLASS_HPP
#define PENGUINCLASS_HPP
#include "animalClass.hpp"

class Penguin : public Animal
{
	private:
		int penguinFoodMod = 1;		//tiger food modifer (1x)
		//static int penguinCounter = 0;		//counter for penguin amount

	protected:

	public:

	//constructor
	Penguin();

	Penguin(int);

	//getters
	int getPenguinFoodMod();
	//int getPenguinCounter();

	//setters
	//void setPenguinCounter(int n);

	//functions

};
#endif