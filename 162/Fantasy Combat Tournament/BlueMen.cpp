/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Devin Gendron
** Date: 3/5/18
** Description: Using dice rolls, have characters battle it out... in
** a tournament!
*********************************************************************/
#include "BlueMen.h"
#include <iostream>
//default constructor
BlueMen::BlueMen()
{
    //attributes
    attack = 0;             //attack
    defense = 0;            //defense
    armor = 3;              //armor
    strengthPoints = 12;    //strength
    name = "Blue Men";
    type = "Blue Men";
}

//overload constructor

//destructor
BlueMen::~BlueMen()
{

}

//functions
void BlueMen::characteristics()     //characteristics
{
    std::cout << "They are small, 6 inch tall, but fast and tough." << std::endl
            << "They are hard to hit so they can take some damage." << std::endl
            << "They can also do a LOT of damage when they crawl " << std::endl
            << "inside enemies’ armor or clothing." << std::endl;
}

int BlueMen::rollAttack()           //roll attack
{
    int rollOne = 0;
    int rollTwo = 0;
    //std::cout << "Rolling for attack!..." << std::endl;
    rollOne = (rand() % 10 + 1);
    //std::cout << "First roll was: " << rollOne << std::endl;
    rollTwo = (rand() % 10 + 1);
    //std::cout << "Second roll was: " << rollTwo << std::endl;
    attack = rollOne + rollTwo;

    return attack;
}
int BlueMen::rollDefense()          //roll defense
{
    int rollOne = 0;
    int rollTwo = 0;
    int rollThree = 0;

    if (strengthPoints > 8)
    {
        //std::cout << "The Blue Men have a full mob!" << std::endl;
        //std::cout << "Rolling for defense!..." << std::endl;
        rollOne = (rand() % 6 + 1);
        //std::cout << "Roll was: " << rollOne << std::endl;

        //std::cout << "Rolling for defense!..." << std::endl;
        rollTwo = (rand() % 6 + 1);
        //std::cout << "Roll was: " << rollTwo << std::endl;

        //std::cout << "Rolling for defense!..." << std::endl;
        rollThree = (rand() % 6 + 1);
        //std::cout << "Roll was: " << rollThree << std::endl;

        defense = rollOne + rollTwo + rollThree;
    }
    else if (strengthPoints > 4 && strengthPoints < 9)
    {
        //std::cout << "The Blue Men Mob has been weakened! Their defense is much lower!" << std::endl;
        //std::cout << "Rolling for defense!..." << std::endl;
        rollOne = (rand() % 6 + 1);
        //std::cout << "Roll was: " << rollOne << std::endl;

        //std::cout << "Rolling for defense!..." << std::endl;
        rollTwo = (rand() % 6 + 1);
        //std::cout << "Roll was: " << rollTwo << std::endl;

        defense = rollOne + rollTwo;
    }
    else if (strengthPoints < 5)
    {
        //std::cout << "The Blue Men are almost finished! Their defense is even lower!" << std::endl;
        //std::cout << "Rolling for defense!..." << std::endl;
        rollOne = (rand() % 6 + 1);
        //std::cout << "Roll was: " << rollOne << std::endl;

        defense = rollOne;
    }

    return defense;
}

void BlueMen::specialAbility()
{
    /*int rollOne = 0;
    int rollTwo = 0;
    int rollThree = 0;

    if (strengthPoints > 8)
    {
        std::cout << "The Blue Men have a full mob!" << std::endl;
        std::cout << "Rolling for defense!..." << std::endl;
        rollOne = (rand() % 6 + 1);
        std::cout << "Roll was: " << rollOne << std::endl;

        std::cout << "Rolling for defense!..." << std::endl;
        rollTwo = (rand() % 6 + 1);
        std::cout << "Roll was: " << rollTwo << std::endl;

        std::cout << "Rolling for defense!..." << std::endl;
        rollThree = (rand() % 6 + 1);
        std::cout << "Roll was: " << rollThree << std::endl;

        defense = rollOne + rollTwo + rollThree;
    }
    else if (strengthPoints > 4 && strengthPoints < 9)
    {
        std::cout << "The Blue Men Mob has been weakened! Their defense is much lower!" << std::endl;
        std::cout << "Rolling for defense!..." << std::endl;
        rollOne = (rand() % 6 + 1);
        std::cout << "Roll was: " << rollOne << std::endl;

        std::cout << "Rolling for defense!..." << std::endl;
        rollTwo = (rand() % 6 + 1);
        std::cout << "Roll was: " << rollTwo << std::endl;

        defense = rollOne + rollTwo;
    }
    else if (strengthPoints < 5)
    {
        std::cout << "The Blue Men are almost finished! Their defense is even lower!" << std::endl;
        std::cout << "Rolling for defense!..." << std::endl;
        rollOne = (rand() % 6 + 1);
        std::cout << "Roll was: " << rollOne << std::endl;

        defense = rollOne;
    }

    return defense;*/
}
void BlueMen::recovery()
{
    int healthVar = 12;
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