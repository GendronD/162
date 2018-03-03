/**************************************************************
** Author: Devin Gendron
** Date : 10/11/17
** Description: Output the min and max of a set of numbers
**************************************************************/

#include <iostream>

int main()

{

	//initialize variables
	int num;
	int minNum = 0;
	int maxNum = 0;
	int loopCount = 1;
	int userInput;
	int minmaxMarker;

	//prompt user for input 
	std::cout << "How many integers would you like to enter? " << std::endl;
	
	//user input
	std::cin >> num;

	//prompt user for set of integers within range of their initial input
	std::cout << "Please enter " << num << " integers." << std::endl;

	//input form user
	for(loopCount = 1; loopCount <= num; loopCount++){
		
		std:: cin >> userInput;

		//begin sorting numbers to determine in min or max
		
		//if loop to check user input with minnumber conditionals
		if(userInput < minNum || minNum == 0) {
			minNum = userInput;

		}

		//if loop to check user input with minnumber conditionals
		if(userInput >= maxNum || maxNum == 0) {
			maxNum = userInput;
		}
	}

	//output min and max
	std::cout << "min: " << minNum << std::endl;
	std::cout << "max: " << maxNum << std::endl;

	return 0;
}
