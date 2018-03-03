/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Devin Gendron
** Date: 2/18/17
** Description: Using dice rolls, have characters battle it out!
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

void Character::setStrengthPoints(int d) //receives sum of attack - sum of defense (one number)
{
    strengthPoints = strengthPoints - d;
}

//functions
void Character::characteristics()     //characteristics
{
    std::cout << " " << std::endl; //prints character info
}

int Character::rollAttack()           //roll attack
{
    std::cout << "roll atttack function not working" << std::endl;//dice rolls for attack
}
int Character::rollDefense()          //roll defense
{
    std::cout << "roll defense function not working" << std::endl;//dice rolls for defense
}
void Character::specialAbility()
{
    //std::cout << "special ability not used" << std::endl;
}