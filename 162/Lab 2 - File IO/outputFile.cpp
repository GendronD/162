/*********************************************************************
** Program name: Lab2 - File I/O
** Author: Devin Gendron
** Date: 1/21/17
** Description: Program that reads a file filled with letters, count 
** the letter frequencies in the file, and write the results to a new
** file.
*********************************************************************/
#include "outputFile.hpp"
#include "inputFile.hpp"
#include <fstream>
#include <iostream>
#include <string>

void output_letters(std::ofstream &outputFile, int *arrayCounter)
{
	const int alphabetSize = 26;
			char letterEntry[] =
		{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
		'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

	for (int i = 0; i < alphabetSize; i++)
	{
		//display what is entered to file
		std::cout << letterEntry[i] << ": " << arrayCounter[i] << std::endl;
		
		//enter it to file
		outputFile << letterEntry[i] << ": " << arrayCounter[i] << std::endl;
	}
}