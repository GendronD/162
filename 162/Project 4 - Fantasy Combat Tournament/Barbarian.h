/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Devin Gendron
** Date: 3/5/18
** Description: Using dice rolls, have characters battle it out... in
** a tournament!
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
    void recovery();
};


#endif //FANTASY_COMBAT_GAME_BARBARIAN_H