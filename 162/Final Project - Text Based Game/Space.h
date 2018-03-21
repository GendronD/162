/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#ifndef TEXT_BASED_GAME_SPACE_H
#define TEXT_BASED_GAME_SPACE_H
#include <iostream>
//#include "Character.h"
class Character;
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

    virtual void item_event()
    {

    }
    virtual void dialogue_event()
    {

    }
    virtual void action_event()
    {

    }
};


#endif //TEXT_BASED_GAME_SPACE_H