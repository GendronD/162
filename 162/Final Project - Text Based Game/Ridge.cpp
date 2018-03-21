/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#include "Ridge.h"
Ridge::Ridge(Event* i) : it(i)
{

}
void Ridge::item_event()
{
    if(visited)
    {
        std::cout << "A Sword and a Shield! Better continue while my luck is still up!" << std::endl;
    }
    else
    {
        it->item_action(it->getItem("Shield"));
        visited = true;
    }
}
void Ridge::dialogue_event()
{

}
void Ridge::action_event()
{

}