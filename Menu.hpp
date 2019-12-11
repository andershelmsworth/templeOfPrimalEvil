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

#ifndef MENU_HPP
#define MENU_HPP

/*********************************************************************
** Menu class
** Abstraction it represents: menu for running game functions
** What it's for: building and running game
** How to use it: all functionality tied to showMenu()
*********************************************************************/
class Menu
{
public:
    //Con/destructors
    Menu();
    ~Menu();

    //Member functions
    void showMenu();
    int getInt(int, int);

private:
};

#endif // !MENU_HPP