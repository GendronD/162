/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Devin Gendron
** Date: 2/18/17
** Description: Using dice rolls, have characters battle it out!
*********************************************************************/
#ifndef FANTASY_COMBAT_GAME_MEDUSA_H
#define FANTASY_COMBAT_GAME_MEDUSA_H
#include "Character.h"

class Medusa : public Character{
private:
protected:
public:
    //default constructor
    Medusa();

    //overload constructor

    //destructor
    ~Medusa();

    //functions
    void characteristics();     //characteristics
    int rollAttack();           //roll attack
    int rollDefense();          //roll defense
    void specialAbility();
};


#endif //FANTASY_COMBAT_GAME_MEDUSA_H
