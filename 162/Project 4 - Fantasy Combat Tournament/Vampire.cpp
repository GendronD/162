/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Devin Gendron
** Date: 3/5/18
** Description: Using dice rolls, have characters battle it out... in
** a tournament!
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
    type = "Vampire";
}
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
    //std::cout << "Rolling for attack!..." << std::endl;
    rollOne = (rand() % 12 + 1);
    //std::cout << "Roll was: " << rollOne << std::endl;

    attack = rollOne;

    return attack;
}
int Vampire::rollDefense()          //roll defense
{
    int rollOne = 0;

    //std::cout << "Rolling for defense!..." << std::endl;
    rollOne = (rand() % 6 + 1);
    //std::cout << "Roll was: " << rollOne << std::endl;
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
        //std::cout << "Vampire used charm special ability! It dodged the attack!" << std::endl;
        defense = charm;
    }
}
void Vampire::recovery()
{
    int healthVar = 18;
    int healthRec = 0;
    int healthRange = 0;
    int hpHealed = 0;

    if(healthVar == strengthPoints)
    {
        std::cout << "No Recovery needed!" << std::endl;
    }
    else
    {
        healthRange = healthVar - strengthPoints;

        std::cout << "Recovering health..." << std::endl;
        healthRec = (rand() % healthRange + 1);
        hpHealed = strengthPoints + healthRec;
        heal(hpHealed);
        std::cout << healthRec << " recovered." << std::endl;
        if (strengthPoints == healthVar)
        {
            std::cout << "Full Recovery!!" << std::endl;
        }
        else
        {
            std::cout << "Health is now " << strengthPoints << "!" << std::endl;
        }
    }
}
