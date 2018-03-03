/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Devin Gendron
** Date: 2/18/17
** Description: Using dice rolls, have characters battle it out!
*********************************************************************/

#ifndef FANTASY_COMBAT_GAME_HARRYPOTTER_H
#define FANTASY_COMBAT_GAME_HARRYPOTTER_H
#include "Character.h"


class HarryPotter : public Character{
private:
    int lives = 1;
protected:
public:
    //default constructor
    HarryPotter();

    //overload constructor

    //destructor
    ~HarryPotter();

    //functions
    void characteristics();     //characteristics
    int rollAttack();           //roll attack
    int rollDefense();          //roll defense
    void specialAbility();
};


#endif //FANTASY_COMBAT_GAME_HARRYPOTTER_H
