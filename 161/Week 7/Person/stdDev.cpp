/****************************************************************************
* Author: Devin Gendron
* Date: 11/8/17
* Description: function that takes params and returns std deviation
****************************************************************************/
#include "Person.hpp"
#include <iostream>
#include <string>
#include <cmath>

/**************************** stdDev function **************************************/
double stdDev(Person personArr[], int size)
	{

/**************************** variables/declarations *******************************/
		//Person personArr[];
		double sum = 0;
		double mean = 0;
		double popVar = 0;
		double stdDevAns = 0;
		double popVarSum = 0;

/**************************** for loop for mean *************************************/
		for (int i = 0; i < size; i++)								//calculates mean age's
		{
			//std::cout << "age list: " << personArr[i].getAge() << std::endl;//prints list of age's
			sum += personArr[i].getAge();							//sum of people's ages
			mean = (sum / size);									//math for mean
		}

/**************************** mean print tests *************************************/
			//std::cout << "sum: " << sum << std::endl;				//prints sum
			//std::cout << "mean: " << mean << std::endl;				//prints mean

/************************* for loop for population variance ***********************/
		for (int i = 0; i < size; i++)
		{
			double midOfFunc;
			double centerMath;
			midOfFunc = (personArr[i].getAge() - mean);				//math for middle of func
			centerMath = pow(midOfFunc, 2);							//squares midOfFunc
			popVarSum += centerMath;								//sums to popVarSum
		}

		popVar = (popVarSum / size);							//divides by size

/**************************** pop var print tests *************************************/
			//std::cout << "popvar: " << popVar << std::endl;			//prints popVar

/************************* population variance *****************************/
			stdDevAns = sqrt(popVar);

/************************* test for std dev *************************************/
			//std::cout << "stddev: " << stdDevAns << std::endl;			//prints stdDev		

		return stdDevAns;
	}