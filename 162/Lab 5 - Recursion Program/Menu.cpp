/*********************************************************************
** Program name: Recursive Functions
** Author: Devin Gendron
** Date: 2/11/17
** Description: Recursive Functions: Three separate functions -
** 1. Reverse String, 2. Array Sums, 3. Triangular Num Calculator
*********************************************************************/
#include <iostream>
#include <sstream>
#include "Menu.h"
#include "Recursive.h"
#include "InputValidation.h"
#include <iomanip>

int menu()
{
    int menu = 0;
    int exitCount = 0;

    //menu
    std::cout << "--Recursive Menu System--" << std::endl;
    std::cout << "1. Reverse a string Recursive Function" << std::endl;
    std::cout << "2. Array sum Recursive Function." << std::endl;
    std::cout << "3. Triangular Num Calculator." << std::endl;
    std::cout << "4. Exit the program." << std::endl;

    do
    {
        exitCount = 0;			//sets to continue while loop in do-while
        while (exitCount == 0)
        {
            int correctEntry = 0;
            int incorrectEntry = 0;
            std::string str = " ";

            //arrays to check string
            char numEntry[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

            char letterEntry[] =
                    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                     'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                     'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

            char symEntry[] = {'`', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
                               '{', '}', '[', ']', '"', '<', '>', ',', '.', '?', '/', ' ', '-', '_', '+', '='};
            //removed: '\', '|', ';', ':', ''',

            //reads in user input
            getline(std::cin, str);
            std::stringstream ss(str);

            //checks for empty strings
            bool badEntry = false;
            if (str.empty())
            {
                badEntry = true;
            }

            //checks for proper ints or incorrect entries
            for (int t = 0; t < str.size(); t++)
            {
                for (int m = 0; m < 10; m++)
                {
                    if (str[t] == numEntry[m])
                    {
                        correctEntry ++;
                    }
                }
                for (int y = 0; y < 52; y++)
                {
                    if (str[t] == letterEntry[y])
                    {
                        incorrectEntry ++;
                    }
                }
                for (int n = 0; n < 28; n++)
                {
                    if (str[t] == symEntry[n])
                    {
                        incorrectEntry ++;
                    }
                }
            }
            if (badEntry)
            {
                std::cout << "Please enter at least one integer." << std::endl;
                exitCount = 0;
            }
            else if (correctEntry == str.size())
            {
                ss >> menu;
                //std::cout << "Correct Input." << std::endl;
                exitCount++;
            }
            else if (incorrectEntry > 0)
            {
                std::cout << "Incorrect Entry." << std::endl;
                std::cout << "Please enter an integer: No characters, symbols, doubles, floats, or decimals." << std::endl;
                exitCount = 0;
            }
        }

        if (menu >= 1 && menu <= 4)
        {
            exitCount = 0;
        }
        else
        {
            exitCount = 1;
            std::cout << "Please use proper menu range." << std::endl;
        }

    } while(exitCount == 1);

    return menu;
}

void reverser()
{
    std::string reverse = " ";

    std::cout << "Please enter a string to reverse." << std::endl;
    std::getline(std::cin, reverse);

    reverse = reverseString(reverse);

    std::cout << reverse << std::endl;
}
void summation()
{
    int arraySize = 0;
    int sum = 0;

    std::cout << "Please enter a size for the array." << std::endl;
    arraySize = inputValidation();

    int *arrayS = new int[arraySize];

    std::cout << "Please fill the array with integers." << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        arrayS[i] = inputValidation();
    }

    sum = arraySum(arrayS, arraySize);

    std::cout << "The Sum of the array is: " << sum << std::endl;

    delete [] arrayS;
}
void triangular()
{
    int N = 0;
    int tN = 0;

    std::cout << "Please enter an integer to calculate its triangular number." << std::endl;
    N = inputValidation();

    tN = triangularCalc(N);

    std::cout << "The triangular number of " << N << " is: " << tN << std::endl;
}