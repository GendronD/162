/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Devin Gendron
** Date: 2/18/17
** Description: Using dice rolls, have characters battle it out!
*********************************************************************/
#ifndef FANTASY_COMBAT_GAME_COMBAT_H
#define FANTASY_COMBAT_GAME_COMBAT_H
#include "Character.h"
#include "Barbarian.h"
#include "Vampire.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "HarryPotter.h"


class Combat {
private:
    int round = 1;
    Character *player1;
    Character *player2;
protected:
public:
    //constructor
    Combat();

    //overloaded constructor

    //destructor
    ~Combat();

    //functions
    void setPlayer1(Character*);
    void setPlayer2(Character*);
    void battle();

};


#endif //FANTASY_COMBAT_GAME_COMBAT_H
