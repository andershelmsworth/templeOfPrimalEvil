/*********************************************************************
** Program Name: The Temple of Primal Evil
** Author: Andrew Helmsworth
** Date: 2019/12/08
** Description: Player Character object traverses linked list of Space objects,
** Description: ...& interacts with Spaces and InventoryObjects in a timed scenario.
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include "TempleFoyer.hpp"
#include "Barbarian.hpp"
#include "HarryPotter.hpp"
#include "Character.hpp"
#include "Game.hpp"

/*********************************************************************
** TempleFoyer default constructor
** Paramaters are: none
** What it does: sets name, sets character to null
** Returns: No return data.
*********************************************************************/
TempleFoyer::TempleFoyer()
{
	name = "Temple Foyer";
}

/*********************************************************************
** TempleFoyer destructor
** Paramaters are: none
** What it does: destroys TempleFoyer
** Returns: No return data.
*********************************************************************/
TempleFoyer::~TempleFoyer()
{
}

/*********************************************************************
** TempleFoyer draw
** Paramaters are: none
** What it does: runs level interaction
** Returns: number of rounds required
*********************************************************************/
int TempleFoyer::draw(Character* playerCharacter, int& passingArg)
{
	int winner = 0;
	//Init enemy barb
	Character* foyerBarb = new Barbarian;
	//Init and run game with player char and barb
	Game* currentGame = new Game();
	currentGame->startFight(playerCharacter, foyerBarb, winner);
	winner = currentGame->getRounds();
	//Free barb and game mem
	delete currentGame;
	delete foyerBarb;
	//Return rouds req'd
	return winner;
}
