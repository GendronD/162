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
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

void count_letters(std::ifstream &inputFile, int *arrayCounter)
{
	bool endPar = true;	//checks for end of paragraph
	char ch = ' ';

	do
	{	
		ch = inputFile.get();	//read in file

		//std::cout << "entry: " << ch << std::endl;	//reads characters

		//increments character counter
		switch(ch)
		{
			case 'a' : arrayCounter[0]++;
						break;
			case 'b' : arrayCounter[1]++;
						break;
			case 'c' : arrayCounter[2]++;
						break;
			case 'd' : arrayCounter[3]++;
						break;
			case 'e' : arrayCounter[4]++;
						break;			
			case 'f' : arrayCounter[5]++;
						break;			
			case 'g' : arrayCounter[6]++;
						break;			
			case 'h' : arrayCounter[7]++;
						break;			
			case 'i' : arrayCounter[8]++;
						break;			
			case 'j' : arrayCounter[9]++;
						break;			
			case 'k' : arrayCounter[10]++;
						break;			
			case 'l' : arrayCounter[11]++;
						break;			
			case 'm' : arrayCounter[12]++;
						break;			
			case 'n' : arrayCounter[13]++;
						break;			
			case 'o' : arrayCounter[14]++;
						break;			
			case 'p' : arrayCounter[15]++;
						break;			
			case 'q' : arrayCounter[16]++;
						break;			
			case 'r' : arrayCounter[17]++;
						break;			
			case 's' : arrayCounter[18]++;
						break;			
			case 't' : arrayCounter[19]++;
						break;			
			case 'u' : arrayCounter[20]++;
						break;			
			case 'v' : arrayCounter[21]++;
						break;			
			case 'w' : arrayCounter[22]++;
						break;			
			case 'x' : arrayCounter[23]++;
						break;			
			case 'y' : arrayCounter[24]++;
						break;			
			case 'z' : arrayCounter[25]++;
						break;			
			case 'A' : arrayCounter[0]++;
						break;			
			case 'B' : arrayCounter[1]++;
						break;			
			case 'C' : arrayCounter[2]++;
						break;			
			case 'D' : arrayCounter[3]++;
						break;			
			case 'E' : arrayCounter[4]++;
						break;			
			case 'F' : arrayCounter[5]++;
						break;			
			case 'G' : arrayCounter[6]++;
						break;			
			case 'H' : arrayCounter[7]++;
						break;			
			case 'I' : arrayCounter[8]++;
						break;			
			case 'J' : arrayCounter[9]++;
						break;			
			case 'K' : arrayCounter[10]++;
						break;			
			case 'L' : arrayCounter[11]++;
						break;			
			case 'M' : arrayCounter[12]++;
						break;			
			case 'N' : arrayCounter[13]++;
						break;			
			case 'O' : arrayCounter[14]++;
						break;			
			case 'P' : arrayCounter[15]++;
						break;			
			case 'Q' : arrayCounter[16]++;
						break;			
			case 'R' : arrayCounter[17]++;
						break;			
			case 'S' : arrayCounter[18]++;
						break;			
			case 'T' : arrayCounter[19]++;
						break;			
			case 'U' : arrayCounter[20]++;
						break;			
			case 'V' : arrayCounter[21]++;
						break;			
			case 'W' : arrayCounter[22]++;
						break;			
			case 'X' : arrayCounter[23]++;
						break;			
			case 'Y' : arrayCounter[24]++;
						break;			
			case 'Z' : arrayCounter[25]++;
						break;			
			case '\n' : endPar = false;	//end of file
						inputFile.ignore();	//remove endline
						break;
			case '\r' : endPar = false;	//end of file
						inputFile.ignore();	//remove endline
						break;
		}
		if (inputFile.eof())	//if file ends, exit loop
		{
			endPar = false;
		}
	}
	while (endPar != false);
}