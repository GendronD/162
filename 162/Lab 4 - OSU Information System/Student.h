/*********************************************************************
** Program name: OSU Information System
** Author: Devin Gendron
** Date: 2/4/17
** Description: Information System of OSU
*********************************************************************/
#ifndef OSU_INFORMATIONSYSTEM_STUDENT_H
#define OSU_INFORMATIONSYSTEM_STUDENT_H
#include "Person.h"
#include <iostream>

class Student : public Person {

    private:
        double GPA = 0.0;
    protected:
    public:

    //constructor
    Student();  //defualt

    Student(std::string n, int a); //overloaded

    ~Student(); //destructor

    //getters
    double getGPA();

    //setters
    void setGPA();
    virtual void do_work();
    virtual void printInfo();
};


#endif //OSU_INFORMATIONSYSTEM_STUDENT_H
