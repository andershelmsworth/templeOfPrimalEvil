/*********************************************************************
** Program Name: Fibonacci Timing Tool
** Author: Andrew Helmsworth
** Date: 2019/12/05
** Description: Compares the time required to calculate a Fibonacci number...
** Description: ...with iteration vs. recursion.
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
#include "Space.hpp"
#include "Pixel.hpp"
#include "Character.hpp"
#include "InventoryObject.hpp"

#ifndef AMULET_HPP
#define AMULET_HPP

/*********************************************************************
** Menu class
** Abstraction it represents: menu for running Fibonacci functions
** What it's for: running recursive and iterative fxns 1k times
** How to use it: all functionality tied to showMenu()
*********************************************************************/
class Amulet : public InventoryObject
{
public:
    //Con/destructors
    Amulet();
    ~Amulet();

    //Member functions


private:

};

#endif // !JUNGLEFLOOR_HPP