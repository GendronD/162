/*********************************************************************
** Program name: Zoo Tycoon
** Author: Devin Gendron
** Date: 2/4/17
** Description: Zoo Tycoon Game
*********************************************************************/
#include "animalClass.hpp"
#include "tigerClass.hpp"
#include "penguinClass.hpp"
#include "turtleClass.hpp"
#include "zooClass.hpp"
#include "inputValidation.hpp"
#include "promptPlayer.hpp"
#include <iostream>

//constructor
Zoo::Zoo()
{
    arrayLengthTiger  = 10;
    arrayLengthPenguin = 10;
    arrayLengthTurtle  = 10;
    tigerArray = new Tiger*[arrayLengthTiger];
    penguinArray = new Penguin*[arrayLengthPenguin];
    turtleArray = new Turtle*[arrayLengthTurtle];

    for (int i = 0; i < 10; i++)
    {
        tigerArray[i] = NULL;
        penguinArray[i] = NULL;
        turtleArray[i] = NULL;
    }
}

Zoo::~Zoo()
{
	for (int i = 0; i < arrayLengthTiger; i++)
	{
		if (tigerArray[i] != NULL)
			delete tigerArray[i];
	}
	delete [] tigerArray;

	for (int i = 0; i < arrayLengthPenguin; i++)
	{
		if (penguinArray[i] != NULL)
			delete penguinArray[i];
	}
	delete [] penguinArray;

	for (int i = 0; i < arrayLengthTurtle; i++)
	{
		if (turtleArray[i] != NULL)
			delete turtleArray[i];
	}
	delete [] turtleArray;
}

/**************************************************************************************/

//getters
int Zoo::getBankAccount()
{
    return bankAccount;
}

/**************************************************************************************/

//setters
void Zoo::addTiger(int a)	//copies old tiger array and makes new
{
    if (bankAccount > 10000 || a == 2)
    {
        if (tigerCounter == arrayLengthTiger)    //if tiger cage is full
        {
            int doubleSize = arrayLengthTiger * 2; //double size

            Tiger **tempTiger = new Tiger *[doubleSize];    //create new temp dyn arr

            for (int i = 0; i < arrayLengthTiger; i++) {
                tempTiger[i] = tigerArray[i];        //store values in temp
            }

            for (int i = arrayLengthTiger; i < doubleSize; i++) {
                tempTiger[i] = NULL;        //set temp array's empty cages to null
            }

            delete[] tigerArray;   //delete previous array

            tigerArray = tempTiger; //refill with doubled size and same animals
            arrayLengthTiger = doubleSize;
        }

        if (tigerCounter == 0)
        {
            for (int i = 0; i < tigerCounter + 1; i++) {
                if (tigerArray[i] == NULL) {
                    //tigerArray[i] = new Tiger(a);
                    Tiger *tig = new Tiger(a);
                    tigerArray[tigerCounter] = tig;
                    std::cout << "Tiger added to the Zoo!" << std::endl;
                }
            }
            tigerCounter++;
        }

        else if (tigerArray[tigerCounter] == NULL)
        {
            tigerArray[tigerCounter] = new Tiger(a);
            std::cout << "Tiger added to the Zoo!" << std::endl;
            tigerCounter++;
            if (a == 3)
            {
            	bought = 2;
            	bankAccount = bankAccount - tigerArray[0]->getCost();	//cost of tiger subtracted
            }
        }
    }
    else if (a == 3)
    {
        std::cout << "Insufficient Funds for Tiger" << std::endl;
    }
}

void Zoo::addPenguin(int a)	//copies old penguin array and makes new
{
    if (bankAccount > 1000 || a == 2)
    {
        if (penguinCounter == arrayLengthPenguin)    //if penguin cage is full
        {
            int doubleSize = arrayLengthPenguin * 2; //double size

            Penguin **tempPenguin = new Penguin *[doubleSize];    //create new temp dyn arr

            for (int i = 0; i < arrayLengthPenguin; i++) {
                tempPenguin[i] = penguinArray[i];        //store values in temp
            }

            for (int i = arrayLengthPenguin; i < doubleSize; i++) {
                tempPenguin[i] = NULL;        //set temp array's empty cages to null
            }

            delete[] penguinArray;   //delete previous array

            penguinArray = tempPenguin; //refill with doubled size and same animals
            arrayLengthPenguin = doubleSize;
        }

        if (penguinCounter == 0) {
            for (int i = 0; i < penguinCounter + 1; i++) {
                if (penguinArray[i] == NULL) {
                    Penguin *peng = new Penguin(a);
                    penguinArray[penguinCounter] = peng;
                    std::cout << "Penguin added to the Zoo!" << std::endl;
                }
            }
            penguinCounter++;
        }
        else if (penguinArray[penguinCounter] == NULL)
        {
            penguinArray[penguinCounter] = new Penguin(a);
            std::cout << "Penguin added to the Zoo!" << std::endl;
            penguinCounter++;
            if (a == 3)
            {
            	bought = 2;
            	bankAccount = bankAccount - penguinArray[0]->getCost();	//cost of tiger subtracted
            }
        }
    }
    else if (a == 3)
        std::cout << "Insufficient Funds for Penguin" << std::endl;
}

