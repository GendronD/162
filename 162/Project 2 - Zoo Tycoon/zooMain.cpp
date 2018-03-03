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
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));				//Time seed
    Zoo zoo;						//Zoo object

    int menuC = zoo.zooMenu();		//Main menu (compeleted)

    switch (menuC)
    {
        case 1 : 					//Play Game
            zoo.zooSim();			//Runs zoo simulation
            break;

        case 2 : 					//Quit Game
            zoo.quit();				//Quit message
            break;
    }

    return 0;
}