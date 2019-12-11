/*********************************************************************
** Program Name: The Temple of Primal Evil
** Author: Andrew Helmsworth
** Date: 2019/12/08
** Description: Player Character object traverses linked list of Space objects,
** Description: ...& interacts with Spaces and InventoryObjects in a timed scenario.
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include "Space.hpp"
#include "Character.hpp"

Space::Space()
{
    north = NULL;
    northEast = NULL;
    east = NULL;
    southEast = NULL;
    south = NULL;
    southWest = NULL;
    west = NULL;
    northWest = NULL;
    center = NULL;

    character = NULL;

    looted = false;
    solved = false;
    contents = ' ';
}

Space::~Space()
{
}

Space* Space::getNorth()
{
    return this->north;
}

void Space::setNorth(Space* incSpace)
{
    this->north = incSpace;
}

Space* Space::getNorthEast()
{
    return this->northEast;
}

void Space::setNorthEast(Space* incSpace)
{
    this->northEast = incSpace;
}

Space* Space::getEast()
{
    return this->east;
}

void Space::setEast(Space* incSpace)
{
    this->east = incSpace;
}

Space* Space::getSouthEast()
{
    return this->southEast;
}

void Space::setSouthEast(Space* incSpace)
{
    this->southEast = incSpace;
}

Space* Space::getSouth()
{
    return this->south;
}

void Space::setSouth(Space* incSpace)
{
    this->south = incSpace;
}

Space* Space::getSouthWest()
{
    return this->southWest;
}

void Space::setSouthWest(Space* incSpace)
{
    this->southWest = incSpace;
}

Space* Space::getWest()
{
    return this->west;
}

void Space::setWest(Space* incSpace)
{
    this->west = incSpace;
}

Space* Space::getNorthWest()
{
    return this->northWest;
}

void Space::setNorthWest(Space* incSpace)
{
    this->northWest = incSpace;
}

Space* Space::getCenter()
{
    return this->center;
}

void Space::setCenter(Space* incSpace)
{
    this->center = incSpace;
}

bool Space::getSolved()
{
    return this->solved;
}

void Space::setOccupialbe(bool incBool)
{
    this->solved = incBool;
}

bool Space::getLooted()
{
    return this->looted;
}

void Space::setLooted(bool incBool)
{
    this->looted = incBool;
}

char Space::getContents()
{
    return this->contents;
}

void Space::setContents(char incChar)
{
    this->contents = incChar;
}

std::string Space::getName()
{
    return this->name;
}

void Space::setName(std::string incString)
{
    this->name = incString;
}

Character* Space::getCharacter()
{
    return this->character;
}

void Space::setCharacter(Character* incCharacter)
{
    this->character = incCharacter;
}
