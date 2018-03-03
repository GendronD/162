/********************************************************
* Author: Devin Gendron
* Date: 10/18/17
* Description: Hailstorm sequence - Write a function 
*named hailstone that takes the starting integer as a 
*parameter and returns how many steps it takes to reach 1
*********************************************************/
#include <iostream>



int hailstone(int posInt);
/*
int main() {

	int posInt = 5;

	hailstone(posInt);

	return 0;

}
*/

//int function
int hailstone(int posInt) {

	//declare and initialize variables
	int count = 0;

	//loop that runs hailstone sequence and counts steps
	while (posInt != 1) 
	{

		//if function to determine if integer is even or odd
		if (posInt%2 == 0) {
			//if even divide by two
			posInt /= 2;
		}

		//else if the integer is odd
		else {
			posInt *= 3;	
			posInt += 1;	
		}

		//increment counter
		count++;
	}

	//output the 
	//std::cout << count << std::endl;

	return count;
}