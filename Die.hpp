/*********************************************************************
** Program Name: Dungeon Duel
** Author: Andrew Helmsworth
** Date: 2019/11/9
** Description: Characters with special abilities roll attack and defense die
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include <iostream>
#include <string>

#ifndef DIE_HPP
#define DIE_HPP

//CITATION: General structure of a C++ class 
//studied from relevant LearnCpp.com link in works cited.

/*********************************************************************
** Die class
** Abstraction it represents: base Die class
** What it's for: building and rolling a normal die
** How to use it: roll() or the constructor with an int parameter.
*********************************************************************/

class Die
{
public:

    //Con/destructors
    Die();
    Die(int);
    ~Die();

    //Getters and Setters

    //Member functions
    virtual int roll(int);


protected:
    int sides;
};

#endif // !DIE_HPP