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
#include "Space.hpp"
#include "InventoryObject.hpp"

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

//CITATION: General structure of a C++ class 
//studied from relevant LearnCpp.com link in works cited,
//Also see Johnston, Ton, Owens in Works Cited
/*********************************************************************
** Character class
** Abstraction it represents: abstract base Character class
** What it's for: building a Character
** How to use it: not to be used on its own - use derived
*********************************************************************/

class Character
{
public:

    //Con/destructors
    Character();
    //Character(int);
    virtual ~Character() = 0;

    //Getters and Setters
    int getAttack();
    void setAttack(int);
    int getDefense();
    void setDefense(int);
    int getArmor();
    void setArmor(int);
    int getStrengthPoints();
    void setStrengthPoints(int);
    std::string getName();
    void setName(std::string);
    std::string getColor();
    void setColor(std::string);
    Space* getSpace();
    void setSpace(Space*);

    InventoryObject** getInventory();

    //Member functions
    virtual int swing() = 0;
    virtual void defend(int) = 0;


protected:
    int attack;
    int defense;
    int armor;
    int strengthPoints;
    std::string name;
    std::string color;
    Space* currentSpace;
    InventoryObject* inventory[2];
};

#endif // !CHARACTER_HPP
