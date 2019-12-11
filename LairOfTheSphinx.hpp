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

#ifndef LAIROFTHESPHINX_HPP
#define LAIROFTHESPHINX_HPP

/*********************************************************************
** LairOfTheSphinx class
** Abstraction it represents: subclass of Chamber
** What it's for: playing level -2
** How to use it: default ctor, draw()
*********************************************************************/
class LairOfTheSphinx : public Chamber
{
public:
    //Con/destructors
    LairOfTheSphinx();
    ~LairOfTheSphinx();

    //Member functions
    int draw(Character*, int&);
    int getInt(int, int);

private:
};

#endif // !LAIROFTHESPHINX_HPP