/****************************************************************************
* Author: Devin Gendron
* Date: 10/25/17
* Description: Taxicab header
****************************************************************************/
#ifndef TAXICAB_H
#define TAXICAB_H

//Taxicab class declaration
class Taxicab
{
	//private members
	private:

		//set methods
		int xCoord = 0;
		int yCoord = 0;
		int distanceTraveled = 0;

	//public members
	public:

		//default constructor
		Taxicab();

		//constructor with parameters/overload constructor
		Taxicab (int, int);

		//getters
		int getXCoord();			//Returns x coordinate
		int getYCoord();			//Returns y coordinate
		int getDistanceTraveled();

		//modifier functions
		void moveX(int);
		void moveY(int);

};
#endif