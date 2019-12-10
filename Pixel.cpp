#include "Pixel.hpp"

Pixel::Pixel()
{
    north = '-';
    northEast = '+';
    east = '|';
    southEast = '+';
    south = '-';
    southWest = '+';
    west = '|';
    northWest = '+';
    center = ' ';
}

Pixel::~Pixel()
{
}

char Pixel::getNorth()
{
    return this->north;
}

void Pixel::setNorth(char incChar)
{
    this->north = incChar;
}

char Pixel::getNorthEast()
{
    return this->northEast;
}

void Pixel::setNorthEast(char incChar)
{
    this->northEast = incChar;
}

char Pixel::getEast()
{
    return this->east;
}

void Pixel::setEast(char incChar)
{
    this->east = incChar;
}

char Pixel::getSouthEast()
{
    return this->southEast;
}

void Pixel::setSouthEast(char incChar)
{
    this->southEast = incChar;
}

char Pixel::getSouth()
{
    return this->south;
}

void Pixel::setSouth(char incChar)
{
    this->south = incChar;
}

char Pixel::getSouthWest()
{
    return this->southWest;
}

void Pixel::setSouthWest(char incChar)
{
    this->southWest = incChar;
}

char Pixel::getWest()
{
    return this->west;
}

void Pixel::setWest(char incChar)
{
    this->west = incChar;
}

char Pixel::getNorthWest()
{
    return this->northWest;
}

void Pixel::setNorthWest(char incChar)
{
    this->northWest = incChar;
}

char Pixel::getCenter()
{
    return this->center;
}

void Pixel::setCenter(char incChar)
{
    this->center = incChar;
}

bool Pixel::getOccupiable()
{
    return false;
}

void Pixel::setOccupiable(bool)
{
}

char Pixel::getContents()
{
    return 0;
}

void Pixel::setContents(char)
{
}

void Pixel::draw()
{
}
