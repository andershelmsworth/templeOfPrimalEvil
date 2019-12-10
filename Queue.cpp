/*********************************************************************
** Program Name: Dungeon Rumble
** Author: Andrew Helmsworth
** Date: 2019/11/11
** Description: Characters in Queues face off in a fantasy combat sim
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/
//Inclusions
#include <iostream>
#include "Queue.hpp"
#include "Character.hpp"

//CITATION: Drawings from Gupta in WC helped visualise the nodes' relational structure
//However, I did not copy any actual code from that page.
/*********************************************************************
** CircleLinkedList constructor
** Paramaters are: none
** What it does: constructs list, sets head to NULL
** Returns: No return data.
*********************************************************************/
Queue::Queue()
{
    head = NULL;
}

/*********************************************************************
** CircleLinkedList destructor
** Paramaters are: none
** What it does: runs deallocate fxn before destructing list
** Returns: No return data.
*********************************************************************/
Queue::~Queue()
{
    //This function traverses the list and destroys each node
    deallocateList();
}

/*********************************************************************
** emptyCheck
** Paramaters are: none
** What it does: checks to see if a head node is set
** Returns: True if empty, otherwise false
*********************************************************************/
bool Queue::isEmpty()
{
    if (this->getHeadNode() == NULL) {
        //No head node
        return true;
    }
    else {
        //Nodes exist in list
        return false;
    }
}

/*********************************************************************
** addBack
** Paramaters are: int of incoming value
** What it does: adds a new node to the end of the list
** Returns: none (void)
*********************************************************************/
void Queue::addBack(Space* incSpace)
{
    //Initialize new node with inc val
    QueueNode* newNode = new QueueNode;
    newNode->location = incSpace;
    //Check to see if list empty
    bool checkEmpty = isEmpty();

    if (checkEmpty == true) {
        //List was empty
        setHead(newNode);
        //New head node points to itself
        newNode->next = newNode;
        newNode->prev = newNode;
        //std::cout << "Added first value to the list." << std::endl;
    }
    else if (checkEmpty == false) {
        //Nodes exist in list
        QueueNode* headNode = getHeadNode();
        if (headNode->next == headNode) {
            //Was just one node
            headNode->next = newNode;
            headNode->prev = newNode;
            //Now head is connected to new node
            newNode->next = headNode;
            newNode->prev = headNode;
            //Now they point to each other
            //std::cout << "Added second value to the list." << std::endl;
        }
        else {
            //Was at least two nodes in list
            //Get the tail node
            QueueNode* tailNode = headNode->prev;
            //Set new node's next to head and prev to tail 
            //& tail's next pointing at new so still circular
            newNode->next = headNode;
            newNode->prev = tailNode;
            tailNode->next = newNode;
            //prev shouldn't change for tail node
            //But head needs to connect to new node
            headNode->prev = newNode;//Why does this mess up the printing if not included?
            //std::cout << "Added next value to the list." << std::endl;
        }
    }
}

/*********************************************************************
** addBack
** Paramaters are: int of incoming value
** What it does: adds a new node to the end of the list
** Returns: none (void)
*********************************************************************/
void Queue::addFront(Space* incSpace)
{
    //Initialize new node with inc val
    QueueNode* newNode = new QueueNode;
    newNode->location = incSpace;
    //Check to see if list empty
    bool checkEmpty = isEmpty();

    if (checkEmpty == true) {
        //List was empty
        setHead(newNode);
        //New head node points to itself
        newNode->next = newNode;
        newNode->prev = newNode;
        //std::cout << "Added first value to the list." << std::endl;
    }
    else if (checkEmpty == false) {
        //Nodes exist in list
        QueueNode* headNode = getHeadNode();
        if (headNode->next == headNode) {
            //Was just one node
            headNode->prev = newNode;
            headNode->next = newNode;
            //Now head is connected to new node
            newNode->next = headNode;
            newNode->prev = headNode;
            setHead(newNode);
            //Now they point to each other
            //std::cout << "Added second value to the list." << std::endl;
        }
        else {
            //Was at least two nodes in list
            //Get the tail node
            QueueNode* tailNode = headNode->prev;
            QueueNode* secondNode = headNode;
            //Set new node's next to head and prev to tail 
            //& tail's next pointing at new so still circular
            newNode->next = secondNode;
            newNode->prev = tailNode;
            tailNode->next = newNode;
            //prev shouldn't change for tail node
            //But head needs to connect to new node
            secondNode->prev = newNode;//Why does this mess up the printing if not included?
            //std::cout << "Added next value to the list." << std::endl;
            setHead(newNode);
        }
    }
}

/*********************************************************************
** int getFront
** Paramaters are: none
** What it does: returns the value of head node
** Returns: an integer
*********************************************************************/
Space* Queue::getFront() {
    //Gets head node
    QueueNode* headNode = getHeadNode();
    //Returns its value
    return headNode->location;
}

