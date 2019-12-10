/*********************************************************************
** Program Name: Fibonacci Timing Tool
** Author: Andrew Helmsworth
** Date: 2019/12/05
** Description: Compares the time required to calculate a Fibonacci number...
** Description: ...with iteration vs. recursion.
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>

#ifndef SPACE_HPP
#define SPACE_HPP


//Forward declaration
class Character;

/*********************************************************************
** Menu class
** Abstraction it represents: menu for running Fibonacci functions
** What it's for: running recursive and iterative fxns 1k times
** How to use it: all functionality tied to showMenu()
*********************************************************************/
class Space
{
public:
    //Con/destructors
    Space();
    virtual ~Space() = 0;

    //Getters/Setters
    Space* getNorth();
    void setNorth(Space*);
    Space* getNorthEast();
    void setNorthEast(Space*);
    Space* getEast();
    void setEast(Space*);
    Space* getSouthEast();
    void setSouthEast(Space*);
    Space* getSouth();
    void setSouth(Space*);
    Space* getSouthWest();
    void setSouthWest(Space*);
    Space* getWest();
    void setWest(Space*);
    Space* getNorthWest();
    void setNorthWest(Space*);
    Space* getCenter();
    void setCenter(Space*);

    bool getOccupiable();
    void setOccupialbe(bool);

    char getContents();
    void setContents(char);

    std::string getName();
    void setName(std::string);

    Character* getCharacter();
    void setCharacter(Character*);

    //Member functions
    virtual void draw() = 0;

protected:
    Space* north;
    Space* northEast;
    Space* east;
    Space* southEast;
    Space* south;
    Space* southWest;
    Space* west;
    Space* northWest;
    Space* center;

    bool occupiable;
    char contents;
    std::string name;
    Character* character;
};

#endif // !SPACE_HPP