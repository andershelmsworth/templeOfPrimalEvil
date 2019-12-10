/*********************************************************************
** Program Name: Dungeon Rumble
** Author: Andrew Helmsworth
** Date: 2019/11/11
** Description: Characters in Queues face off in a fantasy combat sim
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include "Rumble.hpp"
#include "Character.hpp"
#include "HarryPotter.hpp"
#include "Space.hpp"
#include "JungleFloor.hpp"
#include "Queue.hpp"
#include "TempleFoyer.hpp"
#include "Barbarian.hpp"
#include "InventoryObject.hpp"
#include "ShadowKey.hpp"
#include "LairOfTheSphinx.hpp"
#include "MightySeal.hpp"

/*********************************************************************
** Rumble constructor
** Paramaters are: none
** What it does: intitializes member variables
** Returns: No return data.
*********************************************************************/
Rumble::Rumble()
{
    blueScore = 0;
    blueTeam = NULL;
    redScore = 0;
    redTeam = NULL;
    losersBracket = NULL;
}

/*********************************************************************
** Rumble destructor
** Paramaters are: none
** What it does: destroys Rumble
** Returns: No return data.
*********************************************************************/
Rumble::~Rumble()
{
}


/*********************************************************************
** runRumble fxn
** Paramaters are: none
** What it does: runs main tournament logic, pits Queues against each other
** Returns: none
*********************************************************************/
void Rumble::runRumble()
{
    //seeding random
    srand(time(0));
    int rounds = 60;

    bool won = false;
    bool dead = false;

    Character* playerCharacter = new HarryPotter;
    //Queue* templeQueue = new Queue;
    Space* jungleFloor = new JungleFloor;
    Space* templeFoyer = new TempleFoyer;
    Space* sphinxLair = new LairOfTheSphinx;
    Space* mightySeal = new MightySeal;

    jungleFloor->setSouth(templeFoyer);
    templeFoyer->setNorth(jungleFloor);
    templeFoyer->setSouth(sphinxLair);
    sphinxLair->setNorth(templeFoyer);
    sphinxLair->setSouth(mightySeal);
    mightySeal->setNorth(sphinxLair);

    jungleFloor->setCharacter(playerCharacter);
    playerCharacter->setSpace(jungleFloor);

    //templeQueue->addBack(jungleFloor);
    //templeQueue->addBack(templeFoyer);
    //templeQueue->addBack(sphinxLair);

    int passingArgument = 0;

    //Loop while both teams have characters
    while (won == false && dead == false && rounds > 0) {
        if (playerCharacter->getSpace()->getName() == "Jungle Floor") {
            //playerCharacter->setSpace(jungleFloor);
            jungleFloor->setCharacter(playerCharacter);
            std::cout << std::endl;
            std::cout << "You are now on the Jungle Floor." << std::endl;
            std::cout << rounds << " minutes remain until automatic detonation." << std::endl;
            std::cout << std::endl;
            std::cout << "Enter the door below to proceed into the temple." << std::endl;
            std::cout << "1: Enter the door [-5 minutes]" << std::endl;
            std::cout << "2: Run away and go home." << std::endl;
            int playerChoice = getInt(1, 2);
            
            if (playerChoice == 2) {
                dead = true;
                std::cout << "You gave up :( The sleeping god awoke and destroyed the world, and you along with it! Shame!" << std::endl;
            }
            else if (playerChoice == 1) {
                rounds = rounds - 5;
                //Space* tempSpace = templeQueue->removeFront();
                //templeQueue->addBack(tempSpace);
                playerCharacter->setSpace(playerCharacter->getSpace()->getSouth());
                std::cout << "You descend through the door into the temple." << std::endl;
            }

        }
        else if (playerCharacter->getSpace()->getName() == "Temple Foyer") {
            templeFoyer->setCharacter(playerCharacter);
            std::cout << std::endl;
            std::cout << "You are now in the Temple Foyer." << std::endl;
            std::cout << rounds << " minutes remain until automatic detonation." << std::endl;
            std::cout << std::endl;
            std::cout << "A pile of scattered bones quivers and shakes." << std::endl;
            std::cout << "With a shudder, a spooky skellington springs to life! Slay him or die!" << std::endl;
            std::cout << std::endl;
            std::cout << "1: Fight the skellington." << std::endl;
            std::cout << "2: Try to run away." << std::endl;
            int playerChoice = getInt(1, 2);
            if (playerChoice == 2) {
                dead = true;
                std::cout << "The skellington caught up with you and ran you through with his sword. What an end!" << std::endl;
            }
            else if (playerChoice == 1) {
                int roundsElapsed = playerCharacter->getSpace()->draw(playerCharacter, passingArgument);
                rounds = rounds - roundsElapsed;
                std::cout << std::endl;
                std::cout << "Fighting the skellington ate up precious time!" << std::endl;
                std::cout << roundsElapsed << " minutes elapsed." << std::endl;
                std::cout << std::endl;
                if (rounds <= 0) {
                    std::cout << "Ran out of time fighting the skellington!" << std::endl;
                }
                else {
                    std::cout << "On the skellington's ominously trembling bones, a shadowy key appears." << std::endl;
                    std::cout << "Something tells you you might have to fight him again if you return this way." << std::endl;
                    std::cout << "Will you pick up the key?" << std::endl;
                    std::cout << std::endl;
                    std::cout << "1: Pick up the key." << std::endl;
                    std::cout << "2: Leave it where it is." << std::endl;
                    int keyChoice = getInt(1, 2);

                    if (keyChoice == 2) {
                        std::cout << "Seems like a bad idea! But okay. You leave the key where it is. It dissapates into mist as you walk away." << std::endl;
                    }
                    else if (keyChoice == 1) {
                        std::cout << "Wise move. You pick up the key." << std::endl;
                        InventoryObject* shadowKey = new ShadowKey;


                        if (playerCharacter->getInventory()[0] == NULL) {
                            InventoryObject** currentInventory = playerCharacter->getInventory();
                            currentInventory[0] = shadowKey;
                            std::cout << "Placed Shadowy Key in inventory slot one." << std::endl;
                        }
                        else if (playerCharacter->getInventory()[0] != NULL && playerCharacter->getInventory()[1] == NULL) {
                            InventoryObject** currentInventory = playerCharacter->getInventory();
                            currentInventory[1] = shadowKey;
                            std::cout << "Placed Shadowy Key in inventory slot two." << std::endl;
                        }
                        else if (playerCharacter->getInventory()[0] != NULL && playerCharacter->getInventory()[1] != NULL) {
                            std::cout << "Your inventory is full. Destroy an item to pick it up?" << std::endl;
                            std::cout << "1: Delete item in slot one." << std::endl;
                            std::cout << "2: Delete item in slot two." << std::endl;
                            std::cout << "3: Put the key back." << std::endl;
                            int deleteChoice = getInt(1, 2);
                            if (deleteChoice == 1) {
                                InventoryObject** currentInventory = playerCharacter->getInventory();
                                delete currentInventory[0];
                                currentInventory[0] = shadowKey;
                                std::cout << "Wise move. You destroy the item in slot one, then place the key in inventory slot one." << std::endl;
                            }
                            else if (deleteChoice == 2) {
                                InventoryObject** currentInventory = playerCharacter->getInventory();
                                delete currentInventory[1];
                                currentInventory[1] = shadowKey;
                                std::cout << "Wise move. You destroy the item in slot two, then place the key in inventory slot two." << std::endl;
                            }
                            else if (deleteChoice == 3) {
                                std::cout << "Seems like a bad idea! But okay. You put the key back. It dissapates into mist as you walk away." << std::endl;
                            }
                        }

                    }
                    std::cout << std::endl;
                    std::cout << "Descend the ladder to proceed?" << std::endl;
                    std::cout << "1: Descend [-5 minutes]" << std::endl;
                    std::cout << "2: Return to the surface [-5 minutes]" << std::endl;
                    int playerChoice = getInt(1, 2);

                    if (playerChoice == 2) {
                        //Space* tempSpace = templeQueue->getFront()->getNorth();
                        //templeQueue->removeBack();
                        //templeQueue->addFront(tempSpace);
                        playerCharacter->setSpace(playerCharacter->getSpace()->getNorth());
                        std::cout << "You return through the door, making your way back to the surface." << std::endl;
                        rounds = rounds - 5;
                    }
                    else if (playerChoice == 1) {
                        //Space* tempSpace = templeQueue->removeFront();
                        //templeQueue->addBack(tempSpace);
                        playerCharacter->setSpace(playerCharacter->getSpace()->getSouth());
                        std::cout << "You descend the ladder, making your way deeper into the temple." << std::endl;
                        rounds = rounds - 5;
                    }
                }
            }
        }
        else if (playerCharacter->getSpace()->getName() == "Lair of the Sphinx") {
            std::cout << std::endl;
            std::cout << "You are now in the Lair of the Sphinx." << std::endl;
            std::cout << rounds << " minutes remain until automatic detonation." << std::endl;
            std::cout << std::endl;
            std::cout << "An imperious statue guards the way." << std::endl;
            int playerGuesses = 0;
            sphinxLair->setCharacter(playerCharacter);
            sphinxLair->draw(playerCharacter, playerGuesses);
            rounds = rounds - playerGuesses;

            if (rounds > 0) {
                std::cout << "The Sphinx decided to let you pass. Will you return up the ladder or descend the steps beneath its feet?" << std::endl;
                std::cout << "1: Descend [-5 minutes]" << std::endl;
                std::cout << "2: Return up the ladder [-5 minutes]" << std::endl;
                int playerChoice = getInt(1, 2);

                if (playerChoice == 2) {
                    //Space* tempSpace = templeQueue->getFront()->getNorth();
                    //templeQueue->removeBack();
                    //templeQueue->addFront(tempSpace);
                    playerCharacter->setSpace(playerCharacter->getSpace()->getNorth());
                    std::cout << "You return up the ladder, making your way back to the foyer." << std::endl;
                    rounds = rounds - 5;
                }
                else if (playerChoice == 1) {
                    //Space* tempSpace = templeQueue->removeFront();
                    //templeQueue->addBack(tempSpace);
                    playerCharacter->setSpace(playerCharacter->getSpace()->getSouth());
                    std::cout << "You descend the steps, making your way deeper into the temple." << std::endl;
                    rounds = rounds - 5;
                }
            }
        }
        else if (playerCharacter->getSpace()->getName() == "The Mighty Seal") {
            std::cout << std::endl;
            std::cout << "You are now in the Mighty Seal." << std::endl;
            std::cout << rounds << " minutes remain until automatic detonation." << std::endl;
            std::cout << std::endl;
            mightySeal->setCharacter(playerCharacter);
            int sealSuccess = mightySeal->draw(playerCharacter, passingArgument);

            if (sealSuccess == 0) {
                std::cout << std::endl;
                std::cout << "Proceed down the staircase behind the door?" << std::endl;
                std::cout << "1: Descend the staircase [-5 minutes]" << std::endl;
                std::cout << "2: Return to the Lair of the Sphinx [-5 minutes]" << std::endl;
                int playerChoice = getInt(1, 2);

                if (playerChoice == 0) {
                    //Space* tempSpace = templeQueue->getFront()->getNorth();
                    //templeQueue->removeBack();
                    //templeQueue->addFront(tempSpace);
                    playerCharacter->setSpace(playerCharacter->getSpace()->getNorth());
                    std::cout << "You make your way back towards the Lair of the Sphinx." << std::endl;
                    rounds = rounds - 5;
                }
                else if (playerChoice == 1) {
                    //Space* tempSpace = templeQueue->removeFront();
                    //templeQueue->addBack(tempSpace);
                    playerCharacter->setSpace(playerCharacter->getSpace()->getSouth());
                    std::cout << "You descend the staircase, making your way deeper into the temple." << std::endl;
                    rounds = rounds - 5;
                    won = true;
                }
            }
            else if (sealSuccess == -1) {
                std::cout << std::endl;
                std::cout << "What next?" << std::endl;
                std::cout << "1: Sit down and cry [-60 minutes]" << std::endl;
                std::cout << "2: Return to the Lair of the Sphinx [-5 minutes]" << std::endl;
                int playerChoice = getInt(1, 2);

                if (playerChoice == 2) {
                    //Space* tempSpace = templeQueue->getFront()->getNorth();
                    //templeQueue->removeBack();
                    //templeQueue->addFront(tempSpace);
                    playerCharacter->setSpace(playerCharacter->getSpace()->getNorth());
                    std::cout << "You make your way back towards the Lair of the Sphinx." << std::endl;
                    rounds = rounds - 5;
                }
                else if (playerChoice == 1) {
                    //Space* tempSpace = templeQueue->removeFront();
                    //templeQueue->addBack(tempSpace);
                    std::cout << "You collapse to the floor in a blubbering mess." << std::endl;
                    rounds = rounds - 60;
                }
            }
        }
    }

    if (rounds <= 0) {
        std::cout << "The bomb exploded while you were inside the blast zone! What a way to go..." << std::endl;
    }
    else if (won == true) {
        std::cout << "You won! Congratulations!" << std::endl;
    }

    if (playerCharacter->getInventory()[0] != NULL) {
        InventoryObject** currentInventory = playerCharacter->getInventory();
        delete currentInventory[0];
    }

    if (playerCharacter->getInventory()[1] != NULL) {
        InventoryObject** currentInventory = playerCharacter->getInventory();
        delete currentInventory[1];
    }

    delete playerCharacter;
    delete jungleFloor;
    delete templeFoyer;
    delete sphinxLair;
    //delete templeQueue;
}

/*********************************************************************
** Int input validator
** Paramaters are: ints describing inclusive range
** What it does: accepts integers in a range
** Returns: the selected integer, if it is in range
*********************************************************************/
int Rumble::getInt(int min, int max)
{
    //Conditions for continuing loop and checking input
    std::string intArray = "1234567890-";
    int inputSelection;
    std::string userInput;
    bool keepLooping = true;

    while (keepLooping == true) {
        //CITATION: Herle, johnathan, Johnston, Italia, Works Cited
        std::cout << "Enter an integer between " << min << " and " << max << ":" << std::endl;
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