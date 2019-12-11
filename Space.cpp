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

/*********************************************************************
** Space default constructor
** Paramaters are: none
** What it does: sets pointers to null and solved/looted to false
** Returns: No return data.
*********************************************************************/
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

/*********************************************************************
** Space destructor
** Paramaters are: none
** What it does: destroys Space
** Returns: No return data.
*********************************************************************/
Space::~Space()
{
}

/*********************************************************************
** north getter
** Paramaters are: none
** What it does: gets north
** Returns: Space pointer
*********************************************************************/
Space* Space::getNorth()
{
    return this->north;
}

/*********************************************************************
** north setter
** Paramaters are: Space pointer
** What it does: sets north
** Returns: none
*********************************************************************/
void Space::setNorth(Space* incSpace)
{
    this->north = incSpace;
}

/*********************************************************************
** northEast getter
** Paramaters are: none
** What it does: gets northEast
** Returns: Space pointer
*********************************************************************/
Space* Space::getNorthEast()
{
    return this->northEast;
}

/*********************************************************************
** northEast setter
** Paramaters are: Space pointer
** What it does: sets northEast
** Returns: none
*********************************************************************/
void Space::setNorthEast(Space* incSpace)
{
    this->northEast = incSpace;
}

/*********************************************************************
** east getter
** Paramaters are: none
** What it does: gets east
** Returns: Space pointer
*********************************************************************/
Space* Space::getEast()
{
    return this->east;
}

/*********************************************************************
** east setter
** Paramaters are: Space pointer
** What it does: sets east
** Returns: none
*********************************************************************/
void Space::setEast(Space* incSpace)
{
    this->east = incSpace;
}

/*********************************************************************
** southEast getter
** Paramaters are: none
** What it does: gets southEast
** Returns: Space pointer
*********************************************************************/
Space* Space::getSouthEast()
{
    return this->southEast;
}

/*********************************************************************
** southEast setter
** Paramaters are: Space pointer
** What it does: sets southEast
** Returns: none
*********************************************************************/
void Space::setSouthEast(Space* incSpace)
{
    this->southEast = incSpace;
}

/*********************************************************************
** south getter
** Paramaters are: none
** What it does: gets south
** Returns: Space pointer
*********************************************************************/
Space* Space::getSouth()
{
    return this->south;
}

/*********************************************************************
** south setter
** Paramaters are: Space pointer
** What it does: sets south
** Returns: none
*********************************************************************/
void Space::setSouth(Space* incSpace)
{
    this->south = incSpace;
}

/*********************************************************************
** southWest getter
** Paramaters are: none
** What it does: gets southWest
** Returns: Space pointer
*********************************************************************/
Space* Space::getSouthWest()
{
    return this->southWest;
}

/*********************************************************************
** southWest setter
** Paramaters are: Space pointer
** What it does: sets southWest
** Returns: none
*********************************************************************/
void Space::setSouthWest(Space* incSpace)
{
    this->southWest = incSpace;
}

/*********************************************************************
** west getter
** Paramaters are: none
** What it does: gets west
** Returns: Space pointer
*********************************************************************/
Space* Space::getWest()
{
    return this->west;
}

/*********************************************************************
** west setter
** Paramaters are: Space pointer
** What it does: sets west
** Returns: none
*********************************************************************/
void Space::setWest(Space* incSpace)
{
    this->west = incSpace;
}

/*********************************************************************
** northWest getter
** Paramaters are: none
** What it does: gets northWest
** Returns: Space pointer
*********************************************************************/
Space* Space::getNorthWest()
{
    return this->northWest;
}

/*********************************************************************
** northWest setter
** Paramaters are: Space pointer
** What it does: sets northWest
** Returns: none
*********************************************************************/
void Space::setNorthWest(Space* incSpace)
{
    this->northWest = incSpace;
}

/*********************************************************************
** center getter
** Paramaters are: none
** What it does: gets center
** Returns: Space pointer
*********************************************************************/
Space* Space::getCenter()
{
    return this->center;
}

/*********************************************************************
** center setter
** Paramaters are: Space pointer
** What it does: sets center
** Returns: none
*********************************************************************/
void Space::setCenter(Space* incSpace)
{
    this->center = incSpace;
}

/*********************************************************************
** solved getter
** Paramaters are: none
** What it does: gets solved
** Returns: bool
*********************************************************************/
bool Space::getSolved()
{
    return this->solved;
}

/*********************************************************************
** solved setter
** Paramaters are: bool
** What it does: sets solved
** Returns: none
*********************************************************************/
void Space::setOccupialbe(bool incBool)
{
    this->solved = incBool;
}

/*********************************************************************
** looted getter
** Paramaters are: none
** What it does: gets looted
** Returns: bool
*********************************************************************/
bool Space::getLooted()
{
    return this->looted;
}

/*********************************************************************
** looted setter
** Paramaters are: bool
** What it does: sets looted
** Returns: none
*********************************************************************/
void Space::setLooted(bool incBool)
{
    this->looted = incBool;
}

/*********************************************************************
** contents getter
** Paramaters are: none
** What it does: gets contents
** Returns: char
*********************************************************************/
char Space::getContents()
{
    return this->contents;
}

/*********************************************************************
** contents setter
** Paramaters are: char
** What it does: sets contents
** Returns: none
*********************************************************************/
void Space::setContents(char incChar)
{
    this->contents = incChar;
}

/*********************************************************************
** name getter
** Paramaters are: none
** What it does: gets name
** Returns: string
*********************************************************************/
std::string Space::getName()
{
    return this->name;
}

/*********************************************************************
** name setter
** Paramaters are: string
** What it does: sets name
** Returns: none
*********************************************************************/
void Space::setName(std::string incString)
{
    this->name = incString;
}

/*********************************************************************
** character getter
** Paramaters are: none
** What it does: gets character
** Returns: Character pointer
*********************************************************************/
Character* Space::getCharacter()
{
    return this->character;
}

/*********************************************************************
** character setter
** Paramaters are: Character pointer
** What it does: sets character
** Returns: none
*********************************************************************/
void Space::setCharacter(Character* incCharacter)
{
    this->character = incCharacter;
}
