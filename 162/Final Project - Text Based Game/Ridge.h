/*************************************************************************
** Program name: Stack and Queue STL Containers
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/

#ifndef TEXT_BASED_GAME_RIDGE_H
#define TEXT_BASED_GAME_RIDGE_H
#include "Space.h"
#include "Event.h"

class Ridge : public Space{
private:
protected:
public:
    //constructor
    Ridge()
    {

    }

    Item item_event(Item i);
    int dialogue_event(int d);
    int action_event(int a);
};


#endif //TEXT_BASED_GAME_RIDGE_H