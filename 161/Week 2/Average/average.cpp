/**************************************************************
** Author: Devin Gendron
** Date : 9/28/17
** Description: Program that outputs an average of five number
**************************************************************/

#include <iostream>
#include <string>

double a, b, c, d, e , sum, average;

int main()
{
	//Ask for the five numbers
	std:: cout << "Please enter five numbers." << std:: endl;

	//Input of the five numbers
	std:: cin >> a;
	std:: cin >> b;
	std:: cin >> c;
	std:: cin >> d;
	std:: cin >> e;

	//Summation of the numbers
	sum = a + b + c + d + e;

	//averaging of the five numbers
	average = sum/5;

	//output
	std:: cout << "The average of those numbers is:" << std:: endl << average;

	return 0;
}