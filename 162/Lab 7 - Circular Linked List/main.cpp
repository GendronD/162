/*********************************************************************
** Program name: Circular Linked List
** Author: Devin Gendron
** Date: 2/25/18
** Description: Use circular linked list to create a queue data struct.
*********************************************************************/
#include <iostream>
#include "MenuPrompts.h"
#include "InputValidation.h"
#include "Queue.h"

int main()
{
    int menuC = 0;
    int endGame = 0;
    int n = 0;
    Queue circList;

    do
    {
        std::cout << "* Welcome to the Circular Linked list! *" << std::endl;
        std::cout << "* Please choose one of the following options. *" << std::endl;
        std::cout << "1. Add a value to the back of the queue." << std::endl;
        std::cout << "2. Display the front value." << std::endl;
        std::cout << "3. Remove the front node." << std::endl;
        std::cout << "4. Display the queues contents." << std::endl;
        std::cout << "5. Exit." << std::endl;

        menuC = menu(); //Main menu input validation

        switch (menuC)
        {
            case 1 :  //Add node to queue
                std::cout << std::endl;
                std::cout << "Please enter a value to add to the queue." << std::endl;
                n = inputValidation();
                circList.addBack(n);
                break;

            case 2 :  //Print first in queue
                //std::cout << "First in the queue is: ";
                circList.getFront();
                break;

            case 3 :  //Delete first in queue
                circList.removeFront();
                break;

            case 4 :  //Display queues contents
                //std::cout << "Queue displayed: ";
                circList.printQueue();
                break;

            case 5 : //Exit Program
                std::cout << std::endl;
                std::cout << "Circular Linked List Program quit." << std::endl;
                std::cout << std::endl;
                endGame = 1;
                break;

            default:
                std::cout << "How'd you reach this?? Try another input!" << std::endl;
                break;
        }
    }while(endGame == 0);

    return 0;
}