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

#ifndef CORRIDOR_HPP
#define CORRIDOR_HPP

/*********************************************************************
** Corridor class
** Abstraction it represents: subclass of Space
** What it's for: describing a space type
** How to use it: currently abstract, do not instantiate
*********************************************************************/
class Corridor : public Space
{
public:
    //Con/destructors
    Corridor();
    virtual ~Corridor() = 0;

    //Member functions
    virtual int draw(Character*, int&) = 0;

private:
};

#endif // !CORRIDOR_HPP