/*************************************************************************
** Program name: Final Project - Text Based Game
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
            std::cout << "The Game Has Begun!" << std::endl;
            game_sim.simulation();
            break;
        case 2 : //quit game
            std::cout << "Game Quit." << std::endl;
            break;
        default :
            break;
    }
    return 0;
}