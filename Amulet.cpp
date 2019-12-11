/*********************************************************************
** Program Name: The Temple of Primal Evil
** Author: Andrew Helmsworth
** Date: 2019/12/08
** Description: Player Character object traverses linked list of Space objects,
** Description: ...& interacts with Spaces and InventoryObjects in a timed scenario.
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include "Amulet.hpp"

/*********************************************************************
** Amulet default constructor
** Paramaters are: none
** What it does: Initializes Amulet name
** Returns: No return data.
*********************************************************************/
Amulet::Amulet()
{
	name = "Golden Amulet";
}

/*********************************************************************
** Amulet destructor
** Paramaters are: none
** What it does: destroys Amulet
** Returns: No return data.
*********************************************************************/
Amulet::~Amulet()
{
}
