/*********************************************************************
** Program Name: The Temple of Primal Evil
** Author: Andrew Helmsworth
** Date: 2019/12/08
** Description: Player Character object traverses linked list of Space objects,
** Description: ...& interacts with Spaces and InventoryObjects in a timed scenario.
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include "InventoryObject.hpp"
#include <string>

InventoryObject::InventoryObject()
{
	name = "";
}

InventoryObject::~InventoryObject()
{
}

std::string InventoryObject::getName()
{
	return this->name;
}

void InventoryObject::setName(std::string incName)
{
	this->name = incName;
}
