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

#ifndef JUNGLEFLOOR_HPP
#define JUNGLEFLOOR_HPP

/*********************************************************************
** JungleFloor class
** Abstraction it represents: subclass of Outside
** What it's for: playing level 0
** How to use it: default ctor, draw()
*********************************************************************/
class JungleFloor : public Outside
{
public:
    //Con/destructors
    JungleFloor();
    ~JungleFloor();
    
    //Member functions
    int draw(Character*, int&);

private:
};

#endif // !JUNGLEFLOOR_HPP