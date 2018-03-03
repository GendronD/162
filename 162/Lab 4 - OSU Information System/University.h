/*********************************************************************
** Program name: OSU Information System
** Author: Devin Gendron
** Date: 2/4/17
** Description: Information System of OSU
*********************************************************************/
#ifndef OSU_INFORMATIONSYSTEM_UNIVERSITY_H
#define OSU_INFORMATIONSYSTEM_UNIVERSITY_H

#include "Instructor.h"
#include "Student.h"
#include "Building.h"
#include "Person.h"
#include <vector>


class University {
    private:
        std::string uniName = "Oregon State University";
        std::vector<Building*> buildings;
        std::vector<Person*> people;
    protected:
    public:
        University(); //constructor

        ~University();  //destructor

    //getters
        Building* getBuilding(std::string);    //needs arg
        Person* getPerson(int);        //needs arg
        std::string getUniName();       //returns University Name
    //setters
        void addBuilding(Building* newBuilding);
        void addPerson(Person* newPerson);


    //function
        void printBuildings();  //prints info on all the buildings (name, address, building size)
        void printPeople();     //prints info of all people (name, age, GPA, rating)    //gpa = student rating = prof


};


#endif //OSU_INFORMATIONSYSTEM_UNIVERSITY_H
