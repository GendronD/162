/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Devin Gendron
** Date: 3/5/18
** Description: Using dice rolls, have characters battle it out... in
** a tournament!
*********************************************************************/
#ifndef FANTASY_COMBAT_GAME_COMBAT_H
#define FANTASY_COMBAT_GAME_COMBAT_H
#include "Character.h"
#include "Barbarian.h"
#include "Vampire.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "HarryPotter.h"
#include "Queue.h"


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
    void setPlayer1(Queue);
    void setPlayer2(Queue);
    int battle();

};


#endif //FANTASY_COMBAT_GAME_COMBAT_H
