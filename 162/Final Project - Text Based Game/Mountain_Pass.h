/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#ifndef TEXT_BASED_GAME_MOUNTAIN_PASS_H
#define TEXT_BASED_GAME_MOUNTAIN_PASS_H
#include "Space.h"
#include "Event.h"

class Mountain_Pass : public Space{
private:
    Event* di;
    bool visited = true;
protected:
public:
    //constructor
    Mountain_Pass(Event*);
    //~Mountain_Pass();

    void item_event();
    void dialogue_event();
    void action_event();
};


#endif //TEXT_BASED_GAME_MOUNTAIN_PASS_H
