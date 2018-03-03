/****************************************************************************
* Author: Devin Gendron
* Date: 10/25/17
* Description: Main file for testing
****************************************************************************/

#include "Box.hpp"
#include <iostream>
#include <string>

int main ()
{
	//declare box object
	Box box1;
	double box1Width, box1Height, box1Length;

	//get width, height, and length of box
	std::cout << "This program will calculate the volume and surface area of a box. " << std::endl;
	
	//width
	std::cout << "What is the width? " << std::endl;
		std::cin >> box1Width;

	//height
	std::cout << "What is the height? " << std::endl;
		std::cin >> box1Height;

	//length
	std::cout << "What is the length? " << std::endl;
		std::cin >> box1Length;

	//call member functions to set box dimensions
	//if func return = false, the argument sent was invalid/not stored

	//if function
	if (!box1.setWidth(box1Width))			//store width
		std::cout << "Invalid entry." << std::endl;
	else if (!box1.setHeight(box1Height))
		std::cout << "Invalid entry." << std::endl;
	else if (!box1.setLength(box1Length))
		std::cout << "Invalid entry." << std::endl;
	else
	{
		//call member functions to get box info displayed
		std::cout << "Data displayed here: " << std::endl;

		//width
		std::cout << "Width: " << box1.getWidth() << std::endl;

		//height
		std::cout << "Height: " << box1.getHeight() << std::endl;

		//length
		std::cout << "Length: " << box1.getLength() << std::endl;

		//volume
		std::cout << "Volume: " << box1.calcVolume() << std::endl;

		//surfacearea
		std::cout << "Surface Area: " << box1.calcSurfaceArea() << std::endl;
	}

	return 0;
}