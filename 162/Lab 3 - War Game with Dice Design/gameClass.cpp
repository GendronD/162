/*********************************************************************
** Program name: War Game with Dice Design
** Author: Devin Gendron
** Date: 1/28/17
** Description: War game with two players using a loaded and unloaded dice.
*********************************************************************/
#include "gameMenu.hpp"
#include "inputValidation.hpp"
#include "promptPlayer.hpp"
#include "dieClass.hpp"
#include "loadedDieClass.hpp"
#include "gameClass.hpp"

//constructor
Game::Game()
{

}

//getters
int Game::getMenuDecision()
{
	return menuDecision;
}

int Game::getRoundNum()
{
	return roundNum;
}

int Game::getPlayerDice()
{
	return playerDice;
}

int Game::getDiceNumbers()
{
	return diceNumbers;
}

std::string Game::getWinner()
{
	return winner;
}

Die Game::getPlayer1()
{
	return *player1;
}

Die Game::getPlayer2()
{
	return *player2;
}
//setters
Die Game::setPlayer1(Die *p1)
{
	player1 = p1;
}

Die Game::setPlayer2(Die *p2)
{
	player2 = p2;
}

//functions
int Game::menu()					//main menu
{
	menuDecision = gameMenu();
}

int Game::rounds()					//choose rounds
{
	roundNum = gameRounds();
}

int Game::dieType()					//choose dice
{
	playerDice = dieChoice();
}

int Game::dieSideNum()				//choose dice size
{
	diceNumbers = diceSides();
}

void Game::setGame()				//sets dice size to players dice type
{
	std::cout << "-Player 1-" << std::endl;
	int dN1 = dieSideNum();
	player1->setN(dN1);
	std::cout << "-Player 2-" << std::endl;
	int dN2 = dieSideNum();
	player2->setN(dN2);
} 

void Game::incrementScore(int rollP1, int rollP2)			//increments players score
{
	int player1Score = 0;
	int player2Score = 0;
	player1Score = rollP1;
	player2Score = rollP2;

	if (player1Score > player2Score)
	{
		player1->setScore();
	}
	else if (player2Score > player1Score)
	{
		player2->setScore();
	}
	else if (player1Score == player2Score)
	{

	}
}

void Game::roundWinner(int rollP1, int rollP2)
{
	if (rollP1 > rollP2)
	{
		std::cout << "Player 1 wins the roll!" << std::endl;;
	}
	else if ( rollP2 > rollP1)
	{
		std::cout << "Player 2 wins the roll!" << std::endl;;
	}
	else if (rollP1 == rollP2)
	{
		std::cout << "The roll is a draw!" << std::endl;;
	}
}

void Game::finalWinner()			//determines Winner/Loser/Draw
{
	int p1Score = player1->getScore();
	int p2Score = player2->getScore();

	if (p1Score > p2Score)
	{
		winner = "Player 1";
	}
	else if ( p2Score > p1Score)
	{
		winner = "Player 2";
	}
	else if (p1Score == p2Score)
	{
		winner = "DRAW!";
	}
}

void Game::runGame()				//runs game
{
	std::string p1 = " ";
	std::string p2 = " ";

	if (getPlayerDice() == 1)
	{
		//P1: RD & P2: LD
		p1 = "Regular Dice";
		p2 = "Loaded Dice";

	}
	else if (getPlayerDice() == 2)
	{
		//P1: LD & P2: RD
		p1 = "Loaded Dice";
		p2 = "Regular Dice";

	}
	else if (getPlayerDice() == 3)
	{
		//P1 & P2 have regular dice
		p1 = "Regular Dice";
		p2 = "Regular Dice";

	}
	else if (getPlayerDice() == 4)
	{
		//P1 & P2 have loaded dice
		p1 = "Loaded Dice";
		p2 = "Loaded Dice";
	}

	for (int r = 0; r < roundNum; r++)	//starts Game
	{	
		//std::cout << "\033[2J\033[1;1H";
		int rollP1 = 0;
		int rollP2 = 0;

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Round: " << (r + 1) << std::endl;	//prints round number
		rollP1 = player1->rollDice();
		rollP2 = player2->rollDice();

		incrementScore(rollP1, rollP2);				//increments score for players
		std::cout << "+---------DiceType----+-Side--+" << std::endl;
		std::cout << "Player1: " << p1 << " | " << player1->getN() << std::endl;	//Displays die type and number of sides chosen
		std::cout << "Player2: " << p2 << " | " << player2->getN() << std::endl;	//Displays die type and number of sides chosen
		std::cout << "+-------Roll-------+" << std::endl;	
		std::cout << "Player1: " << rollP1 << std::endl;	//Displays number of rolls for player 1
		std::cout << "Player2: " << rollP2 << std::endl;	//Displays number of rolls for player 2
		roundWinner(rollP1, rollP2);
		std::cout << "+-------SCORE-------+" << std::endl;	
		std::cout << "Player1: " << player1->getScore() << std::endl;	//Displays current score for player 1
		std::cout << "Player2: " << player2->getScore() << std::endl;	//Displays current score for player 2

	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "+-------FINALSCORES-------+" << std::endl;	
	std::cout << "Player1: " << player1->getScore() << std::endl;	//Displays final score for player 1
	std::cout << "Player2: " << player2->getScore() << std::endl;	//Displays final score for player 2
	finalWinner();
	std::cout << "+-------------------------+" << std::endl;	
	std::cout << "Final Winner: " << getWinner() << std::endl;			//Displays final winner
	std::cout << "+-------------------------+" << std::endl;	

	delete player1;
	delete player2;
}

void Game::gameQuit()
{
	std::cout << "Game Quit." << std::endl;
}