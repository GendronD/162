/*************************************************************************
** Program name: Stack and Queue STL Containers
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#ifndef TEXT_BASED_GAME_SPACE_H
#define TEXT_BASED_GAME_SPACE_H
template <typename V>
#include <iostream>
#include "Character.h"

class Space {
private:
    Space* top;
    Space* bottom;
    Space* right;
    Space* left;
    std::string location = " ";
    Character* character;
protected:
public:
    //constructor
    Space();
    Space* getTop();
    Space* getBottom();
    Space* getRight();
    Space* getLeft();
    std::string getLocation();

    void newLocation(Space* t, Space* b, Space* r, Space* l, std::string loc, Character* ch);

    virtual Item item_event(Item i)
    {

    }
    virtual int dialogue_event(int d)
    {

    }
    virtual int action_event(int a)
    {

    }
};


#endif //TEXT_BASED_GAME_SPACE_H