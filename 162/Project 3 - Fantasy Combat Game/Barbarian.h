/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Devin Gendron
** Date: 2/18/17
** Description: Using dice rolls, have characters battle it out!
*********************************************************************/
#ifndef FANTASY_COMBAT_GAME_BARBARIAN_H
#define FANTASY_COMBAT_GAME_BARBARIAN_H
#include "Character.h"

class Barbarian : public Character{
private:
protected:
public:
    //default constructor
    Barbarian();

    //overload constructor

    //destructor
    ~Barbarian();

    //functions
    void characteristics();     //characteristics
    int rollAttack();           //roll attack
    int rollDefense();          //roll defense
};


#endif //FANTASY_COMBAT_GAME_BARBARIAN_H