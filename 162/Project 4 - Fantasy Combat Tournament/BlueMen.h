/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Devin Gendron
** Date: 3/5/18
** Description: Using dice rolls, have characters battle it out... in
** a tournament!
*********************************************************************/
#ifndef FANTASY_COMBAT_GAME_BLUEMEN_H
#define FANTASY_COMBAT_GAME_BLUEMEN_H
#include "Character.h"


class BlueMen : public Character {

private:
protected:
public:
    //default constructor
    BlueMen();

    //overload constructor

    //destructor
    ~BlueMen();

    //functions
    void characteristics();     //characteristics
    int rollAttack();           //roll attack
    int rollDefense();          //roll defense
    void specialAbility();
    void recovery();
};


#endif //FANTASY_COMBAT_GAME_BLUEMEN_H
