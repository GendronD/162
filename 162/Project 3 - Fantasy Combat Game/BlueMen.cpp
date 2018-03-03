/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Devin Gendron
** Date: 2/18/17
** Description: Using dice rolls, have characters battle it out!
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
    std::cout << "Rolling for attack!..." << std::endl;
    rollOne = (rand() % 10 + 1);
    std::cout << "First roll was: " << rollOne << std::endl;
    rollTwo = (rand() % 10 + 1);
    std::cout << "Second roll was: " << rollTwo << std::endl;
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