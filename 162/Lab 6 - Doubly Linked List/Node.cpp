/*********************************************************************
** Program name: Doubly-linked Lists
** Author: Devin Gendron
** Date: 2/18/17
** Description: Practice using Linked lists, in this case a
** doubly-linked list and variations of node management.
*********************************************************************/
#include "Node.h"
#include <iostream>
//constructor
Node::Node()
{

}
//overload constructor
Node::Node(int v)
{
    value = v;
}
//destructor
Node::~Node()
{

}
//functions
void Node::addHead(int v)
{
    if (head == nullptr)
    {
        newNode = new Node;
        newNode->value = v;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode = new Node;
        newNode-> value = v;
        newNode->next = head;
        newNode->prev = nullptr;
        head->prev = newNode;
        head = newNode;
    }
}
void Node::addTail(int v)
{
    if (tail == nullptr)
    {
        newNode = new Node;
        newNode->value = v;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode = new Node;
        newNode->value = v;
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
            std::cout << tTemp->value << "  ";
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

        std::cout << "Doubly-Linked List: ";

        while(hTemp != nullptr)
        {
            std::cout << hTemp->value << "  ";
            hTemp = hTemp->next;
        }
    }
    std::cout << std::endl;
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
        std::cout << head->value <<std::endl;
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
        std::cout << tail->value << std::endl;

        std::cout << std::endl;
    }
}