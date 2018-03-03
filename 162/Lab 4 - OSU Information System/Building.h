/*********************************************************************
** Program name: OSU Information System
** Author: Devin Gendron
** Date: 2/4/17
** Description: Information System of OSU
*********************************************************************/
#ifndef OSU_INFORMATIONSYSTEM_BUILDING_H
#define OSU_INFORMATIONSYSTEM_BUILDING_H
#include <iostream>

class Building {
private:
    std::string bName = " ";
    std::string address = " ";
    int bSize = 0;
protected:
public:
    //constructors
    Building(); //default

    Building(std::string, std::string, int);   //overload

    ~Building();    //destructor

    //getters
    std::string getBldgName();
    std::string getBldgAddress();
    int getBldgSize();

    //setters

    //functions
};


#endif //OSU_INFORMATIONSYSTEM_BUILDING_H
