/****************************************************************************
* Author: Devin Gendron
* Date: 11/1/17
* Description: Team header
****************************************************************************/
#ifndef TEAM_H
#define TEAM_H
#include "Player.hpp"
#include <string>

//Team class declaration
class Team
{
	//private members
	private:

		//set methods
		Player pointGuard;
		Player shootingGuard;
		Player smallForward;
		Player powerForward;
		Player center;

	//public members
	public:

		//constructor with parameters/overload constructor
		Team(Player, Player, Player, Player, Player);

		//getters
		Player getPointGuard();			//Returns point guard
		Player getShootingGuard();		//Returns shooting guard
		Player getSmallForward();		//Returns small forward
		Player getPowerForward();		//Returns power forward
		Player getCenter();				//Returns center

		//setters
		void setPointGuard(Player);			//Sets point guard
		void setShootingGuard(Player);		//Sets shooting guard
		void setSmallForward(Player);		//Sets small forward
		void setPowerForward(Player);		//Sets power forward
		void setCenter(Player);				//Sets center

		//modifier functions
		int totalPoints();

};
#endif