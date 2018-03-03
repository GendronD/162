/*********************************************************************
** Program name: Zoo Tycoon
** Author: Devin Gendron
** Date: 2/4/17
** Description: Zoo Tycoon Game
*********************************************************************/
#ifndef TIGERCLASS_HPP
#define TIGERCLASS_HPP
#include "animalClass.hpp"

class Tiger : public Animal
{
	private:
		const int tigerFoodMod = 5;		//tiger food modifer (5x)
		//static int tigerCounter = 0;		//counter for tiger amount

	protected:

	public:

	//constructor
	Tiger();

	Tiger(int);	//pass switch int for age

	//getters
	//int getTigerCounter();
	int getTigerFoodMod();

	//setters
	//void setTigerCounter(int n);

	//functions

};
#endif