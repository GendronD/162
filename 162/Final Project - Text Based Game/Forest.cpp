/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/

#include "Forest.h"
Forest::Forest(Event* e) : di(e)
{

}
void Forest::item_event()
{

}
void Forest::dialogue_event()
{
    if (visited)
    {
        std::cout << "It's nice walking in the forest, but I should try the other paths." << std::endl;
    }
    else
    {
        di->dialogue_action(1);
        visited = true;
    }
}
void Forest::action_event()
{

}