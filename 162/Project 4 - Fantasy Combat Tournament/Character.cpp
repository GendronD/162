/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Devin Gendron
** Date: 3/5/18
** Description: Using dice rolls, have characters battle it out... in
** a tournament!
*********************************************************************/
#include "Character.h"
#include <iostream>
//default constructor
Character::Character()
{

}

//overload constructor

//destructor
Character::~Character()
{

}

//getters
int Character::getAttack()
{
    return attack;
}
int Character::getDefense()
{
    return defense;
}
int Character::getArmor()
{
    return armor;
}
int Character::getStrengthPoints()
{
    return strengthPoints;
}
std::string Character::getName()
{
    return name;
}
std::string Character::getType()
{
    return type;
}
void Character::setStrengthPoints(int d) //receives sum of attack - sum of defense (one number)
{
    strengthPoints = strengthPoints - d;
}

void Character::heal(int h)
{
    strengthPoints = h;
}
void Character::setName(std::string n)
{
    name = n;
}

//functions
void Character::characteristics()     //characteristics
{
    //std::cout << " " << std::endl; //prints character info
}

int Character::rollAttack()           //roll attack
{
    //std::cout << "roll atttack function not working" << std::endl;//dice rolls for attack
}
int Character::rollDefense()          //roll defense
{
    //std::cout << "roll defense function not working" << std::endl;//dice rolls for defense
}
void Character::specialAbility()
{
    //std::cout << "special ability not used" << std::endl;
}
void Character::recovery()
{
    /*int healthRec = 0;

    std::cout << "Recovering health..." << std::endl;
    healthRec = (rand() % 10 + 1);
    setStrengthPoints(strengthPoints + healthRec);
     */
}