/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/

#include "Field.h"
Field::Field(Event* i) : it(i)
{

}
void Field::item_event()
{
    if(visited)
    {
        std::cout << "The field is pretty nice, I don't blame ol' Backus for coming here." << std::endl;
        std::cout << "It's getting late though, I should try other paths" << std::endl;
    }
    else
    {
        it->item_action(it->getItem("Cat"));

        it->dialogue_action(4);
        it->item_action(it->getItem("Key"));
        visited = true;
    }
}
void Field::dialogue_event()
{

}
void Field::action_event()
{

}