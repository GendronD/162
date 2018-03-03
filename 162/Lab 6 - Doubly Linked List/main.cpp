/*********************************************************************
** Program name: Doubly-linked Lists
** Author: Devin Gendron
** Date: 2/18/17
** Description: Practice using Linked lists, in this case a
** doubly-linked list and variations of node management.
*********************************************************************/
#include <iostream>
#include "MenuPrompts.h"
#include "InputValidation.h"
#include "Node.h"
#include <string>
#include <fstream>

int main()
{
    int menuC = 0;
    int endGame = 0;
    int n = 0;
    std::string iFileName;
    std::ifstream inputFile;
    Node nodeList;

    do
    {
        std::cout << "* Welcome to my Doubly-Linked List Program! *" << std::endl;
        std::cout << "* Please choose one of the following options. *" << std::endl;
        std::cout << "1. Add a new node to the head." << std::endl;
        std::cout << "2. Add a new node to the tail." << std::endl;
        std::cout << "3. Delete from head." << std::endl;
        std::cout << "4. Delete from tail." << std::endl;
        std::cout << "5. Traverse the list reversely." << std::endl;
        std::cout << "6. Print Head." << std::endl;
        std::cout << "7. Print Tail." << std::endl;
        std::cout << "8. Use text file to fill linked list." << std::endl;
        std::cout << "9. Exit." << std::endl;

        //traverse the list (print)
        nodeList.traverse();

        menuC = menu(); //Main menu

        switch (menuC)
        {
            case 1 :  //Add node to head
                std::cout << "Please enter a number to add to the head." << std::endl;
                n = inputValidation();
                nodeList.addHead(n);
                break;

            case 2 :  //Add node to tail
                std::cout << "Please enter a number to add to the tail." << std::endl;
                n = inputValidation();
                nodeList.addTail(n);
                break;

            case 3 :  //Delete from head
                nodeList.deleteHead();
                break;

            case 4 :  //Delete from tail
                nodeList.deleteTail();
                break;

            case 5 :  //Traverse list reversely
                nodeList.reverseTraverse();
                break;

            case 6 :  //Print Head
                nodeList.printHead();
                break;

            case 7 :  //Print Tail
                nodeList.printTail();
                break;

            case 8 : //Add to node by file
                /*std::cout << "Please enter the file you would like to read: " << std::endl;
                std::cin >> iFileName;*/

                //open file
                inputFile.open("LinkedList.txt");

                if(inputFile.fail())
                {
                    std::cout << "The file could not be opened." << std::endl;
                    return 1;
                }
                else if(!inputFile.fail())
                {
                    std::cout << iFileName << " successfully opened." << std::endl;
                    while (!inputFile.eof())
                    {
                        std::cout << "Now reading file..." << std::endl;
                        inputFile >> n;
                        //n = inputValidation();
                        nodeList.addHead(n);

                    }
                    inputFile.close();
                }
                std::cout << "File read complete." << std::endl;
                break;

            case 9 : //Exit Program
                std::cout << "Doubly-Linked Lists Program quit." << std::endl;
                endGame = 1;
                break;
        }

    }while(endGame == 0);

    return 0;
}