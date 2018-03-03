/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Devin Gendron
** Date: 3/5/18
** Description: Using dice rolls, have characters battle it out... in
** a tournament!
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
    std::string type = " ";
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
    std::string getType();

    //setters
    void setStrengthPoints(int); //receives damage
    void heal(int h); //heals health
    void setName(std::string);  //sets name of char

    //functions
    virtual void characteristics();     //characteristics
    virtual int rollAttack();           //roll attack
    virtual int rollDefense();          //roll defense
    virtual void specialAbility();       //special ability
    virtual void recovery();            //recovers health after battle
};


#endif //FANTASY_COMBAT_GAME_CHARACTER_H
