/****************************************************************************
* Author: Devin Gendron
* Date: 11/22/17
* Description: Board .hpp header file 
****************************************************************************/
#ifndef BOARD_H
#define BOARD_H
#include <string>
const int ROWS = 3;
const int COLS = 3;
const int turnDraw = 9;

//enum for gameState
enum gameStates {X_WON = 1, O_WON, DRAW, UNFINISHED};

//Board class declaration
class Board
{
	//private members
	private:

	//public members
	public:

		//default constructor
		Board();

		//constructor with parameters/overload constructor
		Board(char gameBoard[ROWS][COLS]);

		char player;					//player: x or o
		char gameBoard[ROWS][COLS];		//game board
		int turnNumber;					//what turn is it
		bool makeMove(int, int, char);	//controls players moves
		int gameState();				//returns statements on winner/loser/unfinished
		void printBoard();				//prints the board
};
#endif