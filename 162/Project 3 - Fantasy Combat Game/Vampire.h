/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Devin Gendron
** Date: 2/18/17
** Description: Using dice rolls, have characters battle it out!
*********************************************************************/

#ifndef FANTASY_COMBAT_GAME_VAMPIRE_H
#define FANTASY_COMBAT_GAME_VAMPIRE_H
#include "Character.h"

class Vampire : public Character{

private:
protected:
public:
    //default constructor
    Vampire();

    //overload constructor

    //destructor
    ~Vampire();

    //functions
    void characteristics();     //characteristics
    int rollAttack();           //roll attack
    int rollDefense();          //roll defense
    void specialAbility();
};
#endif //FANTASY_COMBAT_GAME_VAMPIRE_H
