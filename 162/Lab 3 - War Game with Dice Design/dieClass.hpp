/*********************************************************************
** Program name: War Game with Dice Design
** Author: Devin Gendron
** Date: 1/28/17
** Description: War game with two players using a loaded and unloaded dice.
*********************************************************************/
#ifndef DIECLASS_HPP
#define DIECLASS_HPP

class Die
{
	private:

		int score = 0;		//score

	protected:

		int N = 0;			//number of dice sides

	public:

		//constructor
		Die();

		//getters
		int getN();			//gets number of dice sides
		int getScore();		//gets score

		//setters
		void setN(int&);		//sets number of dice sides
		void setScore();	//sets score

		//functions
		virtual int rollDice();	//rolls dice based off of N
};
#endif