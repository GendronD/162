/****************************************************************************
* Author: Devin Gendron
* Date: 11/8/17
* Description: Person .cpp implementation file 
****************************************************************************/
#include "Person.hpp"
#include <iostream>
#include <string>

/********************** Create constructors *********************************/

Person::Person()					//default constructor
	{
		std::string name = "";	//person's name
		double age = 0;			//person's age
	}

Person::Person(std::string n, double a) : name(n), age(a)
	{

	}

/**************************** getters **************************************/

std::string Person::getName () 	//Get name
	{
		return name;			//Initialize person name
	}

double Person::getAge ()		//Gets age
	{
		return age;				//Initialize points
	}