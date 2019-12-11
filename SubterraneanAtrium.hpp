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
#include "Outside.hpp"

#ifndef SUBTERRANEANATRIUM_HPP
#define SUBTERRANEANATRIUM_HPP

/*********************************************************************
** SubterraneanAtrium class
** Abstraction it represents: subclass of Outside
** What it's for: playing level -5
** How to use it: default ctor, draw()
*********************************************************************/
class SubterraneanAtrium : public Outside
{
public:
    //Con/destructors
    SubterraneanAtrium();
    ~SubterraneanAtrium();

    //Member functions
    int draw(Character*, int&);
    int getInt(int, int);

private:
};

#endif // !SUBTERRANEANATRIUM_HPP