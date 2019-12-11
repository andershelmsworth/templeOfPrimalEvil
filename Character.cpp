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
#include "Space.hpp"

/*********************************************************************
** Character default constructor
** Paramaters are: none
** What it does: should not be used, but does initialize values
** Returns: No return data.
*********************************************************************/
Character::Character()
{
    this->attack = 0;
    this->defense = 0;
    this->armor = 0;
    this->strengthPoints = 0;
    this->currentSpace = NULL;
    this->inventory[0] = NULL;
    this->inventory[1] = NULL;
}

/*********************************************************************
** Character destructor
** Paramaters are: none
** What it does: destroys base Character object
** Returns: No return data.
*********************************************************************/
Character::~Character()
{
}

/*********************************************************************
** Attack getter
** Paramaters are: none
** What it does: gets Attack value
** Returns: int of attack value
*********************************************************************/
int Character::getAttack()
{
    return this->attack;
}

/*********************************************************************
** Attack setter
** Paramaters are: int of attack value
** What it does: sets Attack value
** Returns: none
*********************************************************************/
void Character::setAttack(int incAttack)
{
    this->attack = incAttack;
}

/*********************************************************************
** Defense getter
** Paramaters are: none
** What it does: gets defense value
** Returns: int of defense value
*********************************************************************/
int Character::getDefense()
{
    return this->defense;
}

/*********************************************************************
** Defense setter
** Paramaters are: int of incoming defense value
** What it does: sets defense value
** Returns: none
*********************************************************************/
void Character::setDefense(int incDefense)
{
    this->defense = incDefense;
}

/*********************************************************************
** Armor getter
** Paramaters are: none
** What it does: gets Armor value
** Returns: int of armor value
*********************************************************************/
int Character::getArmor()
{
    return this->armor;
}

/*********************************************************************
** Armor setter
** Paramaters are: int of incoming armor value
** What it does: sets armor value
** Returns: none
*********************************************************************/
void Character::setArmor(int incArmor)
{
    this->armor = incArmor;
}

/*********************************************************************
** StrengthPoint getter
** Paramaters are: none
** What it does: gets SP value
** Returns: int of SP value
*********************************************************************/
int Character::getStrengthPoints()
{
    return this->strengthPoints;
}

/*********************************************************************
** StrengthPoint setter
** Paramaters are: int of incoming SP value
** What it does: sets SP value
** Returns: none
*********************************************************************/
void Character::setStrengthPoints(int incStrengthPoints)
{
    this->strengthPoints = incStrengthPoints;
}

/*********************************************************************
** Name getter
** Paramaters are: none
** What it does: gets name value
** Returns: string of name value
*********************************************************************/
std::string Character::getName()
{
    return this->name;
}

/*********************************************************************
** Name setter
** Paramaters are: string of incoming name value
** What it does: sets name value
** Returns: none
*********************************************************************/
void Character::setName(std::string incName)
{
    this->name = incName;
}

/*********************************************************************
** Color getter
** Paramaters are: none
** What it does: gets Color value
** Returns: string of color value
*********************************************************************/
std::string Character::getColor()
{
    return this->color;
}

/*********************************************************************
** Color setter
** Paramaters are: string of incoming color value
** What it does: sets color value
** Returns: none
*********************************************************************/
void Character::setColor(std::string incColor)
{
    this->color = incColor;
}

Space* Character::getSpace()
{
    return this->currentSpace;
}

void Character::setSpace(Space* incSpace)
{
    this->currentSpace = incSpace;
}

InventoryObject** Character::getInventory()
{
	return this->inventory;
}