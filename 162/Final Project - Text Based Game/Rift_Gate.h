/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/

#ifndef TEXT_BASED_GAME_RIFT_GATE_H
#define TEXT_BASED_GAME_RIFT_GATE_H
#include "Space.h"
#include "Event.h"

class Rift_Gate : public Space{
private:
    Event* act;
    bool visited = false;
protected:
public:
    //constructor
    Rift_Gate(Event*);
    //~Rift_Gate();

    void item_event();
    void dialogue_event();
    void action_event();
};


#endif //TEXT_BASED_GAME_RIFT_GATE_H
