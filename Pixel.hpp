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

#ifndef PIXEL_HPP
#define PIXEL_HPP

/*********************************************************************
** Menu class
** Abstraction it represents: menu for running Fibonacci functions
** What it's for: running recursive and iterative fxns 1k times
** How to use it: all functionality tied to showMenu()
*********************************************************************/
class Pixel
{
public:
    //Con/destructors
    Pixel();
    ~Pixel();

    //Getters/Setters
    char getNorth();
    void setNorth(char);
    char getNorthEast();
    void setNorthEast(char);
    char getEast();
    void setEast(char);
    char getSouthEast();
    void setSouthEast(char);
    char getSouth();
    void setSouth(char);
    char getSouthWest();
    void setSouthWest(char);
    char getWest();
    void setWest(char);
    char getNorthWest();
    void setNorthWest(char);
    char getCenter();
    void setCenter(char);

    bool getOccupiable();
    void setOccupiable(bool);

    char getContents();
    void setContents(char);

    //Member functions
    void draw();

protected:
    char north;
    char northEast;
    char east;
    char southEast;
    char south;
    char southWest;
    char west;
    char northWest;
    char center;

    bool occupiable;
    char contents;
};

#endif // !SPACE_HPP