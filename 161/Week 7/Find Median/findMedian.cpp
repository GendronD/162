/****************************************************************************
* Author: Devin Gendron
* Date: 11/8/17
* Description: function called findMedian that takes two par as int
****************************************************************************/
//#include "findMedian.hpp"
#include <iostream>
#include <algorithm>

//func find median (two params) : array of int and the size
//func should return the median of the array (must sort) * can use built in sort function
//calc median and be prepared for odd and even groups (if function?)
		
double findMedian (int arr[], int size)		//function takes array and sets size
	{
		/************************* variables & other declarations ****************************/
		double evenMedian;							//for even length arrays
		double median;									//median variable
		int leftPar;								//left param for even median
		int rightPar;								//right param for even median
		int centerPar;								//center of odd array

		/******************************** sort the array *************************************/
		std::sort(arr, arr + size);					//puts array in ascending numeric order
		 //for (int i = 0; i < size; i++) 
     		//std::cout << arr[i] << ' ' << std::endl;//purely for testing arr is working

		/************************ if function to determine proper median *********************/
		if (size % 2 != 0)							//if odd
		{
			centerPar = (((size + 1) / 2.0) - 1.0);
			//std::cout << "centerpar: " << arr[centerPar] << ' ' << std::endl;
			median = arr[centerPar];				//finds median
			//std::cout << "median: " << median << ' ' << std::endl;

			return median;							//returns median
		}
		else										//if even
		{
			leftPar = ((size / 2) - 1);
			//std::cout << "leftpar: " << arr[leftPar] << ' ' << std::endl;
			rightPar = (size / 2);
			//std::cout << "rightpar: " << arr[rightPar] << ' ' << std::endl;
			evenMedian = ((arr[leftPar] + arr[rightPar])/2.0);	//finds even middle
			//std::cout << "evenmedian: " << evenMedian << ' ' << std::endl;

			return evenMedian;						//returns even median
		}
	}
