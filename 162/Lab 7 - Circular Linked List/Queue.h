/*********************************************************************
** Program name: Circular Linked List
** Author: Devin Gendron
** Date: 2/25/18
** Description: Use circular linked list to create a queue data struct.
*********************************************************************/
#ifndef CIRCULARLINKEDLIST_QUEUE_H
#define CIRCULARLINKEDLIST_QUEUE_H

class Queue {
private:
    struct QueueNode
    {
        QueueNode* next;
        QueueNode* prev;
        int value = 0;

        QueueNode(int val, QueueNode* n = nullptr)
        {
            value = val;
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
    void addBack(int val);  //user inputted integer, creates a QueueNode & adds to back.
    int getFront(); //returns the value of the node at the front of the queue.
    void removeFront(); //removes the front queue node & frees memeory
    void printQueue();  //traverses through the queue and prints values of each node.

};
#endif //CIRCULARLINKEDLIST_QUEUE_H
