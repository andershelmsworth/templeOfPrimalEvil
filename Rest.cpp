/*********************************************************************
** Program Name: The Temple of Primal Evil
** Author: Andrew Helmsworth
** Date: 2019/12/08
** Description: Player Character object traverses linked list of Space objects,
** Description: ...& interacts with Spaces and InventoryObjects in a timed scenario.
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include "Rest.hpp"

/*********************************************************************
** Rest default constructor
** Paramaters are: none
** What it does: sets name, sets character to null
** Returns: No return data.
*********************************************************************/
Rest::Rest()
{
    name = "Nameless One's Rest";
}

/*********************************************************************
** Rest destructor
** Paramaters are: none
** What it does: destroys Rest
** Returns: No return data.
*********************************************************************/
Rest::~Rest()
{
}

/*********************************************************************
** MightySeal draw
** Paramaters are: none
** What it does: runs level interaction
** Returns: 0
*********************************************************************/
int Rest::draw(Character* incCharacter, int& passingArg)
{
    if (this->solved == false) {
        std::cout << "The evil god sleeps fitfully on a dais in the center of the room." << std::endl;
        std::cout << "Two declivities flank a barred shaft at its base." << std::endl;
        std::cout << std::endl;

        std::string slotOne = "";
        std::string slotTwo = "";

        //Check if slots are null, initialize names if not
        if (incCharacter->getInventory()[0] != NULL) {
            slotOne = incCharacter->getInventory()[0]->getName();
        }

        if (incCharacter->getInventory()[1] != NULL) {
            slotTwo = incCharacter->getInventory()[1]->getName();
        }

        if ((slotOne == "Golden Amulet" && slotTwo == "Focusing Lens") || (slotOne == "Focusing Lens" && slotTwo == "Golden Amulet")) {
            //Has both items, ask to place
            std::cout << "Will you place the items in their sockets?" << std::endl;
            std::cout << "1: Place items." << std::endl;
            std::cout << "2: Turn back." << std::endl;
            int playerChoice = getInt(1, 2);

            if (playerChoice == 1) {
                //Decided to place, solved to true
                std::cout << "You place the amulet and the lens on either side of the shaft." << std::endl;
                std::cout << "The bars slide aside, revealing a bomb-sized hole underneath the god." << std::endl;
                std::cout << "You unstrap the bomb from your back and set it in place." << std::endl;
                std::cout << "Time to run like hell! Get to the surface before the timer expires!" << std::endl;
                std::cout << std::endl;
                InventoryObject** currentInventory = incCharacter->getInventory();
                solved = true;
                return 0;

            }
            else if (playerChoice == 2) {
                //Decided to leave, returning to Rumble
                std::cout << "You turn back from the sealed door." << std::endl;
                return 0;
            }
        }
        else {
            //Missing items, returning to Rumble
            std::cout << "You clearly lack an item required to continue." << std::endl;
            return 0;
        }
    }



	return 0;
}

/*********************************************************************
** Int input validator
** Paramaters are: ints describing inclusive range
** What it does: accepts integers in a range
** Returns: the selected integer, if it is in range
*********************************************************************/
int Rest::getInt(int min, int max)
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