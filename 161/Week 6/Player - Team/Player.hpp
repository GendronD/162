/****************************************************************************
* Author: Devin Gendron
* Date: 11/1/17
* Description: Player header
****************************************************************************/
#ifndef PLAYER_H
#define PLAYER_H
#include <string>

//Player class declaration
class Player
{
	//private members
	private:

		std::string name;	//player name
		int points;			//points
		int rebounds;		//rebounds
		int assists;		//assists

	//public members
	public:

		//default constructor
		Player();

		//constructor with parameters/overload constructor
		Player(std::string n, int p, int r, int a);

		//getters
		std::string getName();		//Returns player name
		int getPoints();			//Returns points
		int getRebounds();			//Returns rebounds
		int getAssists();			//Returns assists

		//setters for stats
		void setPoints(int);		//Sets points
		void setRebounds(int); 		//Sets rebounds
		void setAssists(int);		//Sets Assists

		//bool methods
		bool hasMorePointsThan(Player);	//more points comparison

};
#endif