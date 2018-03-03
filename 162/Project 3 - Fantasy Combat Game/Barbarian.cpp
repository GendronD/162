/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Devin Gendron
** Date: 2/18/17
** Description: Using dice rolls, have characters battle it out!
*********************************************************************/
#include "Barbarian.h"
#include <iostream>
//default constructor
Barbarian::Barbarian()
{
    //attributes
    attack = 0;             //attack
    defense = 0;            //defense
    armor = 0;              //armor
    strengthPoints = 12;    //strength
    name = "Barbarian";
}

//overload constructor

//destructor
Barbarian::~Barbarian()
{

}

//functions
void Barbarian::characteristics()     //characteristics
{
    std::cout << "Think Conan or Hercules from the movies. Big sword, big muscles, bare torso." << std::endl;
}

int Barbarian::rollAttack()           //roll attack
{
    int rollOne = 0;
    int rollTwo = 0;
    std::cout << "Rolling for attack!..." << std::endl;
    rollOne = (rand() % 6 + 1);
    std::cout << "First roll was: " << rollOne << std::endl;
    rollTwo = (rand() % 6 + 1);
    std::cout << "Second roll was: " << rollTwo << std::endl;
    attack = rollOne + rollTwo;

    return attack;
}
int Barbarian::rollDefense()          //roll defense
{
    int rollOne = 0;
    int rollTwo = 0;

    std::cout << "Rolling for defense!..." << std::endl;
    rollOne = (rand() % 6 + 1);
    std::cout << "First roll was: " << rollOne << std::endl;
    rollTwo = (rand() % 6 + 1);
    std::cout << "Second roll was: " << rollTwo << std::endl;
    defense = rollOne + rollTwo;

    return defense;
}