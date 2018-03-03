/****************************************************************************
* Author: Devin Gendron
* Date: 11/22/17
* Description: T3Reader .hpp header file 
****************************************************************************/
#ifndef T3Reader_H
#define T3Reader_H
#include <string>
#include "Board.hpp"


/****************************************************************************
* Write a class called T3Reader that uses the Board class to re-run a game of 
* TicTacToe from moves that it reads from a text file. This class will have a 
* field for a Board object and a field to keep track of which player's turn it 
* is. 
*****************************************************************************/

//Board class declaration
class T3Reader
{
	//private members
	private:

		Board tttBoard;
		char playersTurn = 0;

	//public members
	public:

		//default constructor
		T3Reader();

		//constructor with parameters/overload constructor
		T3Reader(char turn);

		//will loop while game runs
		bool readGameFile(std::string);	//string is game file name

		void setPlayerTurn(char);
		//Board setT3Board();
		char getPlayerTurn();
		Board getT3Board();

};
#endif