/*********************************************************************
** QueueNode* getHeadNode
** Paramaters are: none
** What it does: returns the head node
** Returns: a QueueNode pointer
*********************************************************************/
Queue::QueueNode* Queue::getHeadNode()
{
    return this->head;
}

/*********************************************************************
** setHead node
** Paramaters are: a QueueNode pointer
** What it does: resets the head node with incoming node value
** Returns: none (void)
*********************************************************************/
void Queue::setHead(QueueNode* incNode)
{
    this->head = incNode;
}

/*********************************************************************
** removeFront
** Paramaters are: none
** What it does: deletes node at head and resets head pointer correctly
** Returns: none (void)
*********************************************************************/
Space* Queue::removeFront()
{
    //Check if empty
    bool emptyCheck = isEmpty();

    if (emptyCheck == true) {
        //List is empty
        std::cout << "Sorry, couldn't delete first node as list was empty." << std::endl;
        std::cout << "Returning to main menu." << std::endl;
    }
    else if (emptyCheck == false) {
        //Not empty, getting head node
        QueueNode* headNode = getHeadNode();

        if (headNode->next == headNode) {
            //Just one node
            setHead(NULL);
            //std::cout << "Deleted first and only node." << std::endl;
            //Assign head character to a temporary character pointer
            Space* currentLocation = headNode->location;
            //Delete head node
            delete headNode;
            //return character
            return currentLocation;
        }
        else if (headNode->next->next == headNode)
        {
            //Just two nodes
            QueueNode* nodeTwo = headNode->next;
            //Now just one, setting it to point to itself
            nodeTwo->next = nodeTwo;
            nodeTwo->prev = nodeTwo;
            //Setting new head to node two
            setHead(nodeTwo);
            //std::cout << "Deleted first node, original second is now only node." << std::endl;
            //Assign head character to a temporary character pointer
            Space* currentLocation = headNode->location;
            //Delete head node
            delete headNode;
            //return character
            return currentLocation;
        }
        else {
            //has at least three
            //Get tail and original second
            QueueNode* tailNode = headNode->prev;
            QueueNode* nodeTwo = headNode->next;
            //Delete head, reattach the circle
            tailNode->next = nodeTwo;
            nodeTwo->prev = tailNode;
            //Setting new head to node two
            setHead(nodeTwo);
            //std::cout << "Deleted first node in list." << std::endl;
            //Assign head character to a temporary character pointer
            Space* currentLocation = headNode->location;
            //Delete head node
            delete headNode;
            //return character
            return currentLocation;
        }
    }
}

Space* Queue::removeBack()
{
    //Check if empty
    bool emptyCheck = isEmpty();

    if (emptyCheck == true) {
        //List is empty
        std::cout << "Sorry, couldn't delete first node as list was empty." << std::endl;
        std::cout << "Returning to main menu." << std::endl;
    }
    else if (emptyCheck == false) {
        //Not empty, getting head node
        QueueNode* tailNode = getHeadNode()->prev;

        if (tailNode->next == tailNode) {
            //Just one node
            setHead(NULL);
            //std::cout << "Deleted first and only node." << std::endl;
            //Assign head character to a temporary character pointer
            Space* currentLocation = tailNode->location;
            //Delete head node
            delete tailNode;
            //return character
            return currentLocation;
        }
        else if (tailNode->next != tailNode && tailNode->prev == getHeadNode())
        {
            //Just two nodes
            QueueNode* nodeOne = tailNode->prev;
            //Now just one, setting it to point to itself
            nodeOne->next = nodeOne;
            nodeOne->prev = nodeOne;
            //Setting new head to node two
            setHead(nodeOne);
            //std::cout << "Deleted first node, original second is now only node." << std::endl;
            //Assign head character to a temporary character pointer
            Space* currentLocation = tailNode->location;
            //Delete head node
            delete tailNode;
            //return character
            return currentLocation;
        }
        else {
            //has at least three
            //Get tail and original second
            QueueNode* headNode = getHeadNode();
            QueueNode* penUltimateNode = tailNode->prev;
            //Delete head, reattach the circle
            headNode->prev = penUltimateNode;
            penUltimateNode->next = headNode;
            //Setting new head to node two
            setHead(headNode);
            //std::cout << "Deleted first node in list." << std::endl;
            //Assign head character to a temporary character pointer
            Space* currentLocation = tailNode->location;
            //Delete head node
            delete tailNode;
            //return character
            return currentLocation;
        }
    };
}

/*********************************************************************
** printFront
** Paramaters are: none
** What it does: Prints first node in list if available
** Returns: none (void)
*********************************************************************/
void Queue::printFront()
{
    //Check if empty
    bool checkEmpty = isEmpty();

    if (checkEmpty == true) {
        //List is empty
        std::cout << "No first node to print, sorry - list is empty!" << std::endl;
    }
    else {
        //List is not empty, getting head node
        Space* headNodeValue = getFront();
    }
}

