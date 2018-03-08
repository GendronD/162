/*************************************************************************
** Program name: Stack and Queue STL Containers
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#include <iostream>
#include "Menu.h"
#include "Game_Simulation.h"
int main() {
    srand(time(nullptr));
    Game_Simulation game_sim;
    int main_menu_choice = 0;

    main_menu_choice = main_menu();
    switch (main_menu_choice)
    {
        case 1 : //play game
            game_sim.simulation();
            //run game
            break;
        case 2 : //quit game
            std::cout << "Game Quit." << std::endl;
            break;
    }
    return 0;
}