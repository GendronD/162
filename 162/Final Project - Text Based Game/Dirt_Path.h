/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/

#ifndef TEXT_BASED_GAME_DIRT_PATH_H
#define TEXT_BASED_GAME_DIRT_PATH_H
#include "Space.h"
#include "Event.h"

class Dirt_Path : public Space{
private:
    Event* di;
    bool visited = false;
protected:
public:
    //constructor
    Dirt_Path(Event*);
    //~Dirt_Path();

    void item_event();
    void dialogue_event();
    void action_event();
};


#endif //TEXT_BASED_GAME_DIRT_PATH_H
