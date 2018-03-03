/*********************************************************************
** Program name: Langton's Ant - Project 1
** Author: Devin Gendron
** Date: 1/21/17
** Description: Creates a simulation of Langton's Ant
*********************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include "promptUserMenu.hpp"
#include "inputValidation.hpp"
#include <random>
#include <cmath>
#include <map>
#include <iomanip>

int rowsB()
{
	int boardRows = 0;
	int exitCount = 0;

	//menu
	std::cout << "Langton's Ant" << std::endl;
	std::cout << "1. Please enter the number of rows for the board between 10 and 200." << std::endl;

	do
	{
		exitCount = 0;			//sets to continue while loop in do-while
		while (exitCount == 0)
		{
			int correctEntry = 0;
			int incorrectEntry = 0;
			std::string str = " ";
			int inputLength = str.size();

			//arrays to check string	
			char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
			
			char letterEntry[] =
			{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
			'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
			'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
			
			char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
			'{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' ', '-', '_', '+', '='};
			//removed: '\', '|', ';', ':', ''',

			//reads in user input
			getline(std::cin, str);
			std::stringstream ss(str);

			//checks for empty strings
			bool badEntry = false;
			if (str.empty())
			{
				badEntry = true;
			}

			//checks for proper ints or incorrect entries
			for (int t = 0; t < str.size(); t++)
			{
				for (int m = 0; m < 10; m++)
				{
					if (str[t] == numEntry[m])
					{							
						correctEntry ++;
					}
				}
				for (int y = 0; y < 52; y++)
				{
					if (str[t] == letterEntry[y])
					{										
						incorrectEntry ++;
					}
				}
				for (int n = 0; n < 28; n++)
				{
					if (str[t] == symEntry[n])
					{
						incorrectEntry ++;
					}
				}
			}
			if (badEntry == true)
			{
				std::cout << "Please enter at least one integer." << std::endl;
				exitCount = 0;
			}
			else if (correctEntry == str.size())
			{
				ss >> boardRows;
				//std::cout << "Correct Input." << std::endl;
				exitCount++;
			}
			else if (incorrectEntry > 0)
			{
				std::cout << "Incorrect Entry." << std::endl;
				std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
				exitCount = 0;
			}
		}

		if (boardRows >= 10 && boardRows <= 200)
		{
			exitCount = 0;
		}
		else
		{
			exitCount = 1;
			std::cout << "Please use proper range for board." << std::endl;
		}

	} while(exitCount == 1);

	return boardRows;
}

int colsB()
{
	int boardCols = 0;
	int exitCount = 0;

	std::cout << "2. Please enter the number of columns for the board between 10 and 200." << std::endl;
	do
	{
		exitCount = 0;
		while (exitCount == 0)
		{
			int correctEntry = 0;
			int incorrectEntry = 0;
			std::string str = " ";
			int inputLength = str.size();

			//arrays to check string	
			char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
			
			char letterEntry[] =
			{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
			'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
			'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
			
			char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
			'{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' ', '-', '_', '+', '='};
			//removed: '\', '|', ';', ':', ''',

			//reads in user input
			getline(std::cin, str);
			std::stringstream ss(str);

			//checks for empty strings
			bool badEntry = false;
			if (str.empty())
			{
				badEntry = true;
			}

			//checks for proper ints or incorrect entries
			for (int t = 0; t < str.size(); t++)
			{
				for (int m = 0; m < 10; m++)
				{
					if (str[t] == numEntry[m])
					{							
						correctEntry ++;
					}
				}
				for (int y = 0; y < 52; y++)
				{
					if (str[t] == letterEntry[y])
					{										
						incorrectEntry ++;
					}
				}
				for (int n = 0; n < 28; n++)
				{
					if (str[t] == symEntry[n])
					{
						incorrectEntry ++;
					}
				}
			}
			if (badEntry == true)
			{
				std::cout << "Please enter at least one integer." << std::endl;
				exitCount = 0;
			}
			else if (correctEntry == str.size())
			{
				ss >> boardCols;
				//std::cout << "Correct Input." << std::endl;
				exitCount++;
			}
			else if (incorrectEntry > 0)
			{
				std::cout << "Incorrect Entry." << std::endl;
				std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
				exitCount = 0;
			}
		}

		if (boardCols >= 10 && boardCols <= 200)
		{
			exitCount = 0;
		}
		else
		{
			exitCount = 1;
			std::cout << "Please use proper range for board." << std::endl;
		}

	} while(exitCount == 1);

	return boardCols;
}

int stepsAnt ()
{
	int antSteps = 0;
	int exitCount = 0;

	std::cout << "3. Please enter the number steps for the ant between 1 and 9999999." << std::endl;
		
	do
	{
		exitCount = 0 ;
		while (exitCount == 0)
		{
			int correctEntry = 0;
			int incorrectEntry = 0;
			std::string str = " ";
			int inputLength = str.size();

			//arrays to check string	
			char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
			
			char letterEntry[] =
			{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
			'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
			'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
			
			char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
			'{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' ', '-', '_', '+', '='};		//removed: '\', '|', ';', ':', ''',

			//reads in user input
			getline(std::cin, str);
			std::stringstream ss(str);

			//checks for empty strings
			bool badEntry = false;
			if (str.empty())
			{
				badEntry = true;
			}

			//checks for proper ints or incorrect entries
			for (int t = 0; t < str.size(); t++)
			{
				for (int m = 0; m < 10; m++)
				{
					if (str[t] == numEntry[m])
					{							
						correctEntry ++;
					}
				}
				for (int y = 0; y < 52; y++)
				{
					if (str[t] == letterEntry[y])
					{										
						incorrectEntry ++;
					}
				}
				for (int n = 0; n < 28; n++)
				{
					if (str[t] == symEntry[n])
					{
						incorrectEntry ++;
					}
				}
			}
			if (badEntry == true)
			{
				std::cout << "Please enter at least one integer." << std::endl;
				exitCount = 0;
			}
			else if (correctEntry == str.size())
			{
				ss >> antSteps;
				//std::cout << "Correct Input." << std::endl;
				exitCount++;
			}
			else if (incorrectEntry > 0)
			{
				std::cout << "Incorrect Entry." << std::endl;
				std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
				exitCount = 0;
			}
		}

		if (antSteps >= 1 && antSteps <= 9999999)
		{
			exitCount = 0;
		}
		else
		{
			exitCount = 1;
			std::cout << "Please use proper range for board." << std::endl;
		}
	}
	while (exitCount == 1);
	return antSteps;
}


int randomizer()
{
	int yesOrNo = 0;

	std::cout << "4. If you would like a random starting point press 1." << std::endl;
	std::cout << "If you would like to pick the starting point, press 2." << std::endl;
	
	// inputValidation();
	yesOrNo = inputValidation();

	if (yesOrNo == 1)
	{
		return 1;
	}
	else if (yesOrNo == 2)
	{
		return 2;
	}
}

int randomX(int boardRows)
{
	int antRow = 0;
	// REFERENCE:   http://en.cppreference.com/w/cpp/numeric/random
	std::random_device randomDev;							//creates seed for randomizer
	std::mt19937 ranNum(randomDev());						//random number engine
	std::uniform_int_distribution<int> uni(2, boardRows - 2);	//unbiased num
	antRow = uni(ranNum);

	return antRow;
}

int randomY(int boardCols)
{
	int antCol = 0;
	// REFERENCE:   http://en.cppreference.com/w/cpp/numeric/random
	std::random_device randomDev;							//creates seed for randomizer
	std::mt19937 ranNum(randomDev());						//random number engine
	std::uniform_int_distribution<int> uni(2, boardCols - 2);	//unbiased num
	antCol = uni(ranNum);

	return antCol;
}

int chooseX(int boardRows)	//choosing your rows
{
	int antRow = 0;
	int exitCount = 0;

	do
	{
		exitCount = 0;
		std::cout << "5.2. Please enter the starting column of the ant greater than 0 and within: " << boardRows << std::endl;
		while (exitCount == 0)
		{
			int correctEntry = 0;
			int incorrectEntry = 0;
			std::string str = " ";
			int inputLength = str.size();

			//arrays to check string	
			char numEntry[] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9'};
			
			char letterEntry[] =
			{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
			'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
			'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
			
			char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
			'{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' ', '-', '_', '+', '='};
			//removed: '\', '|', ';', ':', ''',

			//reads in user input
			getline(std::cin, str);
			std::stringstream ss(str);

			//checks for empty strings
			bool badEntry = false;
			if (str.empty())
			{
				badEntry = true;
			}

			//checks for proper ints or incorrect entries
			for (int t = 0; t < str.size(); t++)
			{
				for (int m = 0; m < 10; m++)
				{
					if (str[t] == numEntry[m])
					{							
						correctEntry ++;
					}
				}
				for (int y = 0; y < 52; y++)
				{
					if (str[t] == letterEntry[y])
					{										
						incorrectEntry ++;
					}
				}
				for (int n = 0; n < 28; n++)
				{
					if (str[t] == symEntry[n])
					{
						incorrectEntry ++;
					}
				}
			}
			if (badEntry == true)
			{
				std::cout << "Please enter at least one integer or keep entry within board" << std::endl;
				exitCount = 0;
			}
			else if (correctEntry == str.size())
			{
				ss >> antRow;

				if (antRow >= boardRows)
				{
					badEntry = true;
				}
				else
				{
					std::cout << "Correct Input." << std::endl;
					exitCount++;
				}
			}
			else if (incorrectEntry > 0)
			{
				std::cout << "Incorrect Entry." << std::endl;
				std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
				exitCount = 0;
			}

		}

		if (antRow > 0 && antRow < boardRows)	//checks range
		{
			exitCount = 0;
		}
		else
		{
			exitCount = 1;
			std::cout << "Please use proper range for board." << std::endl;
		}

	} while (exitCount == 1);

	return antRow;
}

int chooseY(int boardCols)	//choosing your columns
{
	int antCol = 0;
	int exitCount = 0;

	do
	{
		exitCount = 0;
		std::cout << "5.2. Please enter the starting column of the ant greater than 0 and within: " << boardCols << std::endl;
		while (exitCount == 0)
		{
			int correctEntry = 0;
			int incorrectEntry = 0;
			std::string str = " ";
			int inputLength = str.size();

			//arrays to check string	
			char numEntry[] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9'};
			
			char letterEntry[] =
			{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
			'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
			'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
			
			char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
			'{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' ', '-', '_', '+', '='};
			//removed: '\', '|', ';', ':', ''',

			//reads in user input
			getline(std::cin, str);
			std::stringstream ss(str);

			//checks for empty strings
			bool badEntry = false;
			if (str.empty())
			{
				badEntry = true;
			}

			//checks for proper ints or incorrect entries
			for (int t = 0; t < str.size(); t++)
			{
				for (int m = 0; m < 10; m++)
				{
					if (str[t] == numEntry[m])
					{							
						correctEntry ++;
					}
				}
				for (int y = 0; y < 52; y++)
				{
					if (str[t] == letterEntry[y])
					{										
						incorrectEntry ++;
					}
				}
				for (int n = 0; n < 28; n++)
				{
					if (str[t] == symEntry[n])
					{
						incorrectEntry ++;
					}
				}
			}
			if (badEntry == true)
			{
				std::cout << "Please enter at least one integer or keep entry within board" << std::endl;
				exitCount = 0;
			}
			else if (correctEntry == str.size())
			{
				ss >> antCol;

				if (antCol >= boardCols)
				{
					badEntry = true;
				}
				else
				{
					std::cout << "Correct Input." << std::endl;
					exitCount++;
				}
			}
			else if (incorrectEntry > 0)
			{
				std::cout << "Incorrect Entry." << std::endl;
				std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
				exitCount = 0;
			}

		}

		if (antCol > 0 && antCol < boardCols)	//checks range
		{
			exitCount = 0;
		}
		else
		{
			exitCount = 1;
			std::cout << "Please use proper range for board." << std::endl;
		}

	} while (exitCount == 1);

	return antCol;
}