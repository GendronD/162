/*********************************************************************
** Program name: War Game with Dice Design
** Author: Devin Gendron
** Date: 1/28/17
** Description: War game with two players using a loaded and unloaded dice.
*********************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include "gameMenu.hpp"
#include "inputValidation.hpp"

int gameMenu()
{
	int menuC = 0;

	//menu
	std::cout << "War Game with Dice Design" << std::endl;
	std::cout << "Please choose one of the following options" << std::endl;
	std::cout << "1. Play Game" << std::endl;
	std::cout << "2. Exit Game" << std::endl;

	//inputValidation();
	menuC = inputValidation();

	return menuC;
}
