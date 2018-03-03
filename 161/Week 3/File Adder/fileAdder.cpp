/**************************************************************
** Author: Devin Gendron
** Date : 10/11/17
** Description:Reads from a txt file, sums its values, and saves to sum.txt 
**************************************************************/

#include <iostream>
#include <string>
#include <fstream>

int main(){
	
	//creating a file stream object and inputting it as well as variables
	std::string fileName;		//holds file name
	std::ifstream inputFile;	//file stream object to input
	std::ofstream outputFile;	//file stream object to output
	double integers = 0;		//file double variable
	int fileSum = 0;		//sum of data in file

	//Program prints "Please enter your file name."
	std::cout << "Please enter your filename." << std::endl;
	std::cin >> fileName;	//user enters file name

	//open file
	inputFile.open(fileName);

	//Program should read out file
	if (inputFile)
	{
		while (inputFile >> integers) 	//file data converted to int data type
		{	
			fileSum += integers;	//file adds strings from file
			//inputFile.close();	//close inputfile
		}
	} else
	  {
		std::cout << "could not access file" << std::endl;
		return 0;
	  }

	//close inputfile
	inputFile.close();	
	
	//Program creates output file called sum.txt
	outputFile.open("sum.txt");

	//writing to the sum file
	if(outputFile){
		outputFile << fileSum << std::endl; 	//write to sum.txt	
		std::cout << "result written to sum.txt" << std::endl;
		outputFile.close();
	}

	return 0;
}
