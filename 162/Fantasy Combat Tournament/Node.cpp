/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Devin Gendron
** Date: 3/5/18
** Description: Using dice rolls, have characters battle it out... in
** a tournament!
*********************************************************************/
#include "Node.h"
#include <iostream>
//constructor
Node::Node()
{

}
//overload constructor
Node::Node(Character* f)
{
    fighter = f;
}
//destructor
Node::~Node()
{

}
//functions
void Node::addHead(Character* f)
{
    if (head == nullptr)
    {
        newNode = new Node;
        newNode->fighter = f;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode = new Node;
        newNode->fighter = f;
        newNode->next = head;
        newNode->prev = nullptr;
        head->prev = newNode;
        head = newNode;
    }
}
void Node::addTail(Character* f)
{
    if (tail == nullptr)
    {
        newNode = new Node;
        newNode->fighter = f;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode = new Node;
        newNode->fighter = f;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}
void Node::deleteHead()
{
    Node* temp;

    if (!head)  //if list is empty
    {
        std::cout << "The list is empty." << std::endl;
        std::cout << std::endl;
    }
    else   //delete head
    {
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            //std::cout << "last value in list" << std::endl;
            std::cout << "Last node deleted." << std::endl;
            std::cout << std::endl;
        }
        else
        {
            temp = head;
            head = head->next;
            delete temp;
            head->prev = nullptr;
            std::cout << "Head deleted." << std::endl;
            std::cout << std::endl;
        }
    }
}
void Node::deleteTail()
{
    Node* temp;

    if (!tail)  //if list is empty
    {
        std::cout << "The list is empty." << std::endl;
        std::cout << std::endl;
    }
    else   //delete head
    {
        if(head == tail)
        {
            delete tail;
            tail = nullptr;
            head = nullptr;
            std::cout << "Last node deleted." << std::endl;
            std::cout << std::endl;
        }
        else
        {
            temp = tail;
            tail = tail->prev;
            delete temp;
            tail->next = nullptr;
            std::cout << "Tail deleted." << std::endl;
            std::cout << std::endl;
        }
    }
}
void Node::reverseTraverse()
{
    if (!tail)
    {
        std::cout << std::endl;
        std::cout << "List is empty" << std::endl;
    }
    else
    {
        std::cout << "Reverse Traverse started: ";
        Node* tTemp = tail;
        while(tTemp != nullptr)
        {
            std::cout << tTemp->fighter << "  ";
            tTemp = tTemp->prev;
        }
    }

    std::cout << std::endl;
    std::cout << std::endl;
}
void Node::traverse()
{
    if (!head)
    {
        std::cout << std::endl;
        std::cout << "List currently empty." << std::endl;
    }
    else
    {
        Node* hTemp = head;

        std::cout << std::endl;

        std::cout << "List of Dead: ";

        while(hTemp != nullptr)
        {
            std::cout << hTemp->fighter->getName() << "  ";
            hTemp = hTemp->next;
        }
    }
    //std::cout << std::endl;
}

void Node::printHead()
{
    if (!head)
    {
        std::cout << std::endl;
        std::cout << "List currently empty." << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << std::endl;
        std::cout << "Head: ";
        std::cout << head->fighter <<std::endl;
        std::cout << std::endl;
    }
}
void Node::printTail()
{
    if (!tail)
    {
        std::cout << std::endl;
        std::cout << "List currently empty." << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << std::endl;
        std::cout << "Tail: ";
        std::cout << tail->fighter << std::endl;

        std::cout << std::endl;
    }
}
void Node::deleteAll()
{
    Node* temp;

    if (!head)
    {

    }
    else
    {
        do
        {
            if (head == tail)
            {
                delete head;
                head = nullptr;
                tail = nullptr;
                //std::cout << "last value in list" << std::endl;
                //std::cout << "Last node deleted." << std::endl;
                std::cout << std::endl;
            }
            else
            {
                temp = head;
                head = head->next;
                delete temp;
                head->prev = nullptr;
                //std::cout << "Head deleted." << std::endl;
                std::cout << std::endl;
            }
        }while(head);
    }
}