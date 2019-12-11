/*********************************************************************
** Program Name: The Temple of Primal Evil
** Author: Andrew Helmsworth
** Date: 2019/12/08
** Description: Player Character object traverses linked list of Space objects,
** Description: ...& interacts with Spaces and InventoryObjects in a timed scenario.
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
#include "Character.hpp"
#include "Space.hpp"

#ifndef QUEUE_HPP
#define QUEUE_HPP

/*********************************************************************
** Queue class
** Abstraction it represents: a roundly linked list of nodes
** What it's for: adding and removing nodes from a list, printing
** How to use it: Functionality hooked up to runRumble
*********************************************************************/
class Queue
{
private:
    //QueueNode struct, represents a node in the queue
    struct QueueNode
    {
    private:
        //Need this to keep these values private
        friend class Queue;
        //next and prev pointer, int of val, as stipulated by spec
        QueueNode* next;
        QueueNode* prev;
        Space* location;
    };
    //Points to first node
    QueueNode* head;

public:
    //Con/destructors
    Queue();
    ~Queue();

    //Member Functions
    bool isEmpty();
    void addBack(Space*);
    void addFront(Space*);
    QueueNode* getHeadNode();
    Space* getFront();
    void setHead(QueueNode*);
    Space* removeFront();
    Space* removeBack();
    void printFront();
    void printQueue();
    void traverseReversely();
    void deallocateList();

};

#endif // !QUEUE_HPP