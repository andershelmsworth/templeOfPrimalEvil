/*********************************************************************
** Program Name: The Temple of Primal Evil
** Author: Andrew Helmsworth
** Date: 2019/12/08
** Description: Player Character object traverses linked list of Space objects,
** Description: ...& interacts with Spaces and InventoryObjects in a timed scenario
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Die.hpp"

/*********************************************************************
** Die default constructor
** Paramaters are: none
** What it does: initializes sides to 0
** Returns: No return data.
*********************************************************************/

Die::Die() {
    sides = 0;
}

/*********************************************************************
** Die overloaded constructor
** Paramaters are: int of sides
** What it does: initializes sides to int of sides
** Returns: No return data.
*********************************************************************/
Die::Die(int inputSides) {
    sides = inputSides;
}

/*********************************************************************
** Die destructor
** Paramaters are: none
** What it does: destroys Die
** Returns: No return data.
*********************************************************************/
Die::~Die()
{
}

/*********************************************************************
** roll() function
** Paramaters are: int of sides
** What it does: rolls a random number between 1 and number of sides
** Returns: int of roll
*********************************************************************/

//CITATION: Adapted from Bartwal, see works cited
int Die::roll(int activeSides) {
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    int theRoll = (rand() % (activeSides - 1 + 1)) + 1;
    return theRoll;
}