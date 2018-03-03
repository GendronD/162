/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Devin Gendron
** Date: 2/18/17
** Description: Using dice rolls, have characters battle it out!
*********************************************************************/
#include "Vampire.h"
#include <iostream>
//default constructor
Vampire::Vampire()
{
    //attributes
    attack = 0;             //attack
    defense = 0;            //defense
    armor = 1;              //armor
    strengthPoints = 18;    //strength
    name = "Vampire";
}

//overload constructor

//destructor
Vampire::~Vampire()
{

}

//functions
void Vampire::characteristics()     //characteristics
{
    std::cout << "Suave, debonair, but vicious and surprisingly resilient." << std::endl;
}

int Vampire::rollAttack()           //roll attack
{
    int rollOne = 0;
    std::cout << "Rolling for attack!..." << std::endl;
    rollOne = (rand() % 12 + 1);
    std::cout << "Roll was: " << rollOne << std::endl;

    attack = rollOne;

    return attack;
}
int Vampire::rollDefense()          //roll defense
{
    int rollOne = 0;

    std::cout << "Rolling for defense!..." << std::endl;
    rollOne = (rand() % 6 + 1);
    std::cout << "Roll was: " << rollOne << std::endl;
    if(rollOne > 3)
    {
            specialAbility();
    }
    else
    {
        defense = rollOne;
    }

    return defense;
}

void Vampire::specialAbility()
{
    int charm = 999999;
    if (strengthPoints > 0)
    {
        std::cout << "Vampire used charm special ability! It dodged the attack!" << std::endl;
        defense = charm;
    }
}
