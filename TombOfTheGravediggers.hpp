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
#include "Chamber.hpp"

#ifndef TOMBOFTHEGRAVEDIGGERS_HPP
#define TOMBOFTHEGRAVEDIGGERS_HPP

/*********************************************************************
** Menu class
** Abstraction it represents: menu for running Fibonacci functions
** What it's for: running recursive and iterative fxns 1k times
** How to use it: all functionality tied to showMenu()
*********************************************************************/
class TombOfTheGraveDiggers : public Chamber
{
public:
    //Con/destructors
    TombOfTheGraveDiggers();
    ~TombOfTheGraveDiggers();

    //Member functions
    int draw(Character*, int&);
    int getInt(int, int);

private:
};

#endif // !JUNGLEFLOOR_HPP