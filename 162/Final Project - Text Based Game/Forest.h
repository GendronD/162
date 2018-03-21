/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/

#ifndef TEXT_BASED_GAME_FOREST_H
#define TEXT_BASED_GAME_FOREST_H
#include "Space.h"
#include "Event.h"

class Forest : public Space{
private:
    Event* di;
    bool visited = false;
protected:
public:
    //constructor
    Forest(Event*);
    //~Forest();

    void item_event();
    void dialogue_event();
    void action_event();
};


#endif //TEXT_BASED_GAME_FOREST_H
