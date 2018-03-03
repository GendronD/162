/*********************************************************************
** Program name: Matrix Calculator
** Author: Devin Gendron
** Date: 1/14/17
** Description: A calculator that calculates the determinants of a
** 2x2 or 3x3 array using dynamic memory.
*********************************************************************/
#include "determinant.hpp"
#include <iostream>

//determinant function
int determinant(int **matrix, int matrixSize)
{
	std::cout << std::endl;
	std::cout << "Determinant is now running..." << std::endl << std::endl;;

	int determinantAns = 0;

	if(matrixSize == 4) //users choice was 2x2 
		{
			determinantAns = (((matrix[0][0]) * (matrix[1][1])) - 
							 ((matrix[0][1]) * (matrix[1][0])));

			std::cout << "Determinant for 2x2 matrix calculated." << std::endl << std::endl;

			return determinantAns;
		}
	if (matrixSize == 9) //users choice was 3x3
		{
			//calc determinant 3x3

			determinantAns = (matrix[0][0] * matrix[1][1] * matrix[2][2]) + 
							 (matrix[0][1] * matrix[1][2] * matrix[2][0]) +
							 (matrix[0][2] * matrix[1][0] * matrix[2][1]) -
							 (matrix[0][2] * matrix[1][1] * matrix[2][0]) -
							 (matrix[0][1] * matrix[1][0] * matrix[2][2]) -
							 (matrix[0][0] * matrix[1][2] * matrix[2][1]);

			std::cout << "Determinant for 3x3 matrix calculated." << std::endl << std::endl;

			return determinantAns;
		}
}