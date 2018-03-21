/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#ifndef TEXT_BASED_GAME_GAME_SIMULATION_H
#define TEXT_BASED_GAME_GAME_SIMULATION_H
#include "Character.h"
#include "Event.h"
#include "Space.h"
#include "Forest.h"
#include "Glade.h"
#include "Cottage.h"
#include "Dirt_Path.h"
#include "Field.h"
#include "Ridge.h"
#include "Rift_Gate.h"
#include "Mountain_Pass.h"
#include "Lair.h"
#include "Menu.h"
#include <vector>

class Game_Simulation {
private:
    //character
    Character* SirCodesAlot = nullptr;
    //events
    Event* game_events = nullptr;
    //locations
    Forest* forest = nullptr;
    Glade* glade = nullptr;
    Cottage* cottage = nullptr;
    Dirt_Path* dirt_path = nullptr;
    Field* field = nullptr;
    Ridge* ridge = nullptr;
    Rift_Gate* rift_gate = nullptr;
    Mountain_Pass* mountain_pass = nullptr;
    Lair* lair = nullptr;

protected:
public:
    //constructor
    Game_Simulation();
    //functions
    void map(Character*);
    void simulation();
};

#endif //TEXT_BASED_GAME_GAME_SIMULATION_H