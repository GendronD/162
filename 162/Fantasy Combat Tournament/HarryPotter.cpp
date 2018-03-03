/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Devin Gendron
** Date: 3/5/18
** Description: Using dice rolls, have characters battle it out... in
** a tournament!
*********************************************************************/
#include "HarryPotter.h"
#include <iostream>
//default constructor
HarryPotter::HarryPotter()
{
    //attributes
    attack = 0;             //attack
    defense = 0;            //defense
    armor = 0;              //armor
    strengthPoints = 10;    //strength
    name = "Harry Potter";
    type = "Harry Potter";
}

//overload constructor

//destructor
HarryPotter::~HarryPotter()
{

}

//functions
void HarryPotter::characteristics()     //characteristics
{
    std::cout << "Harry Potter is a wizard." << std::endl;
}

int HarryPotter::rollAttack()           //roll attack
{
    int rollOne = 0;
    int rollTwo = 0;
    //std::cout << "Rolling for attack!..." << std::endl;
    rollOne = (rand() % 6 + 1);
    //std::cout << "First roll was: " << rollOne << std::endl;
    rollTwo = (rand() % 6 + 1);
    //std::cout << "Second roll was: " << rollTwo << std::endl;
    attack = rollOne + rollTwo;

    return attack;
}
int HarryPotter::rollDefense()          //roll defense
{
    int rollOne = 0;
    int rollTwo = 0;

    //std::cout << "Rolling for defense!..." << std::endl;
    rollOne = (rand() % 6 + 1);
    //std::cout << "First roll was: " << rollOne << std::endl;
    rollTwo = (rand() % 6 + 1);
    //std::cout << "Second roll was: " << rollTwo << std::endl;
    defense = rollOne + rollTwo;

    return defense;
}

void HarryPotter::specialAbility()
{
    if (strengthPoints < 1 && lives > 0)
    {
        //std::cout << "Harry used Hogwarts to come back to life!" << std::endl;
        strengthPoints = 20;
        lives--;
    }
}
void HarryPotter::recovery()
{
    int healthVar = 10;
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