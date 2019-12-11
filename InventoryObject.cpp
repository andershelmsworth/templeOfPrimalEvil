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

/*********************************************************************
** Amulet default InventoryObject
** Paramaters are: none
** What it does: Initializes InventoryObject name
** Returns: No return data.
*********************************************************************/
InventoryObject::InventoryObject()
{
	name = "";
}

/*********************************************************************
** InventoryObject destructor
** Paramaters are: none
** What it does: destroys InventoryObject
** Returns: No return data.
*********************************************************************/
InventoryObject::~InventoryObject()
{
}

/*********************************************************************
** InventoryObject name getter
** Paramaters are: none
** What it does: gets InventoryObject name
** Returns: string of name
*********************************************************************/
std::string InventoryObject::getName()
{
	return this->name;
}

/*********************************************************************
** InventoryObject name setter
** Paramaters are: string of name
** What it does: gets InventoryObject name
** Returns: none
*********************************************************************/
void InventoryObject::setName(std::string incName)
{
	this->name = incName;
}
