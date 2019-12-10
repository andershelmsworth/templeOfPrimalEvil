/*********************************************************************
** Program Name: Dungeon Rumble
** Author: Andrew Helmsworth
** Date: 2019/11/11
** Description: Characters in Queues face off in a fantasy combat sim
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/
//Inclusions
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Game.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "HarryPotter.hpp"

/*********************************************************************
** Game default constructor
** Paramaters are: none
** What it does: should not be used, but does initialize values
** Returns: No return data.
*********************************************************************/
Game::Game()
{
    blueChar = NULL;
    redChar = NULL;
    blueAlive = true;
    redAlive = true;
    rounds = 0;
}

/*********************************************************************
** Game overloaded constructor
** Paramaters are: none
** What it does: initializes game with character choices
** Returns: No return data.
*********************************************************************/
Game::Game(Character* blueChoice, Character* redChoice)
{
    setBlueAlive(true);
    setRedAlive(true);
    setBlueChar(blueChoice);
    setRedChar(redChoice);
    rounds = 0;
}

/*********************************************************************
** Game destructor
** Paramaters are: none
** What it does: destroys Game
** Returns: No return data.
*********************************************************************/
Game::~Game()
{
}

/*********************************************************************
** Game blueChar getter
** Paramaters are: none
** What it does: gets blue char
** Returns: blue char
*********************************************************************/
Character* Game::getBlueChar()
{
    return blueChar;
}

/*********************************************************************
** Game blueChar setter
** Paramaters are: none
** What it does: Very important. Instantiates and assigns to pointer a derived char.
** Returns: No return data.
*********************************************************************/
void Game::setBlueChar(Character* incBlueChar)
{
    this->blueChar = incBlueChar;
}

/*********************************************************************
** Game redChar getter
** Paramaters are: none
** What it does: gets red char
** Returns: red char
*********************************************************************/
Character* Game::getRedChar()
{
    return redChar;
}

/*********************************************************************
** Game redChar setter
** Paramaters are: none
** What it does: Very important. Instantiates and assigns to pointer a derived char.
** Returns: No return data.
*********************************************************************/
void Game::setRedChar(Character* incCharacter)
{
    this->redChar = incCharacter;
}

/*********************************************************************
** Game blueAlive getter
** Paramaters are: none
** What it does: gets blue status
** Returns: bool
*********************************************************************/
bool Game::getBlueAlive()
{
    return blueAlive;
}

/*********************************************************************
** Game blueChar setter
** Paramaters are: bool of char value
** What it does: sets blue char status
** Returns: bool
*********************************************************************/
void Game::setBlueAlive(bool setValue)
{
    blueAlive = setValue;
}

/*********************************************************************
** Game redAlive getter
** Paramaters are: none
** What it does: gets red status
** Returns: bool
*********************************************************************/
bool Game::getRedAlive()
{
    return redAlive;
}

/*********************************************************************
** Game redChar setter
** Paramaters are: bool of char value
** What it does: sets red char status
** Returns: bool
*********************************************************************/
void Game::setRedAlive(bool setValue)
{
    redAlive = setValue;
}

/*********************************************************************
** Game round getter
** Paramaters are: none
** What it does: gets current round number
** Returns: int
*********************************************************************/
int Game::getRounds()
{
    return rounds;
}

/*********************************************************************
** Game rounds setter
** Paramaters are: int of rounds to be set
** What it does: sets rounds status
** Returns: none
*********************************************************************/
void Game::setRounds(int incRounds)
{
    rounds = incRounds;
}