void Zoo::addTurtle(int a)
{
    if (bankAccount > 100 || a == 2) {
        if (turtleCounter == arrayLengthTurtle)    //if turtle cage is full
        {
            int doubleSize = arrayLengthTurtle * 2; //double size

            Turtle **tempTurtle = new Turtle *[doubleSize];    //create new temp dyn arr

            for (int i = 0; i < arrayLengthTurtle; i++) {
                tempTurtle[i] = turtleArray[i];        //store values in temp
            }

            for (int i = arrayLengthTurtle; i < doubleSize; i++) {
                tempTurtle[i] = NULL;        //set temp array's empty cages to null
            }

            delete[] turtleArray;   //delete previous array

            turtleArray = tempTurtle; //refill with doubled size and same animals
            arrayLengthTurtle = doubleSize;
        }

        if (turtleCounter == 0) {
            for (int i = 0; i < turtleCounter + 1; i++) {
                if (turtleArray[i] == NULL) {
                    Turtle *turt = new Turtle(a);
                    turtleArray[turtleCounter] = turt;
                    std::cout << "Turtle added to the Zoo!" << std::endl;
                }
            }
            turtleCounter++;
        }
        else if (turtleArray[turtleCounter] == NULL)
        {
            turtleArray[turtleCounter] = new Turtle(a);
            std::cout << "Turtle added to the Zoo!" << std::endl;
            turtleCounter++;
            if (a == 3)
            {
            	bought = 2;
            	bankAccount = bankAccount - turtleArray[0]->getCost();	//cost of tiger subtracted
            }
        }
    }
    else if (a ==3)
        std::cout << "Insufficient Funds for Turtle" << std::endl;
}

void Zoo::subTiger()	//removes a tiger
{
    if (tigerCounter > 0)
    {
        delete tigerArray[tigerCounter];
        tigerArray[tigerCounter] = NULL;
        tigerCounter--;
    }
    else
        std::cout << "There are no Tigers left." << std::endl;
}

void Zoo::subPenguin()	//removes a penguin
{
    if (penguinCounter > 0)
    {
        delete penguinArray[penguinCounter];
        penguinArray[penguinCounter] = NULL;
        penguinCounter--;
    }
    else
        std::cout << "There are no Penguins left." << std::endl;
}

void Zoo::subTurtle()	//removes a turtle
{
    if (turtleCounter > 0)
    {
        delete turtleArray[turtleCounter];
        turtleArray[turtleCounter] = NULL;
        turtleCounter--;
    }
    else
        std::cout << "There are no Turtles left." << std::endl;
}

void Zoo::pickFeedType(int t)
{
    switch (t)
    {
        case 1 : //cheap
            feedCost = tigerArray[0]->getBaseFoodCost() / 2;
            sicknessMod = 2;	//sickness modifier
            break;

        case 2 : //generic
            feedCost = tigerArray[0]->getBaseFoodCost();
            break;
        case 3: //premium
            feedCost = tigerArray[0]->getBaseFoodCost() * 2;
            sicknessMod = 1;	//sickness modifier
            break;
    }

}

/**************************************************************************************/

//functions
int Zoo::zooMenu()
{
    int menuC = 0;

    //menu
    std::cout << "Zoo Tycoon" << std::endl;
    std::cout << "Please choose one of the following options" << std::endl;
    std::cout << "1. Play Game" << std::endl;
    std::cout << "2. Exit Game" << std::endl;

    menuC = inputValidation();  //input validation

    std::cout << std::endl;
    std::cout << std::endl;

    return menuC;
}

