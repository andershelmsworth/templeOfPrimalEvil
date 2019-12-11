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

#ifndef CHAMBER_HPP
#define CHAMBER_HPP

/*********************************************************************
** Chamber class
** Abstraction it represents: subclass of Space
** What it's for: describing a space type
** How to use it: currently abstract, do not instantiate
*********************************************************************/
class Chamber : public Space
{
public:
    //Con/destructors
    Chamber();
    virtual ~Chamber() = 0;

    //Member functions
    virtual int draw(Character*, int&) = 0;

private:
};

#endif // !CHAMBER_HPP