/*****************************************************
* Author: Devin Gendron
* Date: 11/15/17
* Description: Write a void function named smallSort2 
* that takes as parameters the addresses of three int 
* variables and sorts the ints at those addresses into 
* ascending order.
*****************************************************/
#include <iostream>

//tell program to check sourcecode for this void function
//void smallSort2(int* a, int* b, int* c);

//main function
/*int main () {
	int a = 14;
	int b = -90;
	int c = 2;	

	smallSort2(&a, &b, &c);

	std::cout << a << ", " << b << ", " << c << std::endl;
}*/

//write void sort function with references to a, b, and c
void smallSort2(int* a, int* b, int* c) {

	//declare/initialize variable to hold as a place holder
	//for numbers as they are sorted from lowest to greatest
	int numberSorter = 0;

	//for loop set to loop 3 times since we have 3 integers
	for (int i = 0; i < 3; i++)

		//use if functions to sort the three int values
		//make sure if functions sort in proper order***
		//double check numberSorter switching properly

		//if a is greater than b, change a to b and b to a
		if (*a > *b) {
			numberSorter = *a;
			*a = *b;
			*b = numberSorter;
		}

		//if a is greater than c, change a to c and c to a
		if (*a > *c) {
			numberSorter = *a;
			*a = *c;
			*c = numberSorter;
		}

		//if b is greater than b, change b to c and c to b
		if (*b > *c) {
			numberSorter = *b;
			*b = *c;
			*c = numberSorter;
		}

}