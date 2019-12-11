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
#include <ctime>
#include <time.h>
#include <chrono>
#include "Menu.hpp"
#include "Space.hpp"
#include "Rumble.hpp"

/*********************************************************************
** Menu constructor
** Paramaters are: none
** What it does: not really used, no member variables to initialize
** Returns: No return data.
*********************************************************************/
Menu::Menu()
{
}

/*********************************************************************
** Menu destructor
** Paramaters are: none
** What it does: destroys menu
** Returns: No return data.
*********************************************************************/
Menu::~Menu()
{
}

/*********************************************************************
** ShowMenu fxn
** Paramaters are: none
** What it does: runs the recursive and iterative menu functions
** Returns: none
*********************************************************************/
void Menu::showMenu()
{
    std::cout << "Welcome to the Temple of Primal Evil!" << std::endl;
    int firstRun = 0;

    //Loop as long as 6 isn't selected.
    while (firstRun == 0) {
        //Showing options
        std::cout << std::endl;
        std::cout << "Please make a selection from the following options:" << std::endl;
        std::cout << "1. Play game." << std::endl;
        std::cout << "2. Exit." << std::endl;
        std::cout << std::endl;
        
        //Get menu selection from user
        int selection = getInt(1, 2);

        if (selection == 1) {
            std::cout << std::endl;
            std::cout << "||||THE TEMPLE OF PRIMAL EVIL||||" << std::endl;
            std::cout << std::endl;
            std::cout << "You, our intrepid hero, have been hand-selected for a daring mission to save the world." << std::endl;
            std::cout << "An ancient god slumbers in the depths of a long-forgotten temple, buried beneath the floor of a dense jungle." << std::endl;
            std::cout << "The nation's top scientists predict the god will soon awake, wreaking havoc across the globe." << std::endl;
            std::cout << "Descend to the bottom of the temple, plant your bomb, and make your escape before the bomb detonates!" << std::endl;
            std::cout << std::endl;

            Rumble* theRumble = new Rumble;
            theRumble->runRumble();
            delete theRumble;
        }
        else if (selection == 2) {
            //Exit while loop and exit program
            firstRun = 1;
        }
        else {
            return;
        }
    }
}

/*********************************************************************
** Int input validator
** Paramaters are: ints describing inclusive range
** What it does: accepts integers in a range
** Returns: the selected integer, if it is in range
*********************************************************************/
int Menu::getInt(int min, int max)
{
    //Conditions for continuing loop and checking input
    std::string intArray = "1234567890-";
    int inputSelection;
    std::string userInput;
    bool keepLooping = true;

    while (keepLooping == true) {
        //CITATION: Herle, johnathan, Johnston, Italia, Works Cited
        std::cout << "Enter an integer from " << min << " to " << max << ":" << std::endl;
        std::getline(std::cin, userInput);

        //Probably don't need to check for input failure, but being intentionally paranoid
        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << "Input failure, try again please:" << std::endl;
        }
        else if (userInput.size() == 0) {
            //User input simply [Enter]
            std::cout << "How rude! Try again please:" << std::endl;
        }
        else {
            //Looping through each character in array
            //Comapring each character to each digit
            //Incrementing if a digit is found
            int stringLength = userInput.size();
            int intFound = 0;
            for (int i = 0; i < stringLength; i++) {
                for (int j = 0; j < 11; j++) {
                    if (userInput[i] == intArray[j]) {
                        intFound++;
                    }
                }
            }
            //Build substring of all input after position 0
            std::string substring = userInput.substr(1, (userInput.size() - 1));

            //If the number of found integers is less than string length or string is empty
            if (intFound < stringLength || stringLength == 0) {
                std::cin.clear();
                std::cout << "Non-digits in input buffer, try again please:" << std::endl;
            }
            else if (substring.find('-') != std::string::npos) {
                //If negative sign found outside of position 0
                std::cin.clear();
                std::cout << "Negation sign must be at head of string:" << std::endl;
            }
            else {
                //Again, prolly don't need this in a try-catch but being safe
                try
                {
                    //Try casting to int, catching exception
                    inputSelection = std::stoi(userInput);
                    if (inputSelection >= min && inputSelection <= max) {
                        keepLooping = false;
                        return inputSelection;
                    }
                    else {
                        std::cin.clear();
                        std::cout << "Input out of range, try again please:" << std::endl;
                    }
                }
                catch (const std::exception&)
                {
                    std::cin.clear();
                    std::cout << "Input threw exception, try again please: " << std::endl;
                }
            }
        }
    }
    return 0;
}