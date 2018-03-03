/*********************************************************************
** Program name: Lab2 - File I/O
** Author: Devin Gendron
** Date: 1/21/17
** Description: Program that reads a file filled with letters, count 
** the letter frequencies in the file, and write the results to a new
** file.
*********************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "inputFile.hpp"
#include "outputFile.hpp"

int main()
{
	//virables
	std::string iFileName;
	std::string oFileName;
	std::ifstream inputFile;
	std::ofstream outputFile;
	int arrayCounter[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						   0, 0, 0, 0, 0};

	std::cout << "Please enter the file you would like to read: " << std::endl;
	std::cin >> iFileName;

	//open file
	inputFile.open(iFileName);

	if(inputFile.fail())
	{
		std::cout << "The file could not be opened." << std::endl;
		return 1;
	}
	else if(!inputFile.fail())
	{
		std::cout << iFileName << " successfully opened." << std::endl;
		while (!inputFile.eof())
		{
			std::cout << "Now reading file..." << std::endl;
			count_letters(inputFile, arrayCounter);

			std::cout << "Enter the name of this paragraph's output file: " << std::endl;
			std::cin >> oFileName;

			//open file and fill for each paragraph
			outputFile.open(oFileName);

			if(outputFile.fail())
			{
				std::cout << "The file could not be opened." << std::endl;	
				return 1;
			}
			else
			{
				std::cout << oFileName << " successfully opened." << std::endl;
				std::cout << "Now writing to file..." << std::endl;
				output_letters(outputFile, arrayCounter);
				outputFile.close();
				//reset array counter
				for (int j = 0; j < 26; j++)
				{
					arrayCounter[j] = 0;
				}
			}
		}	
		inputFile.close();
	}
	std::cout << "File read and write complete." << std::endl;
	return 0;
}