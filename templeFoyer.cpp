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

TempleFoyer::TempleFoyer()
{
	name = "Temple Foyer";
}

TempleFoyer::~TempleFoyer()
{
}

int TempleFoyer::draw(Character* playerCharacter, int& passingArg)
{
	int winner = 0;
	Character* foyerBarb = new Barbarian;
	Game* currentGame = new Game();
	currentGame->startFight(playerCharacter, foyerBarb, winner);
	winner = currentGame->getRounds();
	delete currentGame;
	delete foyerBarb;
	return winner;
}
