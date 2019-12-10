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
#include "HarryPotter.hpp"
#include "Die.hpp"

/*********************************************************************
** HarryPotter default constructor
** Paramaters are: none
** What it does: Initializes HP stats
** Returns: No return data.
*********************************************************************/
HarryPotter::HarryPotter()
{
    name = "Harry Potter";
    attack = 6;
    defense = 6;
    armor = 0;
    strengthPoints = 10 ;
    extraLife = 1;
}

/*********************************************************************
** HarryPotter destructor
** Paramaters are: none
** What it does: destroys HP
** Returns: No return data.
*********************************************************************/
HarryPotter::~HarryPotter()
{
}

/*********************************************************************
** HarryPotter extraLife getter
** Paramaters are: none
** What it does: Gets HP 1UP
** Returns: int of 0 for none or 1 for 1UP
*********************************************************************/
int HarryPotter::getExtraLife()
{
    return this->extraLife;
}

/*********************************************************************
** HarryPotter extraLife setter
** Paramaters are: int of 1UP
** What it does: sets HP 1UP
** Returns: none
*********************************************************************/
void HarryPotter::setExtraLife(int xtraLife)
{
    this->extraLife = xtraLife;
}

/*********************************************************************
** HarryPotter swing fxn
** Paramaters are: none
** What it does: Rolls two die for attack damage, outputs status txt
** Returns: Int of attack roll
*********************************************************************/
int HarryPotter::swing()
{
    //Initialize die
    int dieSides = getAttack();
    Die attackDie(dieSides);
    //Roll twice
    int rollOne = attackDie.roll(dieSides);
    int rollTwo = attackDie.roll(dieSides);
    //Report back
    std::cout << "3. Attack dice roll: ";
    std::cout << getColor() << " Harry Potter rolled a " << rollOne << " and a " << rollTwo << " for a total of: " << rollOne + rollTwo << " damage." << std::endl;
    return (rollOne + rollTwo);
}

/*********************************************************************
** HarryPotter defend fxn
** Paramaters are: incoming damage (int)
** What it does: Rolls twice, resurrects if 1UP && SP < 0
** Returns: none
*********************************************************************/
void HarryPotter::defend(int incDamage)
{
    //Initialize die
    int dieSides = getDefense();
    Die defenseDieOne(dieSides);
    Die defenseDieTwo(dieSides);
    //Roll twice
    int rollOne = defenseDieOne.roll(dieSides);
    int rollTwo = defenseDieTwo.roll(dieSides);
    std::cout << "4. Defense dice roll: ";
    std::cout << getColor() << " Harry Potter rolled a " << rollOne << " and a " << rollTwo << " for a total of: " << rollOne + rollTwo << " defense." << std::endl;

    //std::this_thread::sleep_for(std::chrono::seconds(1));

    //Reckon dmg
    int actualDamageDealt = incDamage - (rollOne + rollTwo) - getArmor();
    std::cout << "5. Total inflicted damage calculation: " << incDamage << " incoming damage - ";
    std::cout << (rollOne + rollTwo) << " defense - ";
    std::cout << getArmor() << " armor = " << actualDamageDealt << " damage." << std::endl;


    if (actualDamageDealt < 0) {
        std::cout << "However, damage received was less than 0, so setting that value to 0." << std::endl;
        actualDamageDealt = 0;
    }

    //Initialze rez conditions
    int getPreCombatStrengthPoints = getStrengthPoints();
    int theoreticalNewLifeTotal = getPreCombatStrengthPoints - actualDamageDealt;
    int theExtraLife = getExtraLife();

    if (theoreticalNewLifeTotal > 0) {
        //No rez needed :/
        int currentStrengthPoints = getStrengthPoints();
        //Set new SP
        setStrengthPoints(currentStrengthPoints - actualDamageDealt);
        std::cout << "6. " << getColor() << " " << getName() << "'s updated strength point total after subtracting damage: " << getStrengthPoints() << std::endl;
    }
    else if (theoreticalNewLifeTotal <= 0 && theExtraLife == 1) {
        //Battle rez!! :D
        std::cout << "SPECIAL DEF: Hogwarts! " << getColor() << " Harry Potter's Strength Points dropped to " << theoreticalNewLifeTotal << std::endl;
        std::cout << "SPECIAL DEF SUCCESS: But the spirit of the phoenix him resurrected him to double the starting SP!" << std::endl;
        //Set new SP
        setStrengthPoints(20);
        std::cout << "Extra life replenished." << std::endl;
        //Set 1UP to 0
        setExtraLife(1);
        std::cout << "6. " << getColor() << " " << getName() << "'s updated strength point total after subtracting damage (and resurrection boost): " << getStrengthPoints() << std::endl;
    }
    else if (theoreticalNewLifeTotal <= 0 && theExtraLife == 0) {
        //Battle rez is on CD :(
        std::cout << "SPECIAL DEF: Hogwarts! " << getColor() << " Harry Potter's Strength Points dropped to " << theoreticalNewLifeTotal << std::endl;
        std::cout << "SPECIAL DEF FAIL: However, his extra life was expended. No more phoenixes :(" << std::endl;
        int currentStrengthPoints = getStrengthPoints();
        //Set new SP
        setStrengthPoints(currentStrengthPoints - actualDamageDealt);
        std::cout << "6. " << getColor() << " " << getName() << "'s updated strength point total after subtracting damage: " << getStrengthPoints() << std::endl;
    }

    //std::this_thread::sleep_for(std::chrono::seconds(1));

}
