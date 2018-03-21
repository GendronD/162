/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#include "Glade.h"
Glade::Glade(Event* i) : it(i)
{

}
void Glade::item_event()
{
    if (visited)
    {
        std::cout << "Can't believe I found such a nice sword here.  Better see if I can find more things!" << std::endl;
    }
    else
    {
        //std::cout << "in item giving" << std::endl;
        it->item_action(it->getItem("Sword"));
        visited = true;
    }
}
void Glade::dialogue_event()
{

}
void Glade::action_event()
{

}