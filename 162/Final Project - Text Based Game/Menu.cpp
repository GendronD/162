/*************************************************************************
** Program name: Final Project - Text Based Game
** Author: Devin Gendron
** Date: 3/21/18
** Description: Design a game with pointer-linked spaces and OOP Concepts
*************************************************************************/
#include "Menu.h"
#include <iostream>
#include <sstream>
#include <iomanip>

int main_menu()
{
    int menu = 0;
    int exitCount = 0;

    //menu
    std::cout << "Knight of The Code Table" << std::endl;
    std::cout << "1. Play!" << std::endl;
    std::cout << "2. Quit." << std::endl;

    do
    {
        exitCount = 0;//sets to continue while loop in do-while
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

        if (menu >= 1 && menu <= 2) {exitCount = 0;}
        else
        {
            exitCount = 1;
            std::cout << "Please use proper menu range." << std::endl;
        }

    } while(exitCount == 1);

    return menu;
}
int char_choice()
{
    int menu = 0;
    int exitCount = 0;

    //menu
    std::cout << "Knight of The Code Table" << std::endl;
    std::cout << "1. Move Top!" << std::endl;
    std::cout << "2. Move Bottom!" << std::endl;
    std::cout << "3. Move Right!." << std::endl;
    std::cout << "4. Move Left!" << std::endl;

    do
    {
        exitCount = 0;//sets to continue while loop in do-while
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

        if (menu >= 1 && menu <= 4) {exitCount = 0;}
        else
        {
            exitCount = 1;
            std::cout << "Please use proper menu range." << std::endl;
        }

    } while(exitCount == 1);

    return menu;
}
int contCombat()
{
    int choice = 0;
    int exitCount = 0;

    //menu
    std::cout << "1. Press 1 for Sircodesalot to attack!" << std::endl;

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
                ss >> choice;
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

        if (choice == 1)
        {
            exitCount = 0;
        }
        else
        {
            exitCount = 1;
            std::cout << "Please use proper menu range." << std::endl;
        }

    } while(exitCount == 1);

    return choice;
}