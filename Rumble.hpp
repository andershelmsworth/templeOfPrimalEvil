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
#include "Queue.hpp"

#ifndef RUMBLE_HPP
#define RUMBLE_HPP

/*********************************************************************
** Rumble class
** Abstraction it represents: tournament pitting Queues against each other
** What it's for: running game and Queue functions
** How to use it: all functionality tied to runRumble()
*********************************************************************/
class Rumble
{
public:
    //Con/destructors
    Rumble();
    ~Rumble();

    //Getter/Setter functions
    Queue* getBlueTeam();
    void setBlueTeam(Queue*);
    Queue* getRedTeam();
    void setRedTeam(Queue*);
    Queue* getLosersBracket();
    void setLosersBracket(Queue*);
    int getBlueScore();
    void setBlueScore(int);
    int getRedScore();
    void setRedScore(int);

    //Member functions
    void gameOver();
    void printStatus();
    void matchHeader(int);
    void runRumble();
    int getInt(int, int);

private:
    //Private datamembers
    Queue* blueTeam;
    Queue* redTeam;
    Queue* losersBracket;
    int blueScore;
    int redScore;
};

#endif // !MENU_HPP