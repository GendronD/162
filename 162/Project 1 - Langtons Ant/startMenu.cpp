/*********************************************************************
** Program name: Langton's Ant - Project 1
** Author: Devin Gendron
** Date: 1/21/17
** Description: Creates a simulation of Langton's Ant
*********************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include "startMenu.hpp"
#include "inputValidation.hpp"

int startMenu()
{
	int menuC = 0;

	//menu
	std::cout << "Langton's Ant" << std::endl;
	std::cout << "Please choose one of the following options" << std::endl;
	std::cout << "1. Start Langton's Ant Simulation" << std::endl;
	std::cout << "2. Quit" << std::endl;

	//inputValidation();
	menuC = inputValidation();

	return menuC;
}
