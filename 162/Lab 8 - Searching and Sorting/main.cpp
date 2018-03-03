/*********************************************************************
** Program name: Searching and Sorting
** Author: Devin Gendron
** Date: 3/4/18
** Description: Using algorithms to search data and sort data.
*********************************************************************/
#include <iostream>
#include "Menus.h"
#include "InputValidation.h"
#include <string>
#include <fstream>
#include <vector>

int main()
{
    int menuC = 0;
    int endGame = 0;
    int n = 0;
    int case1 = 0;
    int case2 = 0;
    int case3 = 0;
    int case4 = 0;
    std::vector<int> early;
    std::vector<int> mid;
    std::vector<int> end;
    std::vector<int> none;
    std::string iFileName;
    std::ifstream earlyFile;
    std::ifstream midFile;
    std::ifstream endFile;
    std::ifstream noneFile;
    std::ofstream earlyOutput;
    std::ofstream midOutput;
    std::ofstream endOutput;
    std::ofstream noneOutput;

    do
    {
        std::cout << "* Welcome to my Searching and Sorting Program! *" << std::endl;
        std::cout << "* Please choose one of the following options. *" << std::endl;
        std::cout << "1. Read Values from Files." << std::endl;
        std::cout << "2. Simple Search" << std::endl;
        std::cout << "3. Sorting" << std::endl;
        std::cout << "4. Binary Search" << std::endl;
        std::cout << "5. Quit Searching and Sorting Program." << std::endl;

        menuC = menu(); //Main menu
        std::cout << std::endl;

        switch (menuC)
        {
            case 1 :  //Read values from the 4 files
                if (case1 == 0)
                {
                    for (int i = 1; i < 5; i++)
                    {
                        switch(i)
                        {
                            case 1 :
                                readFiles(earlyFile, early, "Early.txt");
                                std::cout << std::endl;
                                /*std::cout << "test print outside: " << std::endl;
                                for (int j = 0; j < early.size(); j++)
                                {
                                    std::cout << early[j] << std::endl;
                                }*/
                                break;
                            case 2 :
                                readFiles(midFile, mid, "Middle.txt");
                                std::cout << std::endl;
                                break;
                            case 3 :
                                readFiles(endFile, end, "End.txt");
                                std::cout << std::endl;
                                break;
                            case 4 :
                                readFiles(noneFile, none, "None.txt");
                                std::cout << std::endl;
                                break;
                            default :
                                std::cout << "Error: Please try again." << std::endl;
                                std::cout << std::endl;
                                break;
                        }
                    }
                    case1++;
                    std::cout << std::endl;
                }
                else
                {
                    std::cout << "Files have already been read." << std::endl;
                    std::cout << std::endl;
                }
                break;

            case 2 :  //Simple Search
                if (case1 == 0)
                {
                    std::cout << "Please Use Option 1 to read in files before attempting to search." << std::endl;
                    std::cout << std::endl;
                }
                else
                {
                    std::cout << "Please enter an integer to search for." << std::endl;
                    n = inputValidation();
                    std::cout << std::endl;
                    for (int i = 1; i < 5; i++)
                    {
                        switch(i)
                        {
                            case 1 :
                                simpleSearch(n, early, "Early.txt");
                                break;
                            case 2 :
                                simpleSearch(n, mid, "Mid.txt");
                                break;
                            case 3 :
                                simpleSearch(n, end, "End.txt");
                                break;
                            case 4 :
                                simpleSearch(n, none, "None.txt");
                                break;
                            default :
                                std::cout << "Error: Please try again." << std::endl;
                                break;
                        }
                    }
                    case2++;
                    std::cout << std::endl;
                }
                break;

            case 3 :  //Sorting
                if (case1 == 0)
                {
                    std::cout << "Please Use Option 1 to read in files before attempting to sort." << std::endl;
                    std::cout << std::endl;
                }
                else if (case3 == 1)
                {
                    std::cout << "You have already completed a sort of these files." << std::endl;
                    std::cout << std::endl;
                }
                else
                {
                    for (int i = 1; i < 5; i++)
                    {
                        switch(i)
                        {
                            case 1 :
                                sorting(earlyOutput, early, "Early.txt");
                                std::cout << std::endl;
                                break;
                            case 2 :
                                sorting(midOutput, mid, "Mid.txt");
                                std::cout << std::endl;
                                break;
                            case 3 :
                                sorting(endOutput, end, "End.txt");
                                std::cout << std::endl;
                                break;
                            case 4 :
                                sorting(noneOutput, none, "None.txt");
                                std::cout << std::endl;
                                break;
                            default :
                                std::cout << "Error: Please try again." << std::endl;
                                std::cout << std::endl;
                                break;
                        }
                    }
                    case3++;
                    std::cout << std::endl;
                }
                break;

            case 4 :  //Binary Search
                if (case1 == 0 && case3 == 0)
                {
                    std::cout << "Please Use Previous options to prepare files before Binary Search." << std::endl;
                }
                else
                {
                    std::cout << "Please enter an integer to search for." << std::endl;
                    n = inputValidation();
                    std::cout << std::endl;
                    for (int i = 1; i < 5; i++)
                    {
                        switch(i)
                        {
                            case 1 :
                                binarySearch(n, early, "Early.txt");
                                break;
                            case 2 :
                                binarySearch(n, mid, "Mid.txt");
                                break;
                            case 3 :
                                binarySearch(n, end, "End.txt");
                                break;
                            case 4 :
                                binarySearch(n, none, "None.txt");
                                break;
                            default :
                                std::cout << "Error: Please try again." << std::endl;
                                break;
                        }
                    }
                    case4++;
                    std::cout << std::endl;
                }
                break;

            case 5 :  //Quit Program
                std::cout << "Searching and Sorting Program quit." << std::endl;
                endGame = 1;
                break;

            default :  //default
                std::cout << "Error: Please try again." << std::endl;
                break;
        }

    }while(endGame == 0);

    return 0;
}