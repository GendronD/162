/*********************************************************************
** Program name: OSU Information System
** Author: Devin Gendron
** Date: 2/4/17
** Description: Information System of OSU
*********************************************************************/
#ifndef OSU_INFORMATIONSYSTEM_INSTRUCTOR_H
#define OSU_INFORMATIONSYSTEM_INSTRUCTOR_H
#include <iostream>
#include "Person.h"

class Instructor : public Person{
    private:
        double rating = 0.00;
    protected:
    public:

    //constructor
    Instructor();  //defualt

    Instructor(std::string n, int a); //overloaded

    ~Instructor();  //destructor

    //getters
    double getRating();

    //setters
    void setRating();
    virtual void do_work();
    virtual void printInfo();
};


#endif //OSU_INFORMATIONSYSTEM_INSTRUCTOR_H
