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
#include "Corridor.hpp"

#ifndef TEMPLEFOYER_HPP
#define TEMPLEFOYER_HPP

/*********************************************************************
** TempleFoyer class
** Abstraction it represents: subclass of Corridor
** What it's for: playing level -1
** How to use it: default ctor, draw()
*********************************************************************/
class TempleFoyer : public Corridor
{
public:
    //Con/destructors
    TempleFoyer();
    ~TempleFoyer();

    //Member functions
    int draw(Character*, int&);

private:
};

#endif // !TEMPLEFOYER_HPP