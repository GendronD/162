/*********************************************************************
** Program name: OSU Information System
** Author: Devin Gendron
** Date: 2/4/17
** Description: Information System of OSU
*********************************************************************/
#include "Person.h"
#include "Student.h"
#include "Instructor.h"
#include  <cstdlib>
#include <iostream>

Person::Person()   //constructor
{

}

Person::~Person()   //destructor
{

}

//getters
std::string Person::getPersonName()
{
    return name;
}
int Person::getPersonAge()
{
    return age;
}

//setters

//functions
void Person::do_work()
{
    std::cout << "no polymorphism - fix" << std::endl;
}

void Person::printInfo()
{
    "";
}