/****************************************************************************
* Author: Devin Gendron
* Date: 10/25/17
* Description: Write a class called box with three double fields in a header
****************************************************************************/
#ifndef BOX_H
#define BOX_H

//Box class declaration
class Box
{
	//private members
	private:
		//set methods
		double width;
		double height;
		double length;

	//public members
	public:
		//default constructor
		Box()
		{
			double width = 1;
			double height = 1;
			double length = 1;
		}

		//constructor with parameters
		Box (double w, double h, double l)
		{
			width = w;
			height = h;
			length = l;
		}

		//getters
		double getWidth();
		double getHeight();
		double getLength();

		//setters
		bool setWidth(double);
		bool setHeight(double);
		bool setLength(double);

		//functions
		double calcVolume();
		double calcSurfaceArea();

};
#endif