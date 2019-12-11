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

#ifndef INVENTORYOBJECT_HPP
#define INVENTORYOBJECT_HPP

/*********************************************************************
** InventoryObject class
** Abstraction it represents: archetype of required items for game progression
** What it's for: sits in player inventory when collected
** How to use it: use derived classes
*********************************************************************/
class InventoryObject
{
public:
    //Con/destructors
    InventoryObject();
    virtual ~InventoryObject() = 0;

    //Member functions
    std::string getName();
    void setName(std::string);

protected:
    std::string name;
};

#endif // !INVENTORYOBJECT_HPP