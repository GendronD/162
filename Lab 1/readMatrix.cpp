/*********************************************************************
** Program name: Matrix Calculator
** Author: Devin Gendron
** Date: 1/14/17
** Description: A calculator that calculates the determinants of a
** 2x2 or 3x3 array using dynamic memory.
*********************************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include "readMatrix.hpp"

//readMatrix function
void readMatrix(int **matrix, int matrixSize)
{
	int exitCount = 0;
	std::cout << std::endl;
	std::cout << "readMatrix is now running" << std::endl << std::endl;

	if(matrixSize == 4) //users choice was 2x2
	{
		std::cout << "Please enter four numbers for the matrix: " << std::endl;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				do
				{
					int correctEntry = 0;
					int incorrectEntry = 0;
					std::string str = " ";
					int matrixInput = 0;
					int inputLength = str.size();

					//arrays to check string	
					char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
					
					char letterEntry[] =
					{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
					'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
					'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
					'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
					
					char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
					'{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/'};
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
						for (int n = 0; n < 23; n++)
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
						ss >> matrix[j][i];
						std::cout << "Correct Input." << std::endl;
						exitCount++;
					}
					else if (incorrectEntry > 0)
					{
						std::cout << "Incorrect Entry." << std::endl;
						std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
						exitCount = 0;
					}
				}
				while (exitCount == 0);
			}
		}
	}
	else if (matrixSize == 9) //users choice was 3x3
	{
		std::cout << "Please enter nine numbers for the matrix: " << std::endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				do
				{
					int correctEntry = 0;
					int incorrectEntry = 0;
					std::string str = " ";
					int matrixInput = 0;
					int inputLength = str.size();

					//arrays to check string	
					char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
					
					char letterEntry[] =
					{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
					'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
					'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
					'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
					
					char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
					'{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/'};
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
						for (int n = 0; n < 23; n++)
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
						ss >> matrix[j][i];
						std::cout << "Correct Input." << std::endl;
						exitCount++;
					}
					else if (incorrectEntry > 0)
					{
						std::cout << "Incorrect Entry." << std::endl;
						std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
						exitCount = 0;
					}
				}
				while (exitCount == 0);
			}
		}
	}
}