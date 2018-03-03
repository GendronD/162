/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Devin Gendron
** Date: 3/5/18
** Description: Using dice rolls, have characters battle it out... in
** a tournament!
*********************************************************************/
#include "Queue.h"
#include <iostream>

//constructor
Queue::Queue()
{
    head = nullptr;
}
//destructor
Queue::~Queue()
{

}
//functions
bool Queue::isEmpty() //checks if the queue is empty.  If so returns true, otherwise false.
{
    if(!head)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Queue::addBack(Character* nM)  //user inputted integer, creates a QueueNode & adds to back.
{
    if (isEmpty())
    {
        head = new QueueNode(nM);
        head->next = nullptr;
        head->prev = nullptr;
    }
    else if (head->next == nullptr)
    {
        QueueNode* newNode = new QueueNode(nM);

        newNode->prev = head;
        newNode->next = head;
        head->prev = newNode;
        head->next = newNode;
    }
    else
    {
        QueueNode* qNPtr = head;
        QueueNode* newNode = new QueueNode(nM);
        while (qNPtr->next != head)
        {
            qNPtr = qNPtr->next;
        }
        qNPtr->next = newNode;
        newNode->prev = qNPtr;
        newNode->next = head;
        head->prev = newNode;

    }
} Character* Queue::getFront() //returns the value of the node at the front of the queue.
{
    if(isEmpty())
    {
        std::cout << std::endl;
        std::cout << "The Team is Empty!" << std::endl;
        std::cout << std::endl;
    }
    else
    {
        return head->newMember;
    }
}
void Queue::removeFront() //removes the front queue node & frees memeory
{
    QueueNode* temp;

    if (isEmpty())  //if list is empty
    {
        std::cout << std::endl;
    }
    else if(head->next == nullptr)  //last in list after single input
    {
        delete head;
        head = nullptr;
        std::cout << std::endl;
    }
    else if(head == head->next)  //last in list after multiple entries
    {
        delete head;
        head = nullptr;
        std::cout << std::endl;
    }
    else   //delete head
    {
        temp = head;
        head = head->next;
        head->prev = temp->prev;
        head->prev->next = head;
        delete temp;
        std::cout << std::endl;
    }
}
void Queue::printQueue()  //traverses through the queue and prints values of each node.
{
    if (isEmpty())
    {
        std::cout << std::endl;
    }
    else if (head->next == nullptr)
    {
        std::cout << std::endl;
        std::cout << "Queue: " << head->newMember << std::endl;
    }
    else
    {
        QueueNode* hTemp = head;

        std::cout << std::endl;
        std::cout << "Queue: ";

        while(hTemp->next != head)
        {
            std::cout << hTemp->newMember << "  ";
            hTemp = hTemp->next;
        }
        std::cout << hTemp->newMember;
    }
    std::cout << std::endl;
}
void Queue::moveToBack()
{
    if (isEmpty())
    {
        std::cout << std::endl;
        std::cout << "Team is currently empty." << std::endl;
    }
    else if (head->next == nullptr)
    {
    }
    else
    {
        QueueNode* hTemp = head;
        hTemp = head;
        head = head->next;  //new head is next in queue
        head->prev = hTemp;   //new head prev is former head
    }
    std::cout << std::endl;
}
void Queue::deleteAll()
{
    QueueNode* temp;

    if (isEmpty())  //if list is empty
    {
        std::cout << std::endl;
        std::cout << std::endl;
    }
    else {
        do {
            if (head->next == nullptr)  //last in list after single input
            {
                delete head;
                head = nullptr;
                std::cout << std::endl;
                std::cout << std::endl;
            } else if (head == head->next)  //last in list after multiple entries
            {
                delete head;
                head = nullptr;
                std::cout << std::endl;
                std::cout << std::endl;
            } else   //delete head
            {
                temp = head;
                head = head->next;
                head->prev = temp->prev;
                head->prev->next = head;
                delete temp;
                std::cout << std::endl;
                std::cout << std::endl;
            }
        } while (!isEmpty());
    }
}