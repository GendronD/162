/****************************************************************************
* Author: Devin Gendron
* Date: 11/8/17
* Description: Person .hpp header file 
****************************************************************************/
#ifndef PERSON_H
#define PERSON_H
#include <string>

//Player class declaration
class Person
{
	//private members
	private:

		std::string name;	//person's name
		double age;			//person's age

	//public members
	public:

		//default constructor
		Person();

		//constructor with parameters/overload constructor
		Person(std::string n, double a);

		//getters
		std::string getName();	//Returns person name
		double getAge();		//Returns person age
};
#endif