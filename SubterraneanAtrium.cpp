/*********************************************************************
** Program Name: The Temple of Primal Evil
** Author: Andrew Helmsworth
** Date: 2019/12/08
** Description: Player Character object traverses linked list of Space objects,
** Description: ...& interacts with Spaces and InventoryObjects in a timed scenario.
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include "SubterraneanAtrium.hpp"
#include "Amulet.hpp"
#include "FocusingLens.hpp"
#include "InventoryObject.hpp"

SubterraneanAtrium::SubterraneanAtrium()
{
    name = "Subterranean Atrium";
}

SubterraneanAtrium::~SubterraneanAtrium()
{
}

int SubterraneanAtrium::draw(Character* incCharacter, int& passingArg)
{
    std::cout << "Somehow, a shaft of sunlight shines through the skylight above, bathing the room in a golden glow." << std::endl;
    
    if (this->solved == false) {
        std::cout << "Three mirrors have been installed around the perimeter." << std::endl;
        std::cout << "Something tells you they're meant to illuminate the jewel above the door before you." << std::endl;
        std::cout << std::endl;

        std::cout << "How will you orient the first mirror?" << std::endl;
        std::cout << "1: Position 1." << std::endl;
        std::cout << "2: Position 2." << std::endl;
        std::cout << "3: Position 3." << std::endl;
        int mirrorOne = getInt(1, 3);
        std::cout << std::endl;

        std::cout << "How will you orient the second mirror?" << std::endl;
        std::cout << "1: Position 1." << std::endl;
        std::cout << "2: Position 2." << std::endl;
        std::cout << "3: Position 3." << std::endl;
        int mirrorTwo = getInt(1, 3);
        std::cout << std::endl;

        std::cout << "How will you orient the first mirror?" << std::endl;
        std::cout << "1: Position 1." << std::endl;
        std::cout << "2: Position 2." << std::endl;
        std::cout << "3: Position 3." << std::endl;
        int mirrorThree = getInt(1, 3);
        std::cout << std::endl;

        std::cout << "You position the mirrors to orientations " << mirrorOne << " " << mirrorTwo << " " << mirrorThree << " and hold your breath." << std::endl;
        if (mirrorOne != 3 || mirrorTwo != 1 || mirrorThree != 2) {
            std::cout << "Ear-splitting sirens sound all around you!" << std::endl;
            std::cout << "A powerful laser is emitted from the jewel and focuses on the bomb on your back." << std::endl;
            std::cout << "You feel the explosives start to radiate heat." << std::endl;
            std::cout << std::endl;
            return -1;
        }
        else if (mirrorOne == 3 && mirrorTwo == 1 && mirrorThree == 2) {
            std::cout << "Success! The jewel glows red, and the door in front of you slides open." << std::endl;
            this->solved = true;
            std::cout << "The focusing lens in front of the jewel pops out of its socket." << std::endl;
            std::cout << std::endl;
        }
    }
    if (this->solved == true && this->looted == false) {
        std::cout << "Will you take the focusing lens with you?" << std::endl;
        std::cout << std::endl;
        std::cout << "1: Take the lens." << std::endl;
        std::cout << "2: Leave the lens in place." << std::endl;
        int lensChoice = getInt(1, 2);
        if (lensChoice == 1) {
            InventoryObject* theLens = new FocusingLens;
            std::cout << std::endl;
            std::cout << "Grabbed the Focusing Lens." << std::endl;
            std::cout << std::endl;
            if (incCharacter->getInventory()[0] == NULL) {
                InventoryObject** currentInventory = incCharacter->getInventory();
                currentInventory[0] = theLens;
                std::cout << std::endl;
                std::cout << "Placed Focusing Lens in inventory slot one." << std::endl;
                std::cout << std::endl;
                this->looted = true;
            }
            else if (incCharacter->getInventory()[0] != NULL && incCharacter->getInventory()[1] == NULL) {
                InventoryObject** currentInventory = incCharacter->getInventory();
                currentInventory[1] = theLens;
                std::cout << std::endl;
                std::cout << "Placed Focusing Lens in inventory slot two." << std::endl;
                std::cout << std::endl;
                this->looted = true;
            }
            else if (incCharacter->getInventory()[0] != NULL && incCharacter->getInventory()[1] != NULL) {
                
                bool loopDelete = true;

                while (loopDelete == true){
                    std::cout << "Your inventory is full. Destroy an item to pick it up?" << std::endl;
                    std::cout << "1: Delete item in slot one." << std::endl;
                    std::cout << "2: Delete item in slot two." << std::endl;
                    std::cout << "3: Put the lens back." << std::endl;
                    int deleteChoice = getInt(1, 2);
                    if (deleteChoice == 1 && incCharacter->getInventory()[0]->getName() != "Golden Amulet") {
                        InventoryObject** currentInventory = incCharacter->getInventory();
                        delete currentInventory[0];
                        currentInventory[0] = theLens;
                        loopDelete = false;
                        this->looted = true;
                        std::cout << std::endl;
                        std::cout << "Smart move. You destroy the item in slot one, then place the lens in inventory slot one." << std::endl;
                        std::cout << std::endl;
                    }
                    else if (deleteChoice == 2 && incCharacter->getInventory()[1]->getName() != "Golden Amulet") {
                        InventoryObject** currentInventory = incCharacter->getInventory();
                        delete currentInventory[1];
                        currentInventory[1] = theLens;
                        loopDelete = false;
                        this->looted = true;
                        std::cout << std::endl;
                        std::cout << "Smart move. You destroy the item in slot two, then place the key in inventory slot two." << std::endl;
                        std::cout << std::endl;
                    }
                    else if (deleteChoice == 3) {
                        loopDelete = false;
                        std::cout << std::endl;
                        std::cout << "Seems like a bad idea! But okay. You put the lens back." << std::endl;
                        std::cout << std::endl;
                    }
                    else {
                        std::cout << std::endl;
                        std::cout << "Something tells you that you shouldn't delete that item." << std::endl;
                    }
                }
            }


        }
        else if (lensChoice == 2) {
            std::cout << std::endl;
            std::cout << "If you say so! Leaving the lens where it is." << std::endl;
            std::cout << std::endl;
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
int SubterraneanAtrium::getInt(int min, int max)
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