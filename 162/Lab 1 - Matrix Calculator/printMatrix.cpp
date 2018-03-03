/*********************************************************************
** Program name: Matrix Calculator
** Author: Devin Gendron
** Date: 1/14/17
** Description: A calculator that calculates the determinants of a
** 2x2 or 3x3 array using dynamic memory.
*********************************************************************/
#include <iostream>
#include "printMatrix.hpp"

void printMatrix(int **matrix, int matrixSize)
{
	std::cout << std::endl;
	std::cout << "printMatrix is now running" << std::endl << std::endl;

	if(matrixSize == 4) //users choice was 2x2
	{
		int row = 2;
		int col = 2;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				std::cout << matrix[j][i] << " ";
			}
			std::cout<<std::endl;
		}
	}
	else if (matrixSize == 9) //users choice was 3x3
	{
		int row = 3;
		int col = 3;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				std::cout << matrix[j][i] << " ";
			}
			std::cout<<std::endl;
		}
	}
}