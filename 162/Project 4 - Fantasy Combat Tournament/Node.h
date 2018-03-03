/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Devin Gendron
** Date: 3/5/18
** Description: Using dice rolls, have characters battle it out... in
** a tournament!
*********************************************************************/
#ifndef FANTASY_COMBAT_GAME_NODE_H
#define FANTASY_COMBAT_GAME_NODE_H
#include "Character.h"

class Node {
    private:
        Character* fighter;
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
        Node(Character*);
        //destructor
        ~Node();
        //functions
        void addHead(Character*);
        void addTail(Character*);
        void deleteHead();
        void deleteTail();
        void reverseTraverse();
        void traverse();
        void printHead();
        void printTail();
        void deleteAll();
};


#endif //FANTASY_COMBAT_GAME_NODE_H
