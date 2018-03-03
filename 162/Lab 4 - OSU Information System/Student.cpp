/*********************************************************************
** Program name: OSU Information System
** Author: Devin Gendron
** Date: 2/4/17
** Description: Information System of OSU
*********************************************************************/
#include "Student.h"
#include <iostream>
#include <iomanip>
Student::Student()  //defualt
{

}

Student::Student(std::string n, int a) //overloaded
{
    name = n;
    age = a;
    setGPA();
}

Student::~Student() //destructor
{

}

//getters
double Student::getGPA()
{
    return GPA;
}

//setters
void Student::setGPA()
{
    //REF::https://stackoverflow.com/questions/10776073/random-double-between-min-and-max
    double randGPA = (4.00 - 0.00) * ((double)rand() / (double)RAND_MAX) + 0.00;
    GPA = randGPA;
}

void Student::do_work()
{
    getGPA();
    int randHours = (rand() % 40 + 0);
    std::cout << name << " did " << randHours << " hours of homework." << std::endl;
}

void Student::printInfo()
{
    std::cout << "Student Name: " << getPersonName() << " | ";
    std::cout << "Student Age: " << getPersonAge() << " | ";
    std::cout << "Student GPA: " << std::setprecision(2) << getGPA() << std::endl;
}
