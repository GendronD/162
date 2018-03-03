/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Devin Gendron
** Date: 3/5/18
** Description: Using dice rolls, have characters battle it out... in
** a tournament!
*********************************************************************/
#ifndef FANTASY_COMBAT_GAME_QUEUE_H
#define FANTASY_COMBAT_GAME_QUEUE_H

#include "Character.h"

class Queue {
private:
    struct QueueNode
    {
        QueueNode* next;
        QueueNode* prev;
        Character* newMember;

        QueueNode(Character* nM, QueueNode* n = nullptr)
        {
            newMember = nM;
            next = n;
        }
    };
    QueueNode* head;
protected:
public:
    //constructor
    Queue();
    //overload constructor
    //Queue();
    //destructor
    ~Queue();
    //functions
    bool isEmpty(); //checks if the queue is empty.  If so returns true, otherwise false.
    void addBack(Character* nM);  //user inputted integer, creates a QueueNode & adds to back.
    Character* getFront(); //returns the value of the node at the front of the queue.
    void removeFront(); //removes the front queue node & frees memeory
    void printQueue();  //traverses through the queue and prints values of each node.
    void moveToBack();  //moves had to end of queue
    void deleteAll();   //deletes everything in node

};
#endif //FANTASY_COMBAT_GAME_QUEUE_H
