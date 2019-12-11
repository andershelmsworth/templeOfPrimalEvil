/*********************************************************************
** Program Name: The Temple of Primal Evil
** Author: Andrew Helmsworth
** Date: 2019/12/08
** Description: Player Character object traverses linked list of Space objects,
** Description: ...& interacts with Spaces and InventoryObjects in a timed scenario.
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include "JungleFloor.hpp"

/*********************************************************************
** JungleFloor default constructor
** Paramaters are: none
** What it does: sets name, sets character to null
** Returns: No return data.
*********************************************************************/
JungleFloor::JungleFloor()
{
	character = NULL;
	name = "Jungle Floor";
}

/*********************************************************************
** JungleFloor destructor
** Paramaters are: none
** What it does: destroys JungleFloor
** Returns: No return data.
*********************************************************************/
JungleFloor::~JungleFloor()
{
}

/*********************************************************************
** JungleFloor draw
** Paramaters are: none
** What it does: would handle lvl fxns, but none for this level
** Returns: 0
*********************************************************************/
int JungleFloor::draw(Character* playerCharacter, int& passingArg)
{
	return 0;
}
