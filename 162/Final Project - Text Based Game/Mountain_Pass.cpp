/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#include "Mountain_Pass.h"
Mountain_Pass::Mountain_Pass(Event* d) : di(d)
{

}
void Mountain_Pass::item_event()
{

}
void Mountain_Pass::dialogue_event()
{
    if(visited)
    {
        std::cout << "These mountains are beautiful, but I better keep looking for that evil beast.  " << std::endl;
    }
    else
    {
        di->dialogue_action(6);
        visited = true;
    }
}
void Mountain_Pass::action_event()
{

}