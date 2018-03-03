/*********************************************************************
** Program name: OSU Information System
** Author: Devin Gendron
** Date: 2/4/17
** Description: Information System of OSU
*********************************************************************/
#ifndef OSU_INFORMATIONSYSTEM_PERSON_H
#define OSU_INFORMATIONSYSTEM_PERSON_H

#include <iostream>

class Person {
    private:
    protected:
        std::string name = " ";
        int age = 0;

    public:

    Person();   //constructor

    ~Person();  //destructor

    //getters
    std::string getPersonName();
    int getPersonAge();

    //setters

    //functions
    virtual void do_work();
    virtual void printInfo();
};


#endif //OSU_INFORMATIONSYSTEM_PERSON_H
