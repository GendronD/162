/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Devin Gendron
** Date: 2/18/17
** Description: Using dice rolls, have characters battle it out!
*********************************************************************/
#ifndef FANTASY_COMBAT_GAME_CHARACTER_H
#define FANTASY_COMBAT_GAME_CHARACTER_H
#include <iostream>


class Character {
private:
protected:
    //attributes
    int attack = 0;    //attack
    int defense = 0;    //defense
    int armor = 0;    //armor
    int strengthPoints = 0;    //strength
    std::string name = " ";
public:

    //default constructor
    Character();

    //overload constructor

    //destructor
    ~Character();

    //getters
    int getAttack();
    int getDefense();
    int getArmor();
    int getStrengthPoints();
    std::string getName();

    //setters
    void setStrengthPoints(int); //receives damage

    //functions
    virtual void characteristics();     //characteristics
    virtual int rollAttack();           //roll attack
    virtual int rollDefense();          //roll defense
    virtual void specialAbility();       //special ability
};


#endif //FANTASY_COMBAT_GAME_CHARACTER_H
