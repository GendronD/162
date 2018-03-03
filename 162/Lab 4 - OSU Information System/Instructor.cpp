/*********************************************************************
** Program name: OSU Information System
** Author: Devin Gendron
** Date: 2/4/17
** Description: Information System of OSU
*********************************************************************/
#include "Instructor.h"
#include <cstdlib>
#include <iomanip>

Instructor::Instructor()  //defualt
{

}

Instructor::Instructor(std::string n, int a)//overloaded
{
    name = n;
    age = a;
    setRating();
}

Instructor::~Instructor()
{

}

//getters
double Instructor::getRating()
{
    return rating;
}

//setters
void Instructor::setRating()
{
    //REF::https://stackoverflow.com/questions/10776073/random-double-between-min-and-max
    double randRating = (5.00 - 0.00) * ((double)rand() / (double)RAND_MAX) + 0.00;
    rating = randRating;
}

void Instructor::do_work()
{
    getRating();
    int randHours = (rand() % 40 + 0);
    std::cout << name << " graded papers for " << randHours << " hours." << std::endl;
}

void Instructor::printInfo()
{
    std::cout << "Instructor Name: " << getPersonName() << " | ";
    std::cout << "Instructor Age: " << getPersonAge() << " | ";
    std::cout << "Instructor Rating: " << std::setprecision(2) << getRating() << std::endl;
    std::cout << std::endl;
}