/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Devin Gendron
** Date: 3/5/18
** Description: Using dice rolls, have characters battle it out... in
** a tournament!
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
    void recovery();
};


#endif //FANTASY_COMBAT_GAME_HARRYPOTTER_H
