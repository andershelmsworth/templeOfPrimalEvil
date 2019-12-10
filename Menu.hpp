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

#ifndef MENU_HPP
#define MENU_HPP

/*********************************************************************
** Menu class
** Abstraction it represents: menu for running Fibonacci functions
** What it's for: running recursive and iterative fxns 1k times
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
    void runFibonacciR(int);
    void runFibonacciNR(int);
    int getInt(int, int);

private:
};

#endif // !MENU_HPP