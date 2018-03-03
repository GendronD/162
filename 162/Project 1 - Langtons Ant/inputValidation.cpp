/*********************************************************************
** Program name: Langton's Ant - Project 1
** Author: Devin Gendron
** Date: 1/21/17
** Description: Creates a simulation of Langton's Ant
*********************************************************************/
#include <iostream>
#include <string>
#include <sstream>

int inputValidation()
{
	int menuChoice = 0;
	int exitCount = 0;

	//input validation loop
	do
	{
		exitCount = 0;
		while (exitCount == 0)
		{

			int correctEntry = 0;
			int incorrectEntry = 0;
			std::string str = " ";
			int matrixInput = 0;
			int inputLength = str.size();
				
			//arrays to check user input
			char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
			
			char letterEntry[] =
			{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
			'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
			'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
			
			char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
			'{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' '};
			//removed: '\', '|', ';', ':', ''',

			//reads in string 
			getline(std::cin, str);
			std::stringstream ss(str);

			//checks for empty entries
			bool badEntry = false;
			if (str.empty())
			{
				badEntry = true;
			}

			for (int t = 0; t < str.size(); t++)
			{
				//good entry
				for (int m = 0; m < 10; m++)
				{
					if (str[t] == numEntry[m])
					{							
						correctEntry ++;
					}
				}
				//bad char entry
				for (int y = 0; y < 52; y++)
				{
					if (str[t] == letterEntry[y])
					{										
						incorrectEntry ++;
					}
				}
				//bad symbol entry
				for (int n = 0; n < 24; n++)
				{
					if (str[t] == symEntry[n])
					{
						incorrectEntry ++;
					}
				}
			}
			if (badEntry == true)
			{
				std::cout << "Please enter a 1 or 2." << std::endl;
				exitCount = 0;
			}
			else if (correctEntry == str.size())
			{
				ss >> menuChoice;
				exitCount++;
			}
			else if (incorrectEntry > 0)
			{
				std::cout << "Incorrect Entry." << std::endl;
				std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
				exitCount = 0;
			}

		}

		if (menuChoice == 1 || menuChoice == 2)
		{
			exitCount = 0;
		}
		else
		{
			exitCount = 1;
			std::cout << "Incorrect entry, please choose 1 or 2." << std::endl;
		}

	}
	while (exitCount == 1);

	return menuChoice;
}