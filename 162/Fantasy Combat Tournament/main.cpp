/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Devin Gendron
** Date: 3/5/18
** Description: Using dice rolls, have characters battle it out... in
** a tournament!
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
#include "Queue.h"
#include "Node.h"

int main()
{
    srand(time(NULL));
    int menuC = 0;
    int menuChar = 0;
    int counter = 0;
    int maxCount = 0;
    int endGame = 0;
    int teamCount = 0;
    int winner = 0;
    int lost = 0;
    int showLosers = 0;
    int team1Win = 0;
    int team2Win = 0;
    std::string name = " ";

    Combat match;
    Queue team1;
    Queue team2;
    Node dead;

    Character *newMemT1 = NULL;
    Character *newMemT2 = NULL;

    menuC = menu(); //Main menu
    do {
        maxCount = teamSize();

        switch (menuC)
        {
            case 1 : //play game
                do {

                    do {
                        std::cout << "*********** Team " << teamCount + 1 << " ***********" << std::endl;
                        menuChar = charMenu(); //Character Menu

                        switch (menuChar) {
                            case 1 :  //Vampire
                                if (teamCount == 0) {
                                    newMemT1 = new Vampire();
                                    std::cout << "Player 1 Chose a Vampire for Team 1!" << std::endl;
                                    newMemT1->characteristics();
                                    std::cout << "Please enter a nickname for your Vampire!" << std::endl;
                                    std::getline(std::cin, name);
                                    newMemT1->setName(name);
                                    team1.addBack(newMemT1);

                                } else {
                                    newMemT2 = new Vampire();
                                    std::cout << "Player 2 Chose a Vampire for Team 2!" << std::endl;
                                    newMemT2->characteristics();
                                    std::cout << "Please enter a nickname for your Vampire!" << std::endl;
                                    std::getline(std::cin, name);
                                    newMemT2->setName(name);
                                    team2.addBack(newMemT2);
                                }
                                std::cout << std::endl;
                                break;

                            case 2 :  //Barbarian
                                if (teamCount == 0) {
                                    newMemT1 = new Barbarian();
                                    std::cout << "Player 1 Chose a Barbarian for Team 1!" << std::endl;
                                    newMemT1->characteristics();
                                    std::cout << "Please enter a nickname for your Barbarian!" << std::endl;
                                    std::getline(std::cin, name);
                                    newMemT1->setName(name);
                                    team1.addBack(newMemT1);
                                } else
                                {
                                    newMemT2 = new Barbarian();
                                    std::cout << "Player 2 Chose a Barbarian for Team 2!" << std::endl;
                                    newMemT2->characteristics();
                                    std::cout << "Please enter a nickname for your Barbarian!" << std::endl;
                                    std::getline(std::cin, name);
                                    newMemT2->setName(name);
                                    team2.addBack(newMemT2);
                                }
                                std::cout << std::endl;
                                break;

                            case 3 :  //Blue Men
                                if (teamCount == 0) {
                                    newMemT1 = new BlueMen();
                                    std::cout << "Player 1 Chose Blue Men for Team 1!" << std::endl;
                                    newMemT1->characteristics();
                                    std::cout << "Please enter a nickname for your Blue Men!" << std::endl;
                                    std::getline(std::cin, name);
                                    newMemT1->setName(name);
                                    team1.addBack(newMemT1);
                                } else {
                                    newMemT2 = new BlueMen();
                                    std::cout << "Player 2 Chose Blue Men for Team 2!" << std::endl;
                                    newMemT2->characteristics();
                                    std::cout << "Please enter a nickname for your Blue Men!" << std::endl;
                                    std::getline(std::cin, name);
                                    newMemT2->setName(name);
                                    std::cout << std::endl;
                                    team2.addBack(newMemT2);
                                }
                                std::cout << std::endl;
                                break;

                            case 4 :  //Medusa
                                if (teamCount == 0) {
                                    newMemT1 = new Medusa();
                                    std::cout << "Player 1 Chose Medusa for Team 1!" << std::endl;
                                    newMemT1->characteristics();
                                    std::cout << "Please enter a nickname for your Medusa!" << std::endl;
                                    std::getline(std::cin, name);
                                    newMemT1->setName(name);
                                    team1.addBack(newMemT1);
                                } else {
                                    newMemT2 = new Medusa();
                                    std::cout << "Player 2 Chose Medusa for Team 2!" << std::endl;
                                    newMemT2->characteristics();
                                    std::cout << "Please enter a nickname for your Medusa!" << std::endl;
                                    std::getline(std::cin, name);
                                    newMemT2->setName(name);
                                    team2.addBack(newMemT2);
                                }
                                std::cout << std::endl;
                                break;

                            case 5 :  //Harry Potter
                                if (teamCount == 0) {
                                    newMemT1 = new HarryPotter();
                                    std::cout << "Player 1 Chose Harry Potter for Team 1!" << std::endl;
                                    newMemT1->characteristics();
                                    std::cout << "Please enter a nickname for Harry Potter!" << std::endl;
                                    std::getline(std::cin, name);
                                    newMemT1->setName(name);
                                    team1.addBack(newMemT1);
                                } else {
                                    newMemT2 = new HarryPotter();
                                    std::cout << "Player 2 Chose Harry Potter for Team 2!" << std::endl;
                                    newMemT2->characteristics();
                                    std::cout << "Please enter a nickname for Harry Potter!" << std::endl;
                                    std::getline(std::cin, name);
                                    newMemT2->setName(name);
                                    team2.addBack(newMemT2);
                                }
                                std::cout << std::endl;
                                break;
                        }
                        counter++;
                    }while(counter != maxCount);
                    counter = 0;
                    teamCount++;
                } while (teamCount != 2);

                /////////////////////////////////////////
                //player game here
                do {
                    match.setPlayer1(team1);
                    match.setPlayer2(team2);
                    winner = match.battle();

                    if (winner == 1) {
                        team1.moveToBack(); //moves player 1 to back of queue
                        team1.getFront()->recovery();   //player recovers some health
                        dead.addHead(team2.getFront());    //move player 2 to dead stack
                        std::cout << team2.getFront()->getName() << " was sent to the graveyard!" << std::endl;
                        team2.removeFront();    //remove from queue
                        team1Win++;
                    } else if (winner == 2) {
                        team2.moveToBack(); //moves player 2 to back of queue
                        team2.getFront()->recovery();   //player recovers some health
                        dead.addHead(team1.getFront());    //move player 1 to dead stack
                        std::cout << team1.getFront()->getName() << " was sent to the graveyard!" << std::endl;
                        team1.removeFront();    //remove from queue
                        team2Win++;
                    }
                    if(team1.isEmpty())
                    {
                        lost = 1;
                        teamCount = 0;
                        std::cout << "+----------------------------------+" << std::endl;
                        std::cout << "| Team 2 Win's the Tournament!!!!! |" << std::endl;
                        std::cout << "+----------------------------------+" << std::endl;
                        std::cout << "+-----------------------+" << std::endl;
                        std::cout << "| Team 1 Final Score: " << team1Win << " |" << std::endl;
                        std::cout << "+-----------------------+" << std::endl;
                        std::cout << "+-----------------------+" << std::endl;
                        std::cout << "| Team 2 Final Score: " << team2Win << " |" << std::endl;
                        std::cout << "+-----------------------+" << std::endl;
                        showLosers = displayLosers();
                        switch (showLosers)
                        {
                            case 1 : //shows losers
                                dead.traverse();
                                break;
                            case 2 : //skips
                                break;
                            default:
                                break;
                        }
                        //clear queues and dead stack
                        team1.deleteAll();
                        team2.deleteAll();
                        dead.deleteAll();
                    }
                    else if (team2.isEmpty())
                    {
                        lost = 2;
                        teamCount = 0;
                        std::cout << "+----------------------------------+" << std::endl;
                        std::cout << "| Team 1 Win's the Tournament!!!!! |" << std::endl;
                        std::cout << "+----------------------------------+" << std::endl;
                        std::cout << "+-----------------------+" << std::endl;
                        std::cout << "| Team 1 Final Score: " << team1Win << " |" << std::endl;
                        std::cout << "+-----------------------+" << std::endl;
                        std::cout << "+-----------------------+" << std::endl;
                        std::cout << "| Team 2 Final Score: " << team2Win << " |" << std::endl;
                        std::cout << "+-----------------------+" << std::endl;
                        showLosers = displayLosers();
                        switch (showLosers)
                        {
                            case 1 : //shows losers
                                dead.traverse();
                                break;
                            case 2 : //skips
                                break;
                            default:
                                break;
                        }
                        team1.deleteAll();
                        team2.deleteAll();
                        dead.deleteAll();
                    }
                    else
                    {
                        std::cout << "+------------+" << std::endl;
                        std::cout << "| NEXT MATCH |" << std::endl;
                        std::cout << "+------------+" << std::endl;
                    }
                }while(lost == 0);
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
                delete newMemT1;
                delete newMemT2;
                newMemT1 = nullptr;
                newMemT2 = nullptr;
                break;
            case 2 : //quit
                std::cout << "Game Quit." << std::endl;
                endGame = 1;
                break;
        }
        menuChar = 0;
        counter = 0;
        maxCount = 0;
        teamCount = 0;
        winner = 0;
        lost = 0;
        showLosers = 0;
        team1Win = 0;
        team2Win = 0;
    }while(endGame == 0);

    return 0;
}