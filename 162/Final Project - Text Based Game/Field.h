/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/

#ifndef TEXT_BASED_GAME_FIELD_H
#define TEXT_BASED_GAME_FIELD_H
#include "Space.h"
#include "Event.h"

class Field : public Space{
private:
    Event* it;
    bool visited = false;
protected:
public:
    //constructor
    Field(Event*);
    //~Field();

    void item_event();
    void dialogue_event();
    void action_event();
};


#endif //TEXT_BASED_GAME_FIELD_H
