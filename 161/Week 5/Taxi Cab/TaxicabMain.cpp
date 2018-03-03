/****************************************************************************
* Author: Devin Gendron
* Date: 10/25/17
* Description: Main file for testing
****************************************************************************/

#include "Taxicab.hpp"
#include <iostream>
#include <string>

int main ()
{
	//declare taxicab object
	Taxicab cab1;
	Taxicab cab2(5, -8);
	cab1.moveX(3);
	cab1.moveY(-4);
	cab1.moveX(-1);
	std::cout << cab1.getDistanceTraveled() << std::endl;
	cab2.moveY(7);
	std::cout << cab2.getYCoord() << std::endl;

	return 0;
}