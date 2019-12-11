/*********************************************************************
** Program Name: The Temple of Primal Evil
** Author: Andrew Helmsworth
** Date: 2019/12/08
** Description: Player Character object traverses linked list of Space objects,
** Description: ...& interacts with Spaces and InventoryObjects in a timed scenario
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include <iostream>
#include <string>
#include "Character.hpp"
#include "Space.hpp"

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

//CITATION: General structure of a C++ class 
//studied from relevant LearnCpp.com link in works cited.
/*********************************************************************
** HarryPotter class
** Abstraction it represents: derived HarryPotter class
** What it's for: building and rolling for HarryPotter
** How to use it: default constructor, attack() defend(int)
*********************************************************************/

class HarryPotter : public Character
{
public:

    //Con/destructors
    HarryPotter();
    ~HarryPotter();

    //Getters/Setters
    int getExtraLife();
    void setExtraLife(int);

    //Member functions
    int swing();
    void defend(int);

private:
    int extraLife;
    Space* currentSpace;
};

#endif // !HARRYPOTTER_HPP