//ios_base calls cf. user703016, Works Cited
/*********************************************************************
** Game startFight
** Paramaters are: none
** What it does: IMPORTANT: Runs combat
** Returns: none
*********************************************************************/
void Game::startFight(Character* incBlueChar, Character* incRedChar, int& winner)
{
    setBlueChar(incBlueChar);
    setRedChar(incRedChar);
    std::cout.setstate(std::ios_base::failbit);
    std::cout << "Starting combat." << std::endl;
    //Loop for fight continuation
    while (getBlueAlive() == true && getRedAlive() == true) {
        int theRound = getRounds();
        setRounds(theRound + 1);
        blueTurn();
        //Check to see if someone died
        if (getBlueAlive() == true && getRedAlive() == true) {
            theRound = getRounds();
            //Apparently 2 turns is a round
            //setRounds(theRound + 1);
            redTurn();
        }
    }
    std::cout.clear();
    std::cout << "Combat ended after " << getRounds() << " rounds." << std::endl;
    
    //Output win msg
    if (getRedAlive() == false) {
        std::cout << "Player character wins the match!" << std::endl;
        winner = 0;
    }
    else if (getBlueAlive() == false) {
        std::cout << "Enemy character wins the match!" << std::endl;
        winner = 1;
    }

}

/*********************************************************************
** Game blueTurn fxn
** Paramaters are: none
** What it does: Blue attacks, Red defends
** Returns: none
*********************************************************************/
void Game::blueTurn()
{
    //Precombat status
    std::cout << std::endl;
    std::cout << "******************************" << std::endl;
    std::cout << "Round #" << getRounds() << " - Blue's turn" << std::endl;
    std::cout << "******************************" << std::endl;
    std::cout << "1a. Attacker type: " << blueChar->getName() << " (" << blueChar->getColor() << ")" << std::endl;
    std::cout << "1b. Defender type: " << redChar->getName() << " (" << redChar->getColor() << ")" << std::endl;
    std::cout << "2. Defender Stats:" << std::endl;
    std::cout << "    Type: " << redChar->getName() << " (" << redChar->getColor() << ")" << std::endl;
    std::cout << "    Armor: " << redChar->getArmor() << std::endl;
    std::cout << "    Strength Points: " << redChar->getStrengthPoints() << std::endl;

    //Combat happens here
    int blueAttack = blueChar->swing();
    redChar->defend(blueAttack);

    int redStrengthPoints = redChar->getStrengthPoints();
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    
    //See if red died
    if (redChar->getStrengthPoints() <= 0) {
        setRedAlive(false);
        std::cout << redChar->getColor() << " " << redChar->getName() << " died!" << std::endl;
        std::cout << "******************************" << std::endl;
        std::cout << "******************************" << std::endl;
        std::cout << std::endl;
    }
}

/*********************************************************************
** Game redTurn fxn
** Paramaters are: none
** What it does: Red attacks, Blue defends
** Returns: none
*********************************************************************/
void Game::redTurn()
{
    //Precombat status
    std::cout << std::endl;
    std::cout << "******************************" << std::endl;
    std::cout << "Round #" << getRounds() << " - Red's turn" << std::endl;
    std::cout << "******************************" << std::endl;
    std::cout << "1a. Attacker type: " << blueChar->getName() << " (" << blueChar->getColor() << ")" << std::endl;
    std::cout << "1b. Defender type: " << redChar->getName() << " (" << redChar->getColor() << ")" << std::endl; std::cout << "2. Defender Stats:" << std::endl;
    std::cout << "    Type: " << blueChar->getName() << " (" << blueChar->getColor() << ")" << std::endl;
    std::cout << "    Armor: " << blueChar->getArmor() << std::endl;
    std::cout << "    Strength Points: " << blueChar->getStrengthPoints() << std::endl;

    //Combat happens here
    int redAttack = redChar->swing();
    blueChar->defend(redAttack);

    int blueStrengthPoints = blueChar->getStrengthPoints();
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    
    //Check to see if blue died
    if (blueChar->getStrengthPoints() <= 0) {
        setBlueAlive(false);
        std::cout << blueChar->getColor() << " " << blueChar->getName() << " died!" << std::endl;
        std::cout << "******************************" << std::endl;
        std::cout << "******************************" << std::endl;
        std::cout << std::endl;
    }
}

/*********************************************************************
** Game deallocate fxn
** Paramaters are: none
** What it does: IMPORTANT: deallocates char pointers
** Returns: none
*********************************************************************/
void Game::deallocate()
{
    std::cout << std::endl;
    std::cout << "Deleted dynamic objects." << std::endl;
    std::cout << std::endl;
}
