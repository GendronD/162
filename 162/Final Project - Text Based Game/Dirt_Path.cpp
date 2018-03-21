/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#include "Dirt_Path.h"
Dirt_Path::Dirt_Path(Event *e) : di(e)
{

}
void Dirt_Path::item_event()
{

}
void Dirt_Path::dialogue_event()
{
    if (visited)
    {
        std::cout << "This is a well worn path, I should find my own way." << std::endl;
    }
    else
    {
        di->dialogue_action(3);
        visited = true;
    }
}
void Dirt_Path::action_event()
{

}