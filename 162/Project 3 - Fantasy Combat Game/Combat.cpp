/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Devin Gendron
** Date: 2/18/17
** Description: Using dice rolls, have characters battle it out!
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
void Combat::setPlayer1(Character *p1)
{
    player1 = p1;
}
void Combat::setPlayer2(Character *p2)
{
    player2 = p2;
}
void Combat::battle()
{
    int damage = 0;
    int gameOver = 0;
    int cC = 0;

    do {
        std::cout << "ROUND: " << round << "!" << std::endl;
        std::cout << "Atacker - Player 1: " << player1->getName() << std::endl;
        std::cout << "Defender - Player 2: " << player2->getName() << ", Armor: "
                  << player2->getArmor() << ", StrengthPoints: " << player2->getStrengthPoints() << std::endl;

        std::cout << "Player 1: " << player1->getName() << " attacks!" << std::endl;
        player1->rollAttack();
        std::cout << "Player 1: " << player1->getName() << "'s attack power is: " << player1->getAttack() << std::endl;

        std::cout << "Player 2: " << player2->getName() << " defends!" << std::endl;
        player2->rollDefense();
        std::cout << "Player 2: " << player2->getName() << "'s defense is: " << player2->getDefense() << std::endl;




        damage = player1->getAttack() - player2->getDefense() - player2->getArmor();
        if (damage > 0)
        {
            std::cout << "Player 1: " << player1->getName() << " did " << damage << " points of damage to Player 2: " << player2->getName() << "." << std::endl;
            player2->setStrengthPoints(damage);
            std::cout << "Player 2: " << player2->getName() << " now has " << player2->getStrengthPoints() << " left." << std::endl;
        }
        else
        {
            std::cout << "The Attack was completely defended!" << std::endl;
            std::cout << "Player 2: " << player2->getName() << " still has " << player2->getStrengthPoints() << " left." << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;

        if(player2->getStrengthPoints() > 0)
        {
            std::cout << "Atacker - Player 2: " << player2->getName() << std::endl;
            std::cout << "Defender - Player 1: " << player1->getName() << ", Armor: "
                      << player1->getArmor() << ", StrengthPoints: " << player1->getStrengthPoints() << std::endl;

            std::cout << "Player 2: " << player2->getName() << " attacks!" << std::endl;
            player2->rollAttack();
            std::cout << "Player 2: " << player2->getName() << "'s attack power is: " << player2->getAttack() << std::endl;
            std::cout << "Player 1: " << player1->getName() << " defends!" << std::endl;
            player1->rollDefense();
            std::cout << "Player 1: " << player1->getName() << "'s defense is: " << player1->getDefense() << std::endl;
            damage = player2->getAttack() - player1->getDefense() - player1->getArmor();
            if (damage > 0)
            {
                std::cout << "Player 2: " << player2->getName() << " did " << damage << " points of damage to Player 1: " << player1->getName() << "." << std::endl;
                player1->setStrengthPoints(damage);
                std::cout << "Player 1: " << player1->getName() << " now has " << player1->getStrengthPoints() << " left." << std::endl;
            }
            else
            {
                std::cout << "The Attack was completely defended!" << std::endl;
                std::cout << "Player 1: " << player1->getName() << " still has " << player1->getStrengthPoints() << " left." << std::endl;
            }
        }

        std::cout << std::endl;
        std::cout << std::endl;

        if (player1->getStrengthPoints() < 1)
        {
            player1->specialAbility();
        }
        else if (player2->getStrengthPoints() < 1)
        {
            player2->specialAbility();
        }

        round++;

        if (player1->getStrengthPoints() < 1) {
            std::cout << "+-----------------------------------------------------+" << std::endl;
            std::cout << "| Player 1: " << player1->getName() << " died, Player 2: " << player2->getName() << " Wins! |" << std::endl;
            std::cout << "+-----------------------------------------------------+" << std::endl;
            std::cout << std::endl;
            gameOver = 1;
        } else if (player2->getStrengthPoints() < 1) {
            std::cout << "+-----------------------------------------------------+" << std::endl;
            std::cout << "| Player 2: " << player2->getName() << " died, Player 1: " << player1->getName() << " Wins! |" << std::endl;
            std::cout << "+-----------------------------------------------------+" << std::endl;
            std::cout << std::endl;
            gameOver = 1;
        }
        else
        {
            cC = contCombat();
            switch (cC)
            {
                case 1 : //play again
                    gameOver = 0;
                    break;
            }
        }
    }while(gameOver == 0);
}