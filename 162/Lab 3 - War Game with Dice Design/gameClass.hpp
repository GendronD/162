/*********************************************************************
** Program name: War Game with Dice Design
** Author: Devin Gendron
** Date: 1/28/17
** Description: War game with two players using a loaded and unloaded dice.
*********************************************************************/
#ifndef GAMECLASS_HPP
#define GAMECLASS_HPP
#include "gameMenu.hpp"
#include "dieClass.hpp"
#include "loadedDieClass.hpp"

class Game
{
	private:
		int menuDecision = 0;
		int roundNum = 0;
		int playerDice = 0;
		int diceNumbers = 0;
		std::string winner = " "; 
		Die *player1;
		Die *player2;


	public:
		//constructor
		Game();

		//getters
		int getMenuDecision();	//gets menudecision
		int getRoundNum();		//gets round number
		int getPlayerDice();	//gets die type
		int getDiceNumbers();	//gets number of sides per dice
		std::string getWinner();//gets winner
		Die getPlayer1();
		Die getPlayer2();

		//setters
		Die setPlayer1(Die*);
		Die setPlayer2(Die*);

		//functions
		void incrementScore(int , int);
		void runGame();
		int menu();
		int rounds();
		int dieType();
		int dieSideNum();
		void setGame();
		void finalWinner();
		void roundWinner(int, int);
		void gameQuit();
};
#endif