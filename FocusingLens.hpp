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
#include "Space.hpp"
#include "Character.hpp"
#include "InventoryObject.hpp"

#ifndef FOCUSINGLENS_HPP
#define FOCUSINGLENS_HPP

/*********************************************************************
** Focusing Lens class
** Abstraction it represents: required item for game progression
** What it's for: sits in player inventory when collected
** How to use it: default constructor
*********************************************************************/
class FocusingLens : public InventoryObject
{
public:
    //Con/destructors
    FocusingLens();
    ~FocusingLens();

private:

};

#endif // !FOCUSINGLENS_HPP