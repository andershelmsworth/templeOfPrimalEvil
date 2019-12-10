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

int TempleFoyer::draw(Character* playerCharacter)
{
	int winner = 0;
	Character* foyerBarb = new Barbarian;
	Game* currentGame = new Game();
	currentGame->startFight(playerCharacter, foyerBarb, winner);
	winner = currentGame->getRounds();
	delete currentGame;
	return winner;
}
