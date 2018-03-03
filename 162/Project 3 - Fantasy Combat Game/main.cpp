/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Devin Gendron
** Date: 2/18/17
** Description: Using dice rolls, have characters battle it out!
*********************************************************************/
#include "Character.h"
#include "Barbarian.h"
#include "Combat.h"
#include "Menu.h"
#include "HarryPotter.h"
#include "Medusa.h"
#include "BlueMen.h"
#include "Vampire.h"
#include <iostream>

int main()
{
    srand(time(NULL));
    int menuC = 0;
    int menuChar = 0;
    int counter = 0;
    int endGame = 0;

    Combat match;
    Character *p1 = NULL;
    Character *p2 = NULL;

    menuC = menu(); //Main menu
    do {
        //menuC = menu(); //Main menu

        switch (menuC)
        {
            case 1 : //play game
                do {
                        std::cout << "*********** PLAYER " << counter + 1 << " ***********" << std::endl;
                        menuChar = charMenu(); //Character Menu

                        switch (menuChar)
                        {
                            case 1 :  //Vampire
                                if (p1 == NULL) {
                                    p1 = new Vampire();
                                    std::cout << "Player 1 Chose a Vampire!" << std::endl;
                                    p1->characteristics();
                                } else {
                                    p2 = new Vampire();
                                    std::cout << "Player 2 Chose a Vampire!" << std::endl;
                                    p2->characteristics();
                                }
                                std::cout << std::endl;
                                break;

                            case 2 :  //Barbarian
                                if (p1 == NULL) {
                                    p1 = new Barbarian();
                                    std::cout << "Player 1 Chose a Barbarian!" << std::endl;
                                    //match.setPlayer1(p1);
                                    p1->characteristics();
                                } else if(p2 == NULL){
                                    p2 = new Barbarian();
                                    std::cout << "Player 2 Chose a Barbarian!" << std::endl;
                                    //match.setPlayer2(p2);
                                    p2->characteristics();
                                }
                                std::cout << std::endl;
                                break;

                            case 3 :  //Blue Men
                                if (p1 == NULL) {
                                    p1 = new BlueMen();
                                    std::cout << "Player 1 Chose Blue Men!" << std::endl;
                                    p1->characteristics();
                                } else {
                                    p2 = new BlueMen();
                                    std::cout << "Player 2 Chose Blue Men!" << std::endl;
                                    p2->characteristics();
                                }
                                std::cout << std::endl;
                                break;

                            case 4 :  //Medusa
                                if (p1 == NULL) {
                                    p1 = new Medusa();
                                    std::cout << "Player 1 Chose Medusa!" << std::endl;
                                    p1->characteristics();
                                } else {
                                    p2 = new Medusa();
                                    std::cout << "Player 2 Chose Medusa!" << std::endl;
                                    p2->characteristics();
                                }
                                std::cout << std::endl;
                                break;

                            case 5 :  //Harry Potter
                                if (p1 == NULL) {
                                    p1 = new HarryPotter();
                                    std::cout << "Player 1 Chose Harry Potter!" << std::endl;
                                    p1->characteristics();
                                } else {
                                    p2 = new HarryPotter();
                                    std::cout << "Player 2 Chose Harry Potter!" << std::endl;
                                    p2->characteristics();
                                }
                                std::cout << std::endl;
                                break;
                        }

                        counter++;

                } while (counter != 2);
                //player game here
                match.setPlayer1(p1);
                match.setPlayer2(p2);
                match.battle();

                //game finished
                endGame = 1;
                break;

            case 2 : //quit game
                std::cout << "Game Quit." << std::endl;
                endGame = 1;
                break;
        }
        int pAM = playAgainMenu();
        switch (pAM)
        {
            case 1 : //play again
                endGame = 0;
                delete p1;
                delete p2;
                p1 = NULL;
                p2 = NULL;
                break;
            case 2 : //quit
                std::cout << "Game Quit." << std::endl;
                endGame = 1;
                break;
        }
        counter = 0;
    }while(endGame == 0);

    return 0;
}