/*********************************************************************
** printQueue
** Paramaters are: none
** What it does: Prints list in order
** Returns: none (void)
*********************************************************************/
void Queue::printQueue()
{
    //Check if empty
    bool checkEmpty = isEmpty();
    if (checkEmpty == true) {
        //List is empty
        //std::cout << "[List is empty1]" << std::endl;
    }
    else if (checkEmpty == false) {
        //Not empty, getting head node
        QueueNode* headNode = getHeadNode();

        if (headNode->next == headNode) {
            //Was just one node
            //std::cout << std::endl;
            //std::cout << "Your list is:" << std::endl;
            //Printing
            //std::cout << headNode->character->getColor() << " " << headNode->character->getName() << ", \"" << headNode->character->getNickName() << "\"" << std::endl;
        }
        else {
            QueueNode* currentNode = getHeadNode();
            //std::cout << std::endl;
            //Loop while still nodes in list
            bool tailReached = false;
            while (tailReached == false) {
                if (currentNode->next == headNode) {
                    //currentNode is last node in list
                    tailReached = true;
                    //Printing final value
                    //std::cout << currentNode->character->getColor() << " " << currentNode->character->getName() << ", \"" << currentNode->character->getNickName() << "\"" << std::endl;
                }
                else {
                    //Print current node
                    //std::cout << currentNode->character->getColor() << " " << currentNode->character->getName() << ", \"" << currentNode->character->getNickName() << "\"" << std::endl;
                    //Advance currentNode counter
                    currentNode = currentNode->next;
                }
            }
        }
    }
}

/*********************************************************************
** traverseReversely
** Paramaters are: none
** What it does: Prints list in reverse
** Returns: none (void)
*********************************************************************/
void Queue::traverseReversely()
{   //Check if empty
    bool checkEmpty = isEmpty();
    if (checkEmpty == true) {
        //List is empty
        //std::cout << "[List is empty2]" << std::endl;
    }
    else if (checkEmpty == false) {
        //Not empty, getting head node
        QueueNode* headNode = getHeadNode();

        if (headNode->next == headNode) {
            //Was just one node
            //std::cout << std::endl;
            //std::cout << "Your list is:" << std::endl;
            //Printing
            //std::cout << headNode->character->getColor() << " " << headNode->character->getName() << ", \"" << headNode->character->getNickName() << "\"" << std::endl;
        }
        else {
            QueueNode* currentNode = getHeadNode()->prev;
            //std::cout << std::endl;
            //Loop while still nodes in list
            bool headReached = false;
            while (headReached == false) {
                if (currentNode == headNode) {
                    //currentNode is last node in list
                    headReached = true;
                    //Printing final value
                    //std::cout << currentNode->character->getColor() << " " << currentNode->character->getName() << ", \"" << currentNode->character->getNickName() << "\"" << std::endl;
                }
                else {
                    //Print current node
                    //std::cout << currentNode->character->getColor() << " " << currentNode->character->getName() << ", \"" << currentNode->character->getNickName() << "\"" << std::endl;
                    //Advance currentNode counter
                    currentNode = currentNode->prev;
                }
            }
        }
    }
}

/*********************************************************************
** deallocateList
** Paramaters are: none
** What it does: deletes all nodes in list by traversing and deleting in turn
** Returns: none (void)
*********************************************************************/
void Queue::deallocateList()
{
    //std::cout << "Ran deallocate" << std::endl;

    //Check if empty
    bool emptyCheck = isEmpty();

    if (emptyCheck == true) {
        //List is empty
        //std::cout << "[List is empty3]" << std::endl;
    }
    else if (emptyCheck == false) {
        //Not empty, getting head node
        QueueNode* headNode = getHeadNode();
        if (headNode->next == headNode) {
            //Just one node
            delete headNode->location;
            delete headNode;
            //Deleted it and its character
            setHead(NULL);
            //std::cout << "Deleted first and only node." << std::endl;
        }
        else if (headNode->next->next == headNode)
        {
            //Just two nodes
            //Get second node
            QueueNode* nodeTwo = headNode->next;
            //deleting both and their characters
            delete headNode->location;
            delete headNode;
            delete nodeTwo->location;
            delete nodeTwo;
            //Setting head to null
            setHead(NULL);
        }
        else {
            //At least 3 nodes
            bool tailReached = false;
            QueueNode* currentNode = getHeadNode();
            //Loop until head detected as next
            while (tailReached == false) {
                if (currentNode->next == headNode) {
                    //currentNode is head node
                    tailReached = true;
                    //Deleting head node and its character
                    delete currentNode->location;
                    delete currentNode;
                    //Setting head to null so last print check doesn't fail
                    setHead(NULL);
                }
                else {
                    //Alias the current node
                    QueueNode* nodeToBeDeleted = currentNode;
                    //Advance currentNode counter
                    currentNode = currentNode->next;
                    //delete alias and its character
                    delete nodeToBeDeleted->location;
                    delete nodeToBeDeleted;
                }
            }
        }
    }
}