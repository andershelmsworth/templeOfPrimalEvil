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
#include "Space.hpp"

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

    //Level functions
    void playJungleFloor(Character*, Space*, int&, int&, bool&, bool&, Space*);
    void playFoyer(Character*, Space*, int&, int&, bool&, bool&, Space*, Space*);
    void playSphinx(Character*, Space*, int&, int&, bool&, bool&);
    void playMightySeal(Character*, Space*, int&, int&, bool&, bool&);
    void playTomb(Character*, Space*, int&, int&, bool&, bool&);
    void playAtrium(Character*, Space*, int&, int&, bool&, bool&);
    void playRest(Character*, Space*, int&, int&, bool&, bool&);

    //Other member functions
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