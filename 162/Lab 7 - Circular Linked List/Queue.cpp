/*********************************************************************
** Program name: Circular Linked List
** Author: Devin Gendron
** Date: 2/25/18
** Description: Use circular linked list to create a queue data struct.
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
void Queue::addBack(int val)  //user inputted integer, creates a QueueNode & adds to back.
{
    if (isEmpty())
    {
        head = new QueueNode(val);
        head->next = nullptr;
        head->prev = nullptr;
    }
    else if (head->next == nullptr)
    {
        QueueNode* newNode = new QueueNode(val);

        newNode->prev = head;
        newNode->next = head;
        head->prev = newNode;
        head->next = newNode;
    }
    else
    {
        QueueNode* qNPtr = head;
        QueueNode* newNode = new QueueNode(val);
        while (qNPtr->next != head)
        {
            qNPtr = qNPtr->next;
        }
        qNPtr->next = newNode;
        newNode->prev = qNPtr;
        newNode->next = head;
        head->prev = newNode;

    }
}
int Queue::getFront() //returns the value of the node at the front of the queue.
{
    if(isEmpty())
    {
        std::cout << std::endl;
        std::cout << "The Queue is Empty!" << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << std::endl;
        std::cout << "First in queue is: " << head->value << std::endl;
        std::cout << std::endl;
        return head->value;
    }
}
void Queue::removeFront() //removes the front queue node & frees memeory
{
    QueueNode* temp;

    if (isEmpty())  //if list is empty
    {
        std::cout << std::endl;
        std::cout << "The Queue is Empty!" << std::endl;
        std::cout << std::endl;
    }
    else if(head->next == nullptr)  //last in list after single input
    {
        delete head;
        head = nullptr;
        std::cout << std::endl;
        std::cout << "First in queue deleted." << std::endl;
        std::cout << std::endl;
    }
    else if(head == head->next)  //last in list after multiple entries
    {
        delete head;
        head = nullptr;
        std::cout << std::endl;
        std::cout << "First in queue deleted." << std::endl;
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
        std::cout << "First in queue deleted." << std::endl;
        std::cout << std::endl;
    }
}
void Queue::printQueue()  //traverses through the queue and prints values of each node.
{
    if (isEmpty())
    {
        std::cout << std::endl;
        std::cout << "Queue is currently empty." << std::endl;
    }
    else if (head->next == nullptr)
    {
        std::cout << std::endl;
        std::cout << "Queue: " << head->value << std::endl;
    }
    else
    {
        QueueNode* hTemp = head;

        std::cout << std::endl;
        std::cout << "Queue: ";

        while(hTemp->next != head)
        {
            std::cout << hTemp->value << "  ";
            hTemp = hTemp->next;
        }
        std::cout << hTemp->value;
    }
    std::cout << std::endl;
}