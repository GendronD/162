/****************************************************************************
* Author: Devin Gendron
* Date: 11/1/17
* Description: Team .cpp implementation file 
****************************************************************************/
#include "Team.hpp"
#include <iostream>
#include <string>

/********************** Create constructor *********************************/

Team::Team(Player pg, Player sg, Player sf, Player pf, Player c) : pointGuard(pg), shootingGuard(sg), smallForward(sf), powerForward(pf), center(c)
		{

		}

/******************************* setters ************************************/

void Team::setPointGuard (Player pg)		 //sets point guard to team
{		
	pointGuard = pg;
}

void Team::setShootingGuard (Player sg) 	//Sets shooting guard to team
{	
	shootingGuard = sg;
}

void Team::setSmallForward (Player sf) 	//Sets small forward to team
{	
	smallForward = sf;
}

void Team::setPowerForward (Player pf) 	//Sets power forward to team
{	
	powerForward = pf;
}
void Team::setCenter (Player c) 			//Sets center to team
{	
	center = c;
}

/**************************** getters **************************************/

Player Team::getPointGuard ()	//Get point guard
{
	return pointGuard;			//Initialize point guard 
}
Player Team::getShootingGuard ()	//Get shooting guard
{
	return shootingGuard;			//Initialize shooting guard
}

Player Team::getSmallForward ()	//Get small forward
{
	return smallForward;		//Initialize small forward
}

Player Team::getPowerForward ()	//Get power forward
{
	return powerForward;			//Initialize power forward
}

Player Team::getCenter ()	//Get center
{
	return center;			//Initialize center
}

/**************************** team points func **************************************/

int Team::totalPoints()
{
	int totalPoints;	//declare totalPoints and retrieve points from each player on line 74
	totalPoints = pointGuard.getPoints() + shootingGuard.getPoints() + smallForward.getPoints() + powerForward.getPoints() + center.getPoints();
	
	return totalPoints;	//returns total points for team
}







