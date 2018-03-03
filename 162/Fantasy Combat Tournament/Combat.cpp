/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Devin Gendron
** Date: 3/5/18
** Description: Using dice rolls, have characters battle it out... in
** a tournament!
*********************************************************************/
#include "Combat.h"
#include "Menu.h"
#include "Character.h"
#include <iostream>
//constructor
Combat::Combat()
{

}

//overloaded constructor


//destructor
Combat::~Combat()
{

}

//functions
void Combat::setPlayer1(Queue p1)
{
    Character* fighter;
    fighter = p1.getFront();
    player1 = fighter;
}
void Combat::setPlayer2(Queue p2)
{
    Character* fighter;
    fighter = p2.getFront();
    player2 = fighter;
}
int Combat::battle()
{
    int damage = 0;
    int gameOver = 0;
    int t1Winner = 1;
    int t2Winner = 2;
    int cC = 0;

    std::cout << "+-----------------------+" << std::endl;
    std::cout << "| LET THE BATTLE BEGIN! |" << std::endl;
    std::cout << "+-----------------------+" << std::endl;
    std::cout << std::endl;


    std::cout << "Team 1: " << player1->getName() << ", Type: " << player1->getType() << std::endl;
    std::cout << "Team 2: " << player2->getName() << ", Type: " << player2->getType() << std::endl;
    std::cout << "+---------------------------+" << std::endl;

    /*std::cout << "Atacker - Player 2: " << player2->getName() << std::endl;
    std::cout << "Defender - Player 1: " << player1->getName() << ", Armor: "
              << player1->getArmor() << ", StrengthPoints: " << player1->getStrengthPoints() << std::endl;
*/
    do {
        //std::cout << "+------------+" << std::endl;
        //std::cout << "| ROUND: " << round << " ! |" << std::endl;
        //std::cout << "+------------+" << std::endl;
        //std::cout << "Atacker - Player 1: " << player1->getName() << ", Type: " << player1->getType() << std::endl;
        //std::cout << "Defender - Player 2: " << player2->getName() << ", Type: " << player2->getType() << ", Armor: "
                  //<< player2->getArmor() << ", StrengthPoints: " << player2->getStrengthPoints() << std::endl;

        //std::cout << "Player 1: " << player1->getName() << " attacks!" << std::endl;
        player1->rollAttack();
        //std::cout << "Player 1: " << player1->getName() << "'s attack power is: " << player1->getAttack() << std::endl;

        //std::cout << "Player 2: " << player2->getName() << " defends!" << std::endl;
        player2->rollDefense();
        //std::cout << "Player 2: " << player2->getName() << "'s defense is: " << player2->getDefense() << std::endl;




        damage = player1->getAttack() - player2->getDefense() - player2->getArmor();
        if (damage > 0)
        {
            //std::cout << "Player 1: " << player1->getName() << " did " << damage << " points of damage to Player 2: " << player2->getName() << "." << std::endl;
            player2->setStrengthPoints(damage);
            //std::cout << "Player 2: " << player2->getName() << " now has " << player2->getStrengthPoints() << " left." << std::endl;
        }
        else
        {
            //std::cout << "The Attack was completely defended!" << std::endl;
            //std::cout << "Player 2: " << player2->getName() << " still has " << player2->getStrengthPoints() << " left." << std::endl;
        }
        //std::cout << std::endl;
        //std::cout << std::endl;

        if(player2->getStrengthPoints() > 0)
        {
            //std::cout << "Atacker - Player 2: " << player2->getName() << std::endl;
            //std::cout << "Defender - Player 1: " << player1->getName() << ", Armor: "
                      //<< player1->getArmor() << ", StrengthPoints: " << player1->getStrengthPoints() << std::endl;

            //std::cout << "Player 2: " << player2->getName() << " attacks!" << std::endl;
            player2->rollAttack();
            //std::cout << "Player 2: " << player2->getName() << "'s attack power is: " << player2->getAttack() << std::endl;
            //std::cout << "Player 1: " << player1->getName() << " defends!" << std::endl;
            player1->rollDefense();
            //std::cout << "Player 1: " << player1->getName() << "'s defense is: " << player1->getDefense() << std::endl;
            damage = player2->getAttack() - player1->getDefense() - player1->getArmor();
            if (damage > 0)
            {
                //std::cout << "Player 2: " << player2->getName() << " did " << damage << " points of damage to Player 1: " << player1->getName() << "." << std::endl;
                player1->setStrengthPoints(damage);
                //std::cout << "Player 1: " << player1->getName() << " now has " << player1->getStrengthPoints() << " left." << std::endl;
            }
            else
            {
                //std::cout << "The Attack was completely defended!" << std::endl;
                //std::cout << "Player 1: " << player1->getName() << " still has " << player1->getStrengthPoints() << " left." << std::endl;
            }
        }

        //std::cout << std::endl;
        //std::cout << std::endl;

        if (player1->getStrengthPoints() < 1)
        {
            player1->specialAbility();
            //std::cout << std::endl;
        }
        else if (player2->getStrengthPoints() < 1)
        {
            player2->specialAbility();
            //std::cout << std::endl;
        }

        round++;

        if (player1->getStrengthPoints() < 1) {
            //std::cout << "+-----------------------------------------------------+" << std::endl;
            std::cout << "****| Player 1: " << player1->getName() << " died, Player 2: " << player2->getName() << " Wins! |****" << std::endl;
            //std::cout << "+-----------------------------------------------------+" << std::endl;
            std::cout << std::endl;
            gameOver = 1;
            round = 1;

            return t2Winner;

        } else if (player2->getStrengthPoints() < 1) {
            //std::cout << "+-----------------------------------------------------+" << std::endl;
            std::cout << "*****| Player 2: " << player2->getName() << " died, Player 1: " << player1->getName() << " Wins! |****" << std::endl;
            //std::cout << "+-----------------------------------------------------+" << std::endl;
            std::cout << std::endl;
            gameOver = 1;
            round = 1;

            return t1Winner;
        }
        /*else
        {
            cC = contCombat();
            switch (cC)
            {
                case 1 : //play again
                    gameOver = 0;
                    break;
            }
        }*/
    }while(gameOver == 0);
}