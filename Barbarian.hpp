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
#include <string>
#include "Character.hpp"

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

//CITATION: General structure of a C++ class 
//studied from relevant LearnCpp.com link in works cited.
/*********************************************************************
** Barbarian class
** Abstraction it represents: derived Barbarian class
** What it's for: building and rolling for Barbarians
** How to use it: default constructor, attack() defend(int)
*********************************************************************/

class Barbarian : public Character
{
public:

    //Con/destructors
    Barbarian();
    ~Barbarian();

    //Member functions
    int swing();
    void defend(int);

};

#endif // !BARBARIAN_HPP
