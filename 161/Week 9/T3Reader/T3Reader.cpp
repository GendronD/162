/****************************************************************************
* Author: Devin Gendron
* Date: 11/22/17
* Description: T3Reader .cpp file 
****************************************************************************/
#include "Board.hpp"
#include "T3Reader.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

/****************************************************************************
* It should have a constructor that takes a char parameter that specifies 
* whether 'x' or 'o' should have the first move.
*****************************************************************************/		
T3Reader::T3Reader()
{
	Board tttBoard;
	char playersTurn = 0;
}

T3Reader::T3Reader(char turn)
{
	setPlayerTurn(turn);	//receives turn and sets to playersTurn
}
	/*************************** Getters/Setters **********************************/
	void T3Reader::setPlayerTurn(char turn) {playersTurn = turn;}	//sets players turn

	char T3Reader::getPlayerTurn() {return playersTurn;}			//gets players turn

	//getT3Board?
	Board T3Reader::getT3Board() {return tttBoard;}					//gets board from private
	/******************************************************************************/

	/****************************** readGameFile **********************************
	* It should have a method called readGameFile that takes a string parameter that 
	* gives the name of the game file. The readGameFile method should keep looping, 
	* reading a move from the file, and sending it to the board (with makeMove).  The 
	* readGameFile method should return false if any of the moves is for a square that 
	* was already occupied, or if there are still additional moves in the file after 
	* the game has finished.  Otherwise it should return true.
	*******************************************************************************/
	bool T3Reader::readGameFile(std::string gameName)	//string is game file name
	{
		//creating a file stream object and inputting it as well as variables
		std::ifstream gameFile;	//file stream object to input
		//int gameState = UNFINISHED;	
		//int gameState = tttBoard.gameState(); //???????????????????????????????????????????????
		int x;	//row of array
		int y;	//column of array

		//open file
		gameFile.open(gameName.c_str());

		//if loop to keep running
		if (gameFile)	//if file is open
		{	
			do //while(gameState == UNFINISHED)		//loops until gameState != UNFINISHED
			{
			////if loop to keep running
				if (gameFile >> x >> y) //.makeMove(x, y, playersTurn))	//while gamefile uploads to tttBoard
					{
						tttBoard.printBoard();
						tttBoard.makeMove(x, y, playersTurn);
						tttBoard.turnNumber++;	//increment the turn number

						//std::cout << "turns made: " << tttBoard.turnNumber << std::endl;

						/************************ alternates player turns **************************/
						if (playersTurn == 'x') {playersTurn = 'o';}		//if x went, change to o
							//std::cout << "player switched from x to o" << std::endl;}
						else if (playersTurn == 'o') {playersTurn = 'x';}	//if o went, change to x
							//std::cout << "player switched from o to x" << std::endl;}
						/***************************************************************************/

						tttBoard.printBoard();

						if (tttBoard.gameState() == X_WON) {
							//std::cout << "X WON" << std::endl;
						return true;}	//if x wins
						else if (tttBoard.gameState()== O_WON) {
							//std::cout << "O WON" << std::endl;
						return true;}	//if o wins
						else if (tttBoard.gameState()== DRAW) {
							//std::cout << "DRAW" << std::endl;
						return true;}	//if there is a draw
						/***************************************************************************/
					}
				
					else 
					{
						//std::cout << "failure to open" << std::endl;
						return false;
					}	//file could not be opened
			} while(tttBoard.gameState()== UNFINISHED);	

			gameFile.close();	//close inputfile
		}
	}