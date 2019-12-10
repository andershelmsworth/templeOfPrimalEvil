/*********************************************************************
** Program Name: Dungeon Rumble
** Author: Andrew Helmsworth
** Date: 2019/11/11
** Description: Characters in Queues face off in a fantasy combat sim
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
#include "Character.hpp"

#ifndef GAME_HPP
#define GAME_HPP

//CITATION: General structure of a C++ class 
//studied from relevant LearnCpp.com link in works cited.
//&& Tusher, Works Cited
/*********************************************************************
** Game class
** Abstraction it represents: die-rolling instance
** What it's for: building chars and rolling die
** How to use it: all functionality tied to startFight, getBlueChar, getRedChar
*********************************************************************/

class Game
{
public:

    //Con/destructors
    Game();
    Game(Character*, Character*);
    ~Game();

    //Getters and Setters
    Character* getBlueChar();
    void setBlueChar(Character*);
    Character* getRedChar();
    void setRedChar(Character*);
    bool getBlueAlive();
    void setBlueAlive(bool);
    bool getRedAlive();
    void setRedAlive(bool);
    int getRounds();
    void setRounds(int);

    //Member functions
    void startFight(Character*, Character*, int&);
    void blueTurn();
    void redTurn();
    void deallocate();

private:
    //Private member variables
    Character* blueChar;
    Character* redChar;
    bool blueAlive;
    bool redAlive;
    int rounds;
};

#endif // !GAME_HPP
