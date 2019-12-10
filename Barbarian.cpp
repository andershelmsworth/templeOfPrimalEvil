/*********************************************************************
** Program Name: Dungeon Duel
** Author: Andrew Helmsworth
** Date: 2019/11/9
** Description: Characters with special abilities roll attack and defense die
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include <thread>
#include <chrono>
#include "Barbarian.hpp"
#include "Die.hpp"

/*********************************************************************
** Barbarian default constructor
** Paramaters are: none
** What it does: Initializes Barb stats
** Returns: No return data.
*********************************************************************/
Barbarian::Barbarian()
{
    this->name = "Barbarian";
    this->attack = 6;
    this->defense = 6;
    this->armor = 0;
    this->strengthPoints = 12;
}

/*********************************************************************
** Barbarian destructor
** Paramaters are: none
** What it does: Destroys Barb
** Returns: No return data.
*********************************************************************/
Barbarian::~Barbarian()
{
}

/*********************************************************************
** Barbarian swing fxn
** Paramaters are: none
** What it does: Rolls two die for attack damage, outputs status txt
** Returns: Int of attack roll
*********************************************************************/
int Barbarian::swing()
{
    //Initialize die
    int dieSides = getAttack();
    Die attackDie(dieSides);
    //Roll twice
    int rollOne = attackDie.roll(dieSides);
    int rollTwo = attackDie.roll(dieSides);
    //Report back
    std::cout << "3. Attack dice roll: ";
    std::cout << getColor() << " Barbarian rolled a " << rollOne << " and a " << rollTwo << " for a total of: " << rollOne + rollTwo << " damage." << std::endl;
    return (rollOne + rollTwo);
}

/*********************************************************************
** Barbarian defend fxn
** Paramaters are: incoming damage (int)
** What it does: Rolls two die for defense score, adjusts SP, outputs status txt
** Returns: none
*********************************************************************/
void Barbarian::defend(int incDamage)
{
    //Initialize die
    int dieSides = getDefense();
    Die defenseDieOne(dieSides);
    Die defenseDieTwo(dieSides);
    //Roll twice
    int rollOne = defenseDieOne.roll(dieSides);
    int rollTwo = defenseDieTwo.roll(dieSides);
    std::cout << "4. Defense dice roll: ";
    std::cout << getColor() << " Barbarian rolled a " << rollOne << " and a " << rollTwo << " for a total of: " << rollOne + rollTwo << " defense." << std::endl;
    
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    //Calculate rec'd dmg
    int actualDamageDealt = incDamage - (rollOne + rollTwo) - getArmor();
    std::cout << "5. Total inflicted damage calculation: " << incDamage << " incoming damage - ";
    std::cout << (rollOne + rollTwo) << " defense - ";
    std::cout << getArmor() << " armor = " << actualDamageDealt << " damage." << std::endl;

    if (actualDamageDealt < 0) {
        std::cout << "However, damage received was less than 0, so setting that value to 0." << std::endl;
        actualDamageDealt = 0;
    }

    //Adjust SP
    int currentStrengthPoints = getStrengthPoints();
    setStrengthPoints(currentStrengthPoints - actualDamageDealt);

    //std::this_thread::sleep_for(std::chrono::seconds(1));
    //Report status
    std::cout << "6. " << getColor() << " " << getName() << "'s updated strength point total after subtracting damage: " << getStrengthPoints() << std::endl;
}
