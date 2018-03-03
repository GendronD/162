/*********************************************************************
** Program name: Zoo Tycoon
** Author: Devin Gendron
** Date: 2/4/17
** Description: Zoo Tycoon Game
*********************************************************************/
#ifndef TURTLECLASS_HPP
#define TURTLECLASS_HPP
#include "animalClass.hpp"

class Turtle : public Animal
{
	private:
		int turtleFoodMod = (1/2);	//turtle food modifer (0.5x)
		//static int turtleCounter = 0;		//counter for turtle amount

	protected:

	public:

	//constructor
	Turtle();

	Turtle(int);

	//getters
	int getTurtleFoodMod();
	//int getTurtleCounter();

	//setters
	//void setTurtleCounter(int n);

	//functions

};
#endif