void Zoo::startZoo()
{
    std::cout << "Please pick your three starting animals." << std::endl;
    std::cout << "Tiger: Please choose the quanity - 1 or 2 Tigers." << std::endl;
    int tigerQuantity = inputValidation();
    switch (tigerQuantity)
    {
        case 1 :
            addTiger(1);
            bankAccount = bankAccount - tigerArray[0]->getCost();	//cost of tiger subtracted tiger.setCost(10000)
            break;

        case 2 :
            std::cout << "Two Tigers purchased!" << std::endl;
            for(int i = 0; i < 2; i++)
            {
                addTiger(1);
                bankAccount = bankAccount - tigerArray[0]->getCost();	//cost of tiger subtracted
            }
            break;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Penguin: Please choose the quanity - 1 or 2 Penguins." << std::endl;
    int penguinQuantity = inputValidation();
    switch (penguinQuantity)
    {
        case 1 :
            addPenguin(1);
            bankAccount = bankAccount - penguinArray[0]->getCost();	//cost of penguin subtracted
            break;

        case 2 :
            std::cout << "Two Penguins purchased!" << std::endl;
            for (int i = 0; i < 2; i++)
            {
                addPenguin(1);
                bankAccount = bankAccount - penguinArray[0]->getCost();	//cost of penguin subtracted
            }
            break;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Turtle: Please choose the quanity - 1 or 2 Turtles." << std::endl;
    int turtleQuantity = inputValidation();
    switch (turtleQuantity)
    {
        case 1 :
            addTurtle(1);
            bankAccount = bankAccount - turtleArray[0]->getCost();	//cost of turtle subtracted
            break;

        case 2 :
            std::cout << "Two Turtles purchased!" << std::endl;
            for (int i = 0; i < 2; i++)
            {
                addTurtle(1);
                bankAccount = bankAccount - penguinArray[0]->getCost();	//cost of turtle subtracted
            }
            break;
    }

    std::cout << std::endl;
    std::cout << std::endl;
}

void Zoo::incrementZooDay()	//increments zoo day and animal ages
{
    if (zooDay > -1)
    {
        zooDay++;
        std::cout << "Zoo Day: " << zooDay << std::endl;
        for (int i = 0; i < tigerCounter; i++)
        {
            tigerArray[i]->setAge();
        }
        for (int i = 0; i < penguinCounter; i++)
        {
            penguinArray[i]->setAge();
        }
        for (int i = 0; i < turtleCounter; i++)
        {
            turtleArray[i]->setAge();
        }
    }
}

void Zoo::feedChosen()
{
    int feedType = 0;
    std::cout << "Please pick your animal feed type." << std::endl;
    std::cout << "1. Cheap" << std::endl;
    std::cout << "2. Generic" << std::endl;
    std::cout << "3. Premium" << std::endl;

    //input val for feed type
    feedType = feedChoice();

    switch (feedType)
    {
        case 1 : //cheap
            std::cout << "Cheap animal feed chosen." << std::endl;
            pickFeedType(1);	//sets to half of base cost
            break;
        case 2 : //generic
            std::cout << "Generic animal feed chosen." << std::endl;
            pickFeedType(2);	//base cost unchanged
            break;
        case 3 : //premium
            std::cout << "Premium animal feed chosen." << std::endl;
            pickFeedType(3);	//sets to double the base cost
            break;
    }

    std::cout << std::endl;
    std::cout << std::endl;
}

void Zoo::payFeedingCost()
{
    int tigerFoodCost = 0;
    int penguinFoodCost = 0;
    int turtleFoodCost = 0;
    int totalFoodCost = 0;

    tigerFoodCost = (tigerCounter * tigerArray[0]->getTigerFoodMod() * feedCost);

    std::cout << "Tiger Food Cost: " << tigerFoodCost << std::endl;

    penguinFoodCost = (penguinCounter * penguinArray[0]->getPenguinFoodMod() * feedCost);

    std::cout << "Penguin Food Cost: " << penguinFoodCost << std::endl;

    turtleFoodCost = (turtleCounter * feedCost/2);       ///fix turtle modifier

    std::cout << "Turtle Food Cost: " << turtleFoodCost << std::endl;

    totalFoodCost = tigerFoodCost + penguinFoodCost + turtleFoodCost;

    std::cout << "Total Food Cost: " << totalFoodCost << std::endl;

    bankAccount = bankAccount - totalFoodCost;

    std::cout << "Updated Bank Account: " << bankAccount << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
}

void Zoo::randomEvent()
{
    int randomChoice = 0;
    std::cout << "A random event is occurring....." << std::endl;

    if(sicknessMod == 2)
    {
        randomChoice = (rand() % 3 + 1);
        if (randomChoice != 1)
        {
            randomChoice--;
        }
    }
    else if (sicknessMod == 1)
    {
        randomChoice = (rand() % 3 + 1);
        if (randomChoice != 3)
        {
            randomChoice++;
        }
    }
    else if (sicknessMod == 0)
    {
        randomChoice = (rand() % 3 + 1);
    }

    switch(randomChoice)
    {
        case 1 :	//death function
            std::cout << "Sickness strikes the zoo!" << std::endl;
            animalDeath();	//randomly removes one animal from their array
            break;

        case 2 :	//attendance bonus
            zooAttendance();
            break;

        case 3 :	//birth function
            animalBirth();	//randomly adds one animal from their array
            break;
    }

    std::cout << std::endl;
    std::cout << std::endl;
}

void Zoo::animalDeath()
{
    int randChoice = (rand() % 3 + 1);

    switch(randChoice)	//animals 1-3 (tiger, penguin, turtle)
    {
        case 1 : //tiger
            if(tigerCounter == 0)
            {
                std::cout << "No more tigers remain." << std::endl;
                break;
            }
            else
            {
                std::cout << "A Tiger has died." << std::endl;
                subTiger();
                break;
            }
        case 2 : //penguin
            if(penguinCounter == 0)
            {
                std::cout << "No more penguins remain." << std::endl;
                break;
            }
            else
            {
                std::cout << "A Penguin has died." << std::endl;
                subPenguin();
                break;
            }
        case 3 : //turtle
            if(turtleCounter == 0)
            {
                std::cout << "No more turtles remain." << std::endl;
                break;
            }
            else
            {
                std::cout << "A Turtle has died." << std::endl;
                subTurtle();
                break;
            }
    }
}

void Zoo::zooAttendance()
{
    std::cout << "An attendance boost has occurred!" << std::endl;
    int bonusAmount = (rand() % 500 + 250);
    int numberOfTigers = tigerCounter;
    std::cout << "Guests love the tigers!" << std::endl;
    std::cout << "Bonus money earned: " << (bonusAmount*numberOfTigers) << std::endl;
    bonusProfit = (bonusAmount*numberOfTigers);
}

void Zoo::animalBirth()
{
    int randChoice = (rand() % 3 + 1);

    switch(randChoice)	//animals 1-3 (tiger, penguin, turtle)
    {
        case 1 : //tiger
            for (int i = 0; i < tigerCounter; i++)
            {
                if(tigerArray[i]->getAge() > 2)
                {
                    std::cout << "A Tiger has been born!" << std::endl;
                    addTiger(2);
                    //i = tigerCounter;
                    break;
                }
                else if (i == tigerCounter -1)
                    std::cout << "No adult tigers available to breed." << std::endl;
            }
            break;

        case 2 : //penguin
            for (int i = 0; i < penguinCounter; i++)
            {
                if(penguinArray[i]->getAge() > 2)
                {
                    std::cout << "5 Penguins have been born!" << std::endl;
                    for (int i = 0; i < 5; i++) {
                        addPenguin(2);
                    }
                    break;
                }
                else if (i == penguinCounter -1)
                    std::cout << "No adult penguins available to breed." << std::endl;
            }
            break;

        case 3 : //turtle
            for (int i = 0; i < turtleCounter; i++)
            {
                if(turtleArray[i]->getAge() > 2)
                {
                    std::cout << "10 Turtles have been born!" << std::endl;
                    for (int i = 0; i < 10; i++)
                    {
                        addTurtle(2);
                    }
                    break;
                }
                else if (i == turtleCounter -1)
                    std::cout << "No adult turtles available to breed." << std::endl;
            }
            break;
    }
}

void Zoo::buyAnimal()	//needs to fix cases for animal purchase
{
    std::cout << "Would you like to buy an adult animal?" << std::endl;
    std::cout << "1. Yes." << std::endl;
    std::cout << "2. No." << std::endl;
    int buyAnimal = inputValidation();

    std::cout << std::endl;
    std::cout << std::endl;

    do
    {
	    switch (buyAnimal)
	    {
	        case 1 : //yes buy animal
	        {

	            std::cout << "Please pick an animal to buy." << std::endl;
	            std::cout << "1. Tiger" << std::endl;
	            std::cout << "2. Penguin" << std::endl;
	            std::cout << "3. Turtle" << std::endl;

	            //setup input validation
	            int animalCh = animalChoice();

	            switch(animalCh)
	            {
	                case 1 : //tiger bought
	                    std::cout << "Attempting to buy a tiger!" << std::endl;
	                    addTiger(3);	//adds a tiger to tiger array
	                    //bankAccount = bankAccount - tigerArray[0]->getCost();	//cost of tiger subtracted
	                    break;

	                case 2 : //penguin bought
	                    std::cout << "Attempting to buy a penguin!" << std::endl;
	                    addPenguin(3); //adds a penguin to penguin array
	                    //bankAccount = bankAccount - penguinArray[0]->getCost();	//cost of penguin subtracted
	                    break;

	                case 3 : //turtle bought
	                    std::cout << "Attempting to buy a turtle!" << std::endl;
	                    addTurtle(3); //turtle bought
	                    //bankAccount = bankAccount - turtleArray[0]->getCost();	//cost of turtle subtracted
	                    break;
	            }
	        }
	            break;

	        case 2 : //no do not buy
	            std::cout << "No animal purchased." << std::endl;
	            bought = 2;
	            break;
	    }
	    if (bought == 1)
	    {
	    		std::cout << "Sorry, you can't afford that one." << std::endl;
	    	    std::cout << "Would you like to buy a different animal?" << std::endl;
	    	    std::cout << "1. Yes" << std::endl;
	    	    std::cout << "2. No" << std::endl;

	    	    bought = inputValidation();
	    }
	}while(bought == 1);

	std::cout << std::endl;
    std::cout << std::endl;
}

void Zoo::calculateProfit()
{
    int tigerPayoff = 0;
    int penguinPayoff = 0;
    int turtlePayoff = 0;
    int total = 0;
    std::cout << "Today's Profit" << std::endl;

    tigerPayoff = tigerArray[0]->getPayoff()*tigerCounter;
    penguinPayoff = penguinArray[0]->getPayoff()*penguinCounter;
    turtlePayoff = turtleArray[0]->getPayoff()*turtleCounter;
    std::cout << "Tiger Profit: " << tigerPayoff << std::endl;
    std::cout << "Penguin Profit: " << penguinPayoff << std::endl;
    std::cout << "Turtle Profit: " << turtlePayoff << std::endl;
    std::cout << "Bonus Profit: " << bonusProfit << std::endl;

    total = tigerPayoff + penguinPayoff + turtlePayoff + bonusProfit;

    std::cout << "Total Profit: " << total << std::endl;

    bankAccount = bankAccount + total;

    std::cout << "BankAccount: " << bankAccount << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
}

int Zoo::endGameMenu()
{
    int menuE = 0;

    //menu
    if (bankAccount == 0)
    {
        std::cout << "Zoo Tycoon" << std::endl;
        std::cout << "GAME OVER" << std::endl;

        return 2;
    }
    else
    {
        std::cout << "Zoo Tycoon" << std::endl;
        std::cout << "Please choose one of the following options" << std::endl;
        std::cout << "1. Play Another Day" << std::endl;
        std::cout << "2. Exit Game" << std::endl;

        menuE = inputValidation();

        std::cout << std::endl;
    	std::cout << std::endl;

        return menuE;
    }
}

void Zoo::quit()
{
    std::cout << "Quit Zoo Tycoon" << std::endl;
}


void Zoo::zooSim()
{
    int endMenuChoice = 1;

    startZoo();	//prompts user for starting 3 animals

    do
    {
        incrementZooDay();	//increases the zoo day by 1 and increases animal ages
        feedChosen();		//player chooses the type of animal feed
        payFeedingCost();	//payFeedCost
        randomEvent();		//randomEvent
        buyAnimal();		//buyAnimal
        calculateProfit();	//calculateProfit

        if(bankAccount < 0)
	    {
	        std::cout << "No money left! Game over!" << std::endl;
	        endMenuChoice = 2;
	    }
	    else
	    {
		    endMenuChoice = endGameMenu();	//ends game due to lack of money or ask player to continue
	        feedCost = 0;		//resets feed type
	        sicknessMod = 0;	//reset mods
	        bonusProfit = 0;    //resets bonus
	        bought = 1;
	    }
    }
    while(bankAccount > 0 && endMenuChoice == 1);
}