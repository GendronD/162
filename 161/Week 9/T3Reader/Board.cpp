/****************************************************************************
* Author: Devin Gendron
* Date: 11/22/17
* Description: Board .cpp file 
****************************************************************************/
#include "Board.hpp"
#include <iostream>
#include <string>

/********************** Create constructors *********************************
* should have a default constructor that initializes the 3x3 array to being 
* empty (each element set to a space character).
*****************************************************************************/
Board::Board()
{}

Board::Board(char gameBoard[ROWS][COLS])
	{
		//initializes array or board to empty spaces
		for (int i = 0; i < ROWS; i++)
			{
				for(int j = 0; j < COLS; j++) {gameBoard[i][j] = ' ';}
			}

		turnNumber = 0;	//intialize turnNumber to 0 before makeMoves are read.
	}
/********************** Make Move Function *********************************
*  It should have a method called makeMove that takes two ints and a char 
* (either 'x' or 'o') as parameters, representing the x and y coordinates of 
* the move (see the example below) and which player's turn it is. If that 
* location is unoccupied, makeMove should record the move and return true. 
* If that location is already occupied, makeMove should just return false.
***************************************************************************/
bool Board::makeMove(int x, int y, char player)	//controls players moves
{
	if (player == 'x')									//checks that player is plaer x
	{
		if (gameBoard[x][y] == ' ' || gameBoard[x][y] != 'o')	//checks if space is empty or o
		
		{
			//attempted to use dynamic array for practice, but couldn't get it to work :(

			gameBoard[x][y] = 'x';
			
			return true;
		}
		
		else 
			
			return false;
	}
	
	else if (player == 'o')								//checks that player is player o
	{
		if (gameBoard[x][y] == ' ' || gameBoard[x][y] != 'x')	//checks if space is empty
		
		{
			gameBoard[x][y] = 'o';

			return true;
		}

		else 
			return false;
	}

	//return 0;
}

/********************** Displays Game States **********************************
* There should be a method called gameState that takes no parameters and returns 
* one of the four following values: X_WON, O_WON, DRAW, or UNFINISHED - use an 
* enum for this, not strings (the enum definition should go in Board.hpp, before 
* the class, not inside it).
******************************************************************************/
int Board::gameState()					//returns statements on winner/loser/unfinished
	{

			//i feel like a loop could be used here... will test if time.
			//needs check for a winner
		if ((gameBoard [0][0] == gameBoard [0][1] == gameBoard [0][2]) ||
		//check middle of board
			(gameBoard [1][0] == gameBoard [1][1] == gameBoard [1][2]) ||
		//check bottom of board
			(gameBoard [2][0] == gameBoard [2][1] == gameBoard [2][2]) ||
		//check left side of board
			(gameBoard [0][0] == gameBoard [1][0] == gameBoard [2][0]) ||
		//check down the center
			(gameBoard [0][1] == gameBoard [1][1] == gameBoard [2][1]) ||
		//check the right side
			(gameBoard [0][2] == gameBoard [1][2] == gameBoard [2][2]) ||
		//check "\" diagonal
			(gameBoard [0][0] == gameBoard [1][1] == gameBoard [2][2]) ||
		//check "/" diagonal
			(gameBoard [2][0] == gameBoard [1][1] == gameBoard [0][2]))		
		{
			//X winner
			//check top of board
			if ((gameBoard [0][0] == 'x' && gameBoard [0][1] == 'x' && gameBoard [0][2] == 'x' ) ||
			//check middle of board
				(gameBoard [1][0] == 'x' && gameBoard [1][1] == 'x' && gameBoard [1][2] == 'x' ) ||
			//check bottom of board
				(gameBoard [2][0] == 'x' && gameBoard [2][1] == 'x' && gameBoard [2][2] == 'x' ) ||
			//check left side of board
				(gameBoard [0][0] == 'x' && gameBoard [1][0] == 'x' && gameBoard [2][0] == 'x' ) ||
			//check down the center
				(gameBoard [0][1] == 'x' && gameBoard [1][1] == 'x' && gameBoard [2][1] == 'x' ) ||
			//check the right side
				(gameBoard [0][2] == 'x' && gameBoard [1][2] == 'x' && gameBoard [2][2] == 'x' ) ||
			//check "\" diagonal
				(gameBoard [0][0] == 'x' && gameBoard [1][1] == 'x' && gameBoard [2][2] == 'x' ) ||
			//check "/" diagonal
				(gameBoard [2][0] == 'x' && gameBoard [1][1] == 'x' && gameBoard [0][2] == 'x' ))
			{
				return X_WON;	//x was found to be the winner
			}

			//O winner
			//check top of board
			else if ((gameBoard [0][0] == 'o' && gameBoard [0][1] == 'o' && gameBoard [0][2] == 'o' ) ||
			//check middle of board
				(gameBoard [1][0] == 'o' && gameBoard [1][1] == 'o' && gameBoard [1][2] == 'o' ) ||
			//check bottom of board
				(gameBoard [2][0] == 'o' && gameBoard [2][1] == 'o' && gameBoard [2][2] == 'o' ) ||
			//check left side of board
				(gameBoard [0][0] == 'o' && gameBoard [1][0] == 'o' && gameBoard [2][0] == 'o' ) ||
			//check down the center
				(gameBoard [0][1] == 'o' && gameBoard [1][1] == 'o' && gameBoard [2][1] == 'o' ) ||
			//check the right side
				(gameBoard [0][2] == 'o' && gameBoard [1][2] == 'o' && gameBoard [2][2] == 'o' ) ||
			//check "\" diagonal
				(gameBoard [0][0] == 'o' && gameBoard [1][1] == 'o' && gameBoard [2][2] == 'o' ) ||
			//check "/" diagonal
				(gameBoard [2][0] == 'o' && gameBoard [1][1] == 'o' && gameBoard [0][2] == 'o' ))
			{
				return O_WON;	//o was found to be the winner
			}
		}
		//check for draw.  Draws only happen when all the spaces are full after 9 turns
		if (turnNumber == turnDraw) {return DRAW;}

		//The only other possibility is if the game is unfinished, thus:
		else {return UNFINISHED;}

		//return 0;
	}

/********************** Prints the Board *********************************
* [Optional: write a method called print, which just prints out the current 
* board to the screen - this is not required, but will very likely be useful 
* for debugging.]
**************************************************************************/
void Board::printBoard()
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				std::cout << gameBoard[i][j] << std::endl;
			}		
		}
	}





