/*********************************************************************
** Program name: OSU Information System
** Author: Devin Gendron
** Date: 2/4/17
** Description: Information System of OSU
*********************************************************************/
#include <iostream>
#include "University.h"
#include "Person.h"
#include <vector>
University::University() //constructor
{

}

University::~University()    //destructor
{
    for (int i = 0; i < buildings.size(); i++)
    {
        if (buildings.at(i) != NULL)
        {
            delete buildings[i];
        }
        buildings.clear();
    }
    for (int i = 0; i < people.size(); i++)
    {
        if (people.at(i) != NULL)
        {
            delete people[i];
        }
        people.clear();
    }
}

//getters
std::string University::getUniName()
{
    return uniName;
}

Building* University::getBuilding(std::string name)    //needs arg
{
    int buildingCounter = 0;

    for (int i = 0; i < buildings.size(); i++)
    {
        if (buildings.at(i)->getBldgName() == name)
        {
            return buildings.at(i);
        }
        else
        {
            buildingCounter++;
        }
    }
    if (buildingCounter == buildings.size())
    {
        return NULL;
    }
}
Person* University::getPerson(int name)        //needs arg
{
    int personCounter = 0;

    for (int i = 0; i < people.size(); i++)
    {
        if (i + 1 == name)
        {
            return people.at(i);
        }
        else
        {
            personCounter++;
        }
    }
    if (personCounter == people.size())
        return NULL;
}
//setters
void University::addBuilding(Building* newBuilding)
{
    buildings.push_back(newBuilding);
}

void University::addPerson(Person* newPerson)
{
    people.push_back(newPerson);
}


//function
void University::printBuildings()  //prints info on all the buildings (name, address, building size)
{
    for (int i = 0; i < buildings.size(); i++)
    {
        std::cout << "Building Name: " << buildings.at(i)->getBldgName() << std::endl;
        std::cout << "Building Address: " << buildings.at(i)->getBldgAddress() << std::endl;
        std::cout << "Building Size: " << buildings.at(i)->getBldgSize() << "ft." << std::endl;
        std::cout << std::endl;

    }
}
void University::printPeople()  //prints info of all people (name, age, GPA, rating)
{
    int counter = 1;

    for (int i = 0; i < people.size(); i++)
    {
        std::cout << counter << ".";
        people.at(i)->printInfo();
        counter++;
    }
}