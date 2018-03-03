/*********************************************************************
** Program name: OSU Information System
** Author: Devin Gendron
** Date: 2/4/17
** Description: Information System of OSU
*********************************************************************/
#include <iostream>
#include "University.h"
#include "Menu.h"
#include "inputValidation.h"
//#include <vector>

int main()
{
    srand(time(NULL));	//Time seed
    int menuC = 0;
    int choice = 0;
    std::string worker = " ";

    Person *p1 = new Student("Devin", 24);
    Person *p2 = new Instructor("Gail", 66);

    Building *b1 = new Building("Adams Hall", "606 SW 15th St. Corvallis, Oregon 97331", 11168);
    Building *b2 = new Building("Aero Engineering Lab", "852 SW 30th St. Corvallis, Oregon 97331", 3637);
    University university;	//University object

    university.addPerson(p1);
    university.addPerson(p2);
    university.addBuilding(b1);
    university.addBuilding(b2);

    do {
        menuC = menu();		            //Main menu

        switch (menuC) {
            case 1 :                        //Prints information about all OSU buildings
                university.printBuildings();
                std::cout << std::endl;
                break;

            case 2 :                        //Prints information on people at the university
                university.printPeople();
                std::cout << std::endl;
                break;

            case 3 :                        //Chooses a person to do work
                university.printPeople();
                std::cout << "Please choose the person to work with. (1 or 2)" << std::endl;
                choice = inputValidation();
                university.getPerson(choice)->do_work();
                std::cout << std::endl;
                break;

            case 4 :  //Exit the program
                std::cout << "OSU Information System Quit" << std::endl;
                menuC = 5;
                break;
        }
    }while (menuC != 5);

    //delete p1;
    //delete p2;
    //delete b1;
    //delete b2;

    return 0;
}