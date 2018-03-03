/****************************************************************************
* Author: Devin Gendron
* Date: 11/1/17
* Description: Player .cpp implementation file 
****************************************************************************/
#include "Player.hpp"
#include <iostream>
#include <string>

/********************** Create constructors *********************************/

Player::Player()					//default constructor
	{
		std::string name = "";	//player name
		int points = -1;		//points
		int rebounds = -1;		//rebounds
		int assists = -1;		//assists
	}

Player::Player(std::string n, int p, int r, int a) : name(n), points(p), rebounds(r), assists(a)
		{

		}

/******************************* setters ************************************/

void Player::setPoints (int setP) {		//Setter for points
	points = setP;
}

void Player::setRebounds (int setR) {		//Setter for rebounds
	rebounds = setR;
}

void Player::setAssists (int setA) {		//Setter for assists
	assists = setA;
}
/**************************** getters **************************************/

std::string Player::getName () //Get name
{
	return name;			//Initialize player name
}

int Player::getPoints ()	//Get points
{
	return points;			//Initialize points
}

int Player::getRebounds ()	//Get rebounds
{
	return rebounds;		//Initialize rebounds
}

int Player::getAssists ()	//Get assists
{
	return assists;			//Initialize assists
}

/******************************* player point calculator ************************************/

bool Player::hasMorePointsThan (Player otherPlayer) {
	
	int thisPlayersPoints = getPoints();			//retrieves points of player
	int theOtherPlayer = otherPlayer.getPoints();	//retrieves points of other player

	if (thisPlayersPoints > theOtherPlayer)			//compares players
		return true;
	else{
		return false;
	}

}