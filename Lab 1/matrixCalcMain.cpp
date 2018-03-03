/*********************************************************************
** Program name: Matrix Calculator
** Author: Devin Gendron
** Date: 1/14/17
** Description: A calculator that calculates the determinants of a
** 2x2 or 3x3 array using dynamic memory.
*********************************************************************/
#include "readMatrix.hpp"
#include "determinant.hpp"
#include "printMatrix.hpp"
#include <sstream>
#include <string>
#include <iostream>

int main()
{
	int menuChoice = 0;
	int matrixSize;
	int exitCount = 0;
	int* matrix = NULL;

	//menu
	std::cout << "Matrix Calculator" << std::endl;
	std::cout << "Please choose one of the following options" << std::endl;
	std::cout << "1. 2x2 Matrix" << std::endl;
	std::cout << "2. 3x3 Matrix" << std::endl;
	std::cout << "3. Exit" << std::endl;

	//input validation loop
	do
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
		'{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/'};
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
	while (exitCount == 0 && menuChoice != 1 && menuChoice != 2 && menuChoice !=3);

	if (menuChoice == 1)
	{
		matrixSize = 4;

		//2d array dynamic allocation 2x2
		int row = 2;
		int column = 2;

		int **matrix;
		matrix = new int*[row];
		for (int i = 0; i < row; i++)
		{
			matrix[i] = new int[column];
		}

		//std::cin.ignore();
		
		//fills 2x2 matrix
		readMatrix(matrix, matrixSize);

		//calculates 2x2 determinant
		int detAns = determinant(matrix, matrixSize);

		std::cout << std::endl;
		std::cout << "Determinant for 2x2 Matrix: " << detAns << std::endl;
		std::cout << std::endl;

		//display array in square form and determinanat
		printMatrix(matrix, matrixSize);

		//delete array
		for (int i = 0; i < 2; i++)
		{
			delete [] matrix[i];
		}
		delete [] matrix;
		matrix = NULL;

		std::cout << std::endl;
		std::cout << "2x2 Matrix determinant calculation completed. Program end." << std::endl;
	}
	else if (menuChoice == 2)
	{
		matrixSize = 9;

		//2d array dynamic allocation 3x3
		int row = 3;
		int column = 3;

		int **matrix;
		matrix = new int*[row];
		for (int i = 0; i < row; i++)
		{
			matrix[i] = new int[column];
		}

		//fills 3x3 matrix
		readMatrix(matrix, matrixSize);

		//calculates 3x3 determinant
		int detAns = determinant(matrix, matrixSize);

		std::cout << std::endl;
		std::cout << "Determinant for 3x3 Matrix: " << detAns << std::endl;
		std::cout << std::endl;

		//display array in square form and determinanat
		printMatrix(matrix, matrixSize);

		//delete array
		for (int i = 0; i < 3; i++)
		{
			delete [] matrix[i];
		}
		delete [] matrix;
		matrix = NULL;

		std::cout << std::endl;
		std::cout << "3x3 Matrix determinant calculation completed. Program end." << std::endl;
	}
	else if (menuChoice == 3)
	{
		std::cout << std::endl;
		std::cout << "Matrix Calculator Quit" << std::endl;
		return 0;
	}
}

