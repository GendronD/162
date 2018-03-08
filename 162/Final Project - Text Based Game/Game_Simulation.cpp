/*************************************************************************
** Program name: Stack and Queue STL Containers
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#include "Game_Simulation.h"
Game_Simulation::Game_Simulation()
{
    //Character Setup
    Character* SirCodesAlot = new Character();

    //Event Setup
    Event* game_events = new Event();

    //Map locations mostly in order
    Forest* forest = new Forest();
    Glade* glade = new Glade();
    Cottage* cottage = new Cottage();
    Dirt_Path* dirt_path = new Dirt_Path();
    Field* field = new Field();
    Ridge* ridge = new Ridge();
    Rift_Gate* rift_gate = new Rift_Gate();
    Mountain_Pass* mountain_pass = new Mountain_Pass();
    Lair* lair = new Lair();

    //Allocate Maps
    //Argument Order:           Top,       Bottom,        Right,   Left,          Location,        Player
    forest->newLocation        (nullptr,   nullptr,       glade,   nullptr,       "Forest",        SirCodesAlot);
    glade->newLocation         (nullptr,   nullptr,       cottage, forest,        "Glade",         SirCodesAlot);
    cottage->newLocation       (dirt_path, rift_gate,     ridge,   glade,         "Cottage",       SirCodesAlot);
    dirt_path->newLocation     (nullptr,   cottage,       field,   nullptr,       "Dirt Path",     SirCodesAlot);
    field->newLocation         (nullptr,   ridge,         nullptr, dirt_path,     "Field",         SirCodesAlot);
    ridge->newLocation         (field,     nullptr,       nullptr, cottage,       "Ridge",         SirCodesAlot);
    rift_gate->newLocation     (cottage,   mountain_pass, nullptr, nullptr,       "Rift Gate",     SirCodesAlot);
    mountain_pass->newLocation (rift_gate, nullptr,       lair,    nullptr,       "Mountain Pass", SirCodesAlot);
    lair->newLocation          (nullptr,   nullptr,       nullptr, mountain_pass, "Lair",          SirCodesAlot);
}
void Game_Simulation::simulation()
{
    int game_over = 0;
    int user_choice = 0;

    game_events->dialogue_action(1);
    do
    {
        user_choice = char_choice();
        switch(user_choice)
        {
            case 1 : //move top
                SirCodesAlot->travel_top();
                break;
            case 2 : //move bottom
                SirCodesAlot->travel_bottom();
                break;
            case 3 : //move right
                SirCodesAlot->travel_right();
                break;
            case 4 :  //move left
                SirCodesAlot->travel_left();
                break;
        }
        game_over = 1;
    }while(game_over != 1);
}