/*********************************************************************
** Program name: Searching and Sorting
** Author: Devin Gendron
** Date: 3/4/18
** Description: Using algorithms to search data and sort data.
*********************************************************************/
#include "Menus.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <fstream>

int menu()
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

        if (menu >= 1 && menu <= 5)
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

void readFiles(std::ifstream &f, std::vector<int> &file, std::string name)
{
    f.open(name);
    int values = 0;

    if(f.fail())
    {
        std::cout << "The file could not be opened." << std::endl;
    }
    else if(!f.fail())
    {
        std::cout << name << " successfully opened." << std::endl;
        std::cout << "Now reading file..." << std::endl;
        while (f >> values)
        {
            std::cout << "Values: " << values << std::endl;
            file.push_back(values);
        }
        f.close();
        std::cout << name << " read complete." << std::endl;
    }
    //for tests
    /*std::cout << "test print inside: " << std::endl;
    for (int i = 0; i < file.size(); i++)
    {
        std::cout << file[i] << std::endl;
    }*/
}

void simpleSearch(int n, std::vector<int> &file, std::string name)
{
    bool found;
    for(int i = 0; i < file.size(); i++)
    {
        if (n == file[i])
        {
            found = true;
            break;
        }
        else
        {
            found = false;
        }
    }
    //print if target found or not
    if (found == false)
    {
        std::cout << name << ": target value not found." << std::endl;
    }
    else if(found == true)
    {
        std::cout << name << ": target value found." << std::endl;
    }
}
///https://stackoverflow.com/questions/30963204/c-vector-bubble-sort
void bubbleSort(std::vector<int> &file)
{
    bool swapp = true;
    while(swapp)
    {
        swapp = false;
        for (int i = 0; i < file.size()-1; i++)
        {
            if (file[i]>file[i+1])
            {
                file[i] += file[i+1];
                file[i+1] = file[i] - file[i+1];
                file[i] -=file[i+1];
                swapp = true;
            }
        }
    }
}
///https://stackoverflow.com/questions/30963204/c-vector-bubble-sort
void printVector(std::vector<int> &file)
{
    std::cout<< "BubbleSorted: ";
    for (int i = 0; i < file.size(); i++)
    {
        std::cout<<file[i]<<" ";
    }
    std::cout<<std::endl;
}
void sorting(std::ofstream &oFile, std::vector<int> &file, std::string name)  //merge sort
{
    std::string userNamed;
    std::cout << "Please enter a name for " << name << "'s output file." << std::endl;
    std::cin >> userNamed;
    std::cout << std::endl;

    ///https://stackoverflow.com/questions/30963204/c-vector-bubble-sort
    bubbleSort(file);
    printVector(file);
    std::cout << std::endl;

    //open file and fill for each paragraph
    oFile.open(userNamed);

    if(oFile.fail())
    {
        std::cout << "The file could not be opened." << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << userNamed << " successfully opened." << std::endl;
        std::cout << "Now writing to file..." << std::endl;
        for (int j = 0; j < file.size(); j++)
        {
            std::cout << file[j] << std::endl;
            oFile << file[j];
            oFile << " ";
        }
        oFile.close();
        std::cout << "File read and write complete." << std::endl;
    }
}
///https://stackoverflow.com/questions/18774858/using-binary-search-with-vectors
bool bSearch(int n, std::vector<int> &file) {
    size_t mid, left = 0 ;
    size_t right = file.size(); // one position passed the right end
    while (left < right) {
        mid = left + (right - left)/2;
        if (n > file[mid]){
            left = mid+1;
        }
        else if (n < file[mid]){
            right = mid;
        }
        else {
            return true;
        }
    }

    return false;
}
void binarySearch(int n, std::vector<int> &file, std::string name)
{
    bool found;
    //use binarySearch function to check sorted files
    ///https://stackoverflow.com/questions/18774858/using-binary-search-with-vectors
    found = bSearch(n, file);

    //print if target found or not
    if (found == false)
    {
        std::cout << name << ": target value not found." << std::endl;
    }
    else if (found == true)
    {
        std::cout << name << ": target value found." << std::endl;
    }
}
