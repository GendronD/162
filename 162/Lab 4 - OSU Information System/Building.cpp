/*********************************************************************
** Program name: OSU Information System
** Author: Devin Gendron
** Date: 2/4/17
** Description: Information System of OSU
*********************************************************************/
#include "Building.h"
Building::Building ()
{

}

Building::Building(std::string n, std::string a, int s) : bName(n), address(a), bSize(s)
{

}

Building::~Building()   //destructor
{

}

std::string Building::getBldgName()
{
    return bName;
}
std::string Building::getBldgAddress()
{
    return address;
}
int Building::getBldgSize()
{
    return bSize;
}