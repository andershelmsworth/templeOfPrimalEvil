/*********************************************************************
** Program Name: The Temple of Primal Evil
** Author: Andrew Helmsworth
** Date: 2019/12/08
** Description: Player Character object traverses linked list of Space objects,
** Description: ...& interacts with Spaces and InventoryObjects in a timed scenario.
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>



namespace nest {
    
#ifndef RUMBLE2_HPP
#define RUMBLE2_HPP

    /*********************************************************************
    ** Rumble class
    ** Abstraction it represents: main game and level functions
    ** What it's for: running game and level functions
    ** How to use it: all functionality tied to runRumble()
    *********************************************************************/
    class Rumble2
    {
    public:
        //Con/destructors
        Rumble2();
        Rumble2(int);
        ~Rumble2();

        //Other member functions
        void runRumble();
        int getRounds();
        //int getInt(int, int);

    private:
        //Private datamembers
        //Queue* blueTeam;
        //Queue* redTeam;
        //Queue* losersBracket;
        //int blueScore;
        //int redScore;
    };

#endif // !RUMBLE2_HPP


}


