/*********************************************************************
** Program name: Algorithm Efficiency
** Author: Devin Gendron
** Date: 3/19/18
** Description: Implement a recursive and iterative implementation of
** Fibonacci Numbers Calculation and measure/compare run  time.
*********************************************************************/
#include "InputValidation.h"
#include <iostream>
#include <sstream>
#include <iomanip>
int InputValidation()
{
    {
        int menu = 0;
        int exitCount = 0;

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

            if (menu >= 0 && menu <= 45)
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
}