/*********************************************************************
** Program Name: The Temple of Primal Evil
** Author: Andrew Helmsworth
** Date: 2019/12/08
** Description: Player Character object traverses linked list of Space objects,
** Description: ...& interacts with Spaces and InventoryObjects in a timed scenario.
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include "MightySeal.hpp"
#include "Amulet.hpp"
#include <string>

MightySeal::MightySeal()
{
	name = "The Mighty Seal";
}

MightySeal::~MightySeal()
{
}

int MightySeal::draw(Character* incPlayerCharacter, int& passingArg)
{
	std::cout << "You enter a narrow corridor." << std::endl;
	if (this->solved == false) {
		std::cout << "The way before you is sealed by a circular door, inscribed with arcane sigils." << std::endl;
		std::cout << "In the center of the door is a prominent keyhole." << std::endl;
        std::cout << std::endl;

        std::string slotOne = "";
        std::string slotTwo = "";

        if (incPlayerCharacter->getInventory()[0] != NULL) {
            slotOne = incPlayerCharacter->getInventory()[0]->getName();
        }

        if (incPlayerCharacter->getInventory()[1] != NULL) {
            slotTwo = incPlayerCharacter->getInventory()[1]->getName();
        }

		if (slotOne == "Shadowy Key" || slotTwo == "Shadowy Key") {
			std::cout << "Will you use the Shadowy Key to open the door before you?" << std::endl;
			std::cout << "1: Use the key." << std::endl;
			std::cout << "2: Turn back." << std::endl;
            int playerChoice = getInt(1, 2);
            
            if (playerChoice == 1) {
                std::cout << "You insert the Shadowy Key into the keyhole." << std::endl;
                std::cout << "The sigils on the door flicker and fade, and with a scream of hinges, the door slides open." << std::endl;
                std::cout << "\"No turning back now..\" you think to yourself." << std::endl;
                std::cout << "You return the key to your inventory." << std::endl;
                solved = true;

                if (this->looted == false) {
                    std::cout << std::endl;
                    std::cout << "You notice a gleaming amulet hanging from the back side of the open door." << std::endl;
                    std::cout << std::endl;
                    std::cout << "Will you take the amulet? It could come in useful later..." << std::endl;

                    std::cout << "1: Take the amulet with you." << std::endl;
                    std::cout << "2: Leave the amulet where it is." << std::endl;

                    int lootChoice = getInt(1, 2);

                    if (lootChoice == 2) {
                        std::cout << std::endl;
                        std::cout << "Seems like a bad idea! But okay. You leave the amulet where it is." << std::endl;
                        std::cout << std::endl;
                    }
                    else if (lootChoice == 1) {
                        std::cout << std::endl;
                        std::cout << "Wise move. You grab the amulet." << std::endl;
                        std::cout << std::endl;
                        InventoryObject* theAmulet = new Amulet;

                        if (incPlayerCharacter->getInventory()[0] == NULL) {
                            InventoryObject** currentInventory = incPlayerCharacter->getInventory();
                            currentInventory[0] = theAmulet;
                            std::cout << "Placed Golden Amulet in inventory slot one." << std::endl;
                            std::cout << std::endl;
                            this->looted = true;
                        }
                        else if (incPlayerCharacter->getInventory()[0] != NULL && incPlayerCharacter->getInventory()[1] == NULL) {
                            InventoryObject** currentInventory = incPlayerCharacter->getInventory();
                            currentInventory[1] = theAmulet;
                            std::cout << "Placed Golden Amulet in inventory slot two." << std::endl;
                            std::cout << std::endl;
                            this->looted = true;
                        }
                        else if (incPlayerCharacter->getInventory()[0] != NULL && incPlayerCharacter->getInventory()[1] != NULL) {
                            std::cout << std::endl;
                            std::cout << "Your inventory is full. Destroy an item to pick it up?" << std::endl;
                            std::cout << "1: Delete item in slot one." << std::endl;
                            std::cout << "2: Delete item in slot two." << std::endl;
                            std::cout << "3: Put the amulet back." << std::endl;
                            int deleteChoice = getInt(1, 2);
                            if (deleteChoice == 1) {
                                InventoryObject** currentInventory = incPlayerCharacter->getInventory();
                                delete currentInventory[0];
                                currentInventory[0] = theAmulet;
                                std::cout << std::endl;
                                std::cout << "Smart move. You destroy the item in slot one, then place the amulet in inventory slot one." << std::endl;
                                std::cout << std::endl;
                                this->looted = true;
                            }
                            else if (deleteChoice == 2) {
                                InventoryObject** currentInventory = incPlayerCharacter->getInventory();
                                delete currentInventory[1];
                                currentInventory[1] = theAmulet;
                                std::cout << std::endl;
                                std::cout << "Wise move. You destroy the item in slot two, then place the amulet in inventory slot two." << std::endl;
                                std::cout << std::endl;
                                this->looted = true;
                            }
                            else if (deleteChoice == 3) {
                                std::cout << std::endl;
                                std::cout << "Seems like a bad idea! But okay. You put the amulet back." << std::endl;
                                std::cout << std::endl;
                            }
                        }

                    }

                }
                return 0;

            }
            else if (playerChoice == 2) {
                std::cout << "You turn back from the sealed door." << std::endl;
                return -1;
            }
		}
        else if (slotOne != "Shadowy Key" && slotTwo != "Shadowy Key") {
            std::cout << "You clearly lack a key required to continue." << std::endl;
            return -1;
        }
	}
    else if (this->solved == true) {

        std::cout << "The way before you stands open." << std::endl;

        if (this->looted == false) {
            std::cout << "You notice a gleaming amulet hanging from the back side of the open door." << std::endl;
            std::cout << "Will you take the amulet? It could come in useful later..." << std::endl;

            std::cout << "1: Take the amulet with you." << std::endl;
            std::cout << "2: Leave the amulet where it is." << std::endl;

            int lootChoice = getInt(1, 2);

            if (lootChoice == 2) {
                std::cout << "Seems like a bad idea! But okay. You leave the amulet where it is." << std::endl;
            }
            else if (lootChoice == 1) {
                std::cout << "Wise move. You pick up the amulet." << std::endl;
                InventoryObject* theAmulet = new Amulet;


                if (incPlayerCharacter->getInventory()[0] == NULL) {
                    InventoryObject** currentInventory = incPlayerCharacter->getInventory();
                    currentInventory[0] = theAmulet;
                    std::cout << "Placed Golden Amulet in inventory slot one." << std::endl;
                }
                else if (incPlayerCharacter->getInventory()[0] != NULL && incPlayerCharacter->getInventory()[1] == NULL) {
                    InventoryObject** currentInventory = incPlayerCharacter->getInventory();
                    currentInventory[1] = theAmulet;
                    std::cout << "Placed Golden Amulet in inventory slot two." << std::endl;
                }
                else if (incPlayerCharacter->getInventory()[0] != NULL && incPlayerCharacter->getInventory()[1] != NULL) {
                    std::cout << "Your inventory is full. Destroy an item to pick it up?" << std::endl;
                    std::cout << "1: Delete item in slot one." << std::endl;
                    std::cout << "2: Delete item in slot two." << std::endl;
                    std::cout << "3: Put the amulet back." << std::endl;
                    int deleteChoice = getInt(1, 2);
                    if (deleteChoice == 1 && incPlayerCharacter->getInventory()[0]->getName() != "Focusing Lens") {
                        InventoryObject** currentInventory = incPlayerCharacter->getInventory();
                        delete currentInventory[0];
                        currentInventory[0] = theAmulet;
                        std::cout << "Wise move. You destroy the item in slot one, then place the key in inventory slot one." << std::endl;
                    }
                    else if (deleteChoice == 2 && incPlayerCharacter->getInventory()[1]->getName() != "Focusing Lens") {
                        InventoryObject** currentInventory = incPlayerCharacter->getInventory();
                        delete currentInventory[1];
                        currentInventory[1] = theAmulet;
                        std::cout << "Wise move. You destroy the item in slot two, then place the key in inventory slot two." << std::endl;
                    }
                    else if (deleteChoice == 3) {
                        std::cout << "Seems like a bad idea! But okay. You put the amulet back." << std::endl;
                    }
                    else {
                        std::cout << "You can't delete that item. Better come back later and try a different inventory space if you want the amulet." << std::endl;
                    }
                }

            }

        }

        return 0;
    }
	return 2;
}

/*********************************************************************
** Int input validator
** Paramaters are: ints describing inclusive range
** What it does: accepts integers in a range
** Returns: the selected integer, if it is in range
*********************************************************************/
int MightySeal::getInt(int min, int max)
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