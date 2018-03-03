/*********************************************************************
** Program name: Doubly-linked Lists
** Author: Devin Gendron
** Date: 2/18/17
** Description: Practice using Linked lists, in this case a
** doubly-linked list and variations of node management.
*********************************************************************/

#ifndef DOUBLELINKEDLISTS_NODE_H
#define DOUBLELINKEDLISTS_NODE_H


class Node {
private:
    int value = 0;
    Node *next = nullptr;
    Node *prev = nullptr;
    Node *head = nullptr;
    Node *tail = nullptr;
    Node *newNode = nullptr;
protected:
public:
    //constructor
    Node();
    //overload constructor
    Node(int);
    //destructor
    ~Node();
    //functions
    void addHead(int);
    void addTail(int);
    void deleteHead();
    void deleteTail();
    void reverseTraverse();
    void traverse();
    void printHead();
    void printTail();
};


#endif //DOUBLELINKEDLISTS_NODE_H
