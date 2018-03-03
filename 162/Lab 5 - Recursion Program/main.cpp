/*********************************************************************
** Program name: Recursive Functions
** Author: Devin Gendron
** Date: 2/11/17
** Description: Recursive Functions: Three separate functions -
** 1. Reverse String, 2. Array Sums, 3. Triangular Num Calculator
*********************************************************************/
#include "Menu.h"
#include "Recursive.h"
#include <iostream>

int main()
{
    int menuC = 0;

    do
    {
        menuC = menu(); //Main menu

        switch (menuC)
        {
            case 1 :    //Reverse String
                reverser();
                std::cout << std::endl;
                break;

            case 2 :    //Array Sum
                summation();
                std::cout << std::endl;
                break;

            case 3 :    //Triangular Calc
                triangular();
                std::cout << std::endl;
                break;

            case 4 :  //Exit the program
                std::cout << "Recursive Function Program Quit." << std::endl;
                menuC = 5;
                break;
        }
    } while (menuC != 5);

    return 0;
}