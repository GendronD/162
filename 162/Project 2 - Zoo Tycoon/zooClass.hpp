/*********************************************************************
** Program name: Zoo Tycoon
** Author: Devin Gendron
** Date: 2/4/17
** Description: Zoo Tycoon Game
*********************************************************************/
#ifndef ZOOCLASS_HPP
#define ZOOCLASS_HPP
#include "animalClass.hpp"
#include "tigerClass.hpp"
#include "penguinClass.hpp"
#include "turtleClass.hpp"
#include "inputValidation.hpp"
#include "promptPlayer.hpp"


class Zoo
{
private:
    int bankAccount = 25000;
    int zooDay = 0;
    //Tiger *tigerArray[10];
    //Penguin *penguinArray[10];
    //Turtle *turtleArray[10];

    Tiger **tigerArray;
    Penguin **penguinArray;
    Turtle **turtleArray;
    int arrayLengthTiger;
    int arrayLengthPenguin;
    int arrayLengthTurtle;
    int bonusProfit = 0;

    int feedCost = 0;
    int sicknessMod = 0;
    int bought = 1;

    int tigerCounter = 0;
    int penguinCounter = 0;
    int turtleCounter = 0;

    //const int tigerFoodM = 5;
    //const int penguinFoodM = 1;
    //const float turtleFoodM = 0.5;

protected:

public:

    //constructor
    Zoo();

    //destructor
    ~Zoo();

    //getters
    int getBankAccount();			//gets current amount in bank
    //int getZooDay();				//gets day number
    //int getFoodCost();				//gets foodcost

    //setters
    //int setBankAccount();			//add or subtract from bank
    void addTiger(int);			    //adds tiger
    void addPenguin(int);			//adds penguin
    void addTurtle(int);			//adds turtle
    void subTiger();				//subtracts tiger
    void subPenguin();				//subtracts penguin
    void subTurtle();				//subtracts turtle

    //void setFeedCost();				//sets feed cost
    void pickFeedType(int);
    void feedChosen();

    //functions
    int zooMenu();					//starting menu
    void startZoo();				//choose starting animals and deduct from bank
    int endGameMenu();				//end game menu
    void quit();					//prints quit message

    void zooSim();					//simulates zoo
    void incrementZooDay();		//updates day at zoo and age of animals
    void payFeedingCost();		//pays feeding cost for animals
    void randomEvent();			//animal dies, inc zoo attendence, baby animal born
    void animalDeath();		//animal dies
    void zooAttendance();	//bonus for tigers
    void animalBirth();		//animal gives birth
    void calculateProfit();		//calculates and displays profit (includes bonus)
    void buyAnimal();			//asks user to buy an adult animal (3 days old)

};
#endif