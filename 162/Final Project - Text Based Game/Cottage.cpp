/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#include "Cottage.h"
Cottage::Cottage(Event* e) : di(e)
{

}
void Cottage::item_event()
{

}
void Cottage::dialogue_event()
{
    if (visited)
    {
        std::cout << "No sign of Old Fortran.  Best to keep moving." << std::endl;
    }
    else
    {
        di->dialogue_action(2);
        visited = true;
    }

}
void Cottage::action_event()
{

}