/****************************************************************************
* Author: Devin Gendron
* Date: 10/25/17
* Description: Taxicab .cpp implementation file 
****************************************************************************/

#include "Taxicab.hpp"
#include <iostream>
#include <string>
#include <cmath>

/********************** Create constructors *********************************/

Taxicab::Taxicab()	//: xCoord(xCoord), yCoord(yCoord), distanceTraveled(0)					//default constructor
		{
			int xCoord = 0;				//initialize default xCoord to 0
			int yCoord = 0;				//initialize default yCoord to 0
			int distanceTraveled = 0;	//use as counter - initialize to 

		}

Taxicab::Taxicab (int x, int y) : xCoord(x), yCoord(y)	//overload constructor with parameters
		{
		
		}

/**************************** getters **************************************/

int Taxicab::getXCoord ()	//Get xCoordinate
{
	return xCoord;			//Initialize x as xCoordinate
}

int Taxicab::getYCoord ()	//Get yCoordinate
{
	return yCoord;			//Initialize y as yCoordinate
}

/**************************** calculations *********************************/

void Taxicab::moveX (int xTrav)	//X method     xTrav and yTrav
{
	xCoord = xCoord + xTrav;	//Moves xCoord in desired direction
	distanceTraveled = distanceTraveled + std::abs(xTrav);	//Increment distanceTraveled like counter
	std::cout << xCoord << std::endl;
}															//use abs() for absolute distance

void Taxicab::moveY (int yTrav)	//Y method.
{
	yCoord = yCoord + yTrav;	//Moves yCoord in the desired direction
	distanceTraveled = distanceTraveled + std::abs(yTrav);	//Increment distanceTraveled like counter
	std::cout << yCoord << std::endl;
}															//use abs() for absolute distance

int Taxicab::getDistanceTraveled ()	//Return distancetraveled
{
	return distanceTraveled;	//returns distanceTraveled which has been acting as 
}								//a counter for the distance