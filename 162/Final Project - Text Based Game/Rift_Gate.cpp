/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#include "Rift_Gate.h"
Rift_Gate::Rift_Gate(Event* a) : act(a)
{

}
void Rift_Gate::item_event()
{

}
void Rift_Gate::dialogue_event()
{
    //act->dialogue_action(5);
    act->event_door();
    //if (visited)
    /*{
        std::cout << "I've already traveled this way. I should try the other paths." << std::endl;
    }
    else
    {
        act->event_door();
        visited = true;
    }*/
}
void Rift_Gate::action_event()
{

}
