/*************************************************************************
** Program name: Stack and Queue STL Containers
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
protected:
public:
    //constructor
    Mountain_Pass()
    {

    }

    Item item_event(Item i);
    int dialogue_event(int d);
    int action_event(int a);
};


#endif //TEXT_BASED_GAME_MOUNTAIN_PASS_H
