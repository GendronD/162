/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#include "Lair.h"
Lair::Lair(Event* a) : action(a)
{

}
void Lair::item_event()
{

}
void Lair::dialogue_event()
{
    action->dialogue_action(7);
}
void Lair::action_event()
{
    action->event_combat();
}