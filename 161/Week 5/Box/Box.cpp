/****************************************************************************
* Author: Devin Gendron
* Date: 10/25/17
* Description: Write a class called box with three double fields in a header
****************************************************************************/

#include "Box.hpp"
#include <iostream>
#include <string>

//setters
//setup bool for width
bool Box::setWidth (double w) {
	if (w < 0)
		return false;
	else{
		width = w;
		return true;
	}
}

//setup bool for height
bool Box::setHeight (double h) {
	if (h < 0)
		return false;
	else{
		height = h;
		return true;
	}
}

//setup bool for length
bool Box::setLength (double l) {
	if (l < 0)
		return false;
	else{
		length = l;
		return true;
	}
}

//getters
//get width
double Box::getWidth ()
{
	return width;
}

//get height
double Box::getHeight ()
{
	return height;
}

//get length
double Box::getLength ()
{
	return length;
}

//calculations
//calculate volume
double Box::calcVolume ()
{
	return width * height * length;
}

//calculate surface area
double Box::calcSurfaceArea ()
{
	return 2 * (length * width + length * height + width * height);
}