/*********************************************************************
** Program Name: The Temple of Primal Evil
** Author: Andrew Helmsworth
** Date: 2019/12/08
** Description: Player Character object traverses linked list of Space objects,
** Description: ...& interacts with Spaces and InventoryObjects in a timed scenario.
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
#include "Amulet.hpp"
#include "FocusingLens.hpp"
#include "LairOfTheSphinx.hpp"
#include "MightySeal.hpp"
#include "TombOfTheGravediggers.hpp"
#include "SubterraneanAtrium.hpp"
#include "Rest.hpp"
#include "Corridor.hpp"
#include "Chamber.hpp"
#include "Outside.hpp"

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

void Rumble::playJungleFloor(Character* playerCharacter, Space* jungleFloor, int& rounds, int& passingArgument, bool& won, bool& dead, Space* rest)
{
    //playerCharacter->setSpace(jungleFloor);
    jungleFloor->setCharacter(playerCharacter);
    std::cout << std::endl;
    std::cout << "||||LEVEL 0||||" << std::endl;
    std::cout << "You are now on the Jungle Floor." << std::endl;

    if (rest->getSolved() == true) {
        won = true;
    }
    else if (rest->getSolved() == false) {
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
            jungleFloor->setCharacter(NULL);
        }
    }
}

void Rumble::playFoyer(Character* playerCharacter, Space* templeFoyer, int& rounds, int& passingArgument, bool& won, bool& dead, Space* mightySeal, Space* atrium)
{
    templeFoyer->setCharacter(playerCharacter);
    std::cout << std::endl;
    std::cout << "||||LEVEL -1||||" << std::endl;
    std::cout << "You are now in the Temple Foyer." << std::endl;
    std::cout << rounds << " minutes remain until automatic detonation." << std::endl;
    std::cout << std::endl;
    std::cout << "A pile of scattered bones quivers and shakes." << std::endl;
    std::cout << "With a shudder, a spooky skellington springs to life! Slay him or die!" << std::endl;
    std::cout << std::endl;
    std::cout << "What will you do?" << std::endl;
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
            std::cout << std::endl;
            std::cout << "Will you pick up the key?" << std::endl;
            std::cout << "1: Pick up the key." << std::endl;
            std::cout << "2: Leave it where it is." << std::endl;
            int keyChoice = getInt(1, 2);

            if (keyChoice == 2) {
                std::cout << std::endl;
                std::cout << "Seems like a bad idea! But okay. You leave the key where it is. It dissapates into mist as you walk away." << std::endl;
                std::cout << std::endl;
            }
            else if (keyChoice == 1) {
                std::cout << std::endl;
                std::cout << "Wise move. You pick up the key." << std::endl;
                std::cout << std::endl;
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
                    std::cout << "3: Put the key back (you'll ultimately decide to do this anyway if you own an important item)." << std::endl;
                    int deleteChoice = getInt(1, 3);
                    if (mightySeal->getLooted() == true || atrium->getLooted() == true) {
                        deleteChoice = 3;
                    }
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
                        std::cout << "You put the key back. It dissapates into mist as you walk away." << std::endl;
                    }
                }

            }
            std::cout << std::endl;
            std::cout << "Descend the ladder to the level below?" << std::endl;
            std::cout << "1: Descend [-5 minutes]" << std::endl;
            std::cout << "2: Return to the surface [-5 minutes]" << std::endl;
            int playerChoice = getInt(1, 2);

            if (playerChoice == 2) {
                //Space* tempSpace = templeQueue->getFront()->getNorth();
                //templeQueue->removeBack();
                //templeQueue->addFront(tempSpace);
                playerCharacter->setSpace(playerCharacter->getSpace()->getNorth());
                std::cout << "You return through the door, making your way back to the surface." << std::endl;
                templeFoyer->setCharacter(NULL);
                rounds = rounds - 5;
            }
            else if (playerChoice == 1) {
                //Space* tempSpace = templeQueue->removeFront();
                //templeQueue->addBack(tempSpace);
                playerCharacter->setSpace(playerCharacter->getSpace()->getSouth());
                std::cout << "You descend the ladder, making your way deeper into the temple." << std::endl;
                templeFoyer->setCharacter(NULL);
                rounds = rounds - 5;
            }
        }
    }
}

void Rumble::playSphinx(Character* playerCharacter, Space* sphinxLair, int& rounds, int& passingArgument, bool& won, bool& dead)
{
    std::cout << std::endl;
    std::cout << "||||LEVEL -2||||" << std::endl;
    std::cout << "You are now in the Lair of the Sphinx." << std::endl;
    std::cout << rounds << " minutes remain until automatic detonation." << std::endl;
    std::cout << std::endl;
    std::cout << "An imperious statue guards the way." << std::endl;
    int playerGuesses = 0;
    sphinxLair->setCharacter(playerCharacter);
    sphinxLair->draw(playerCharacter, playerGuesses);
    rounds = rounds - playerGuesses;

    if (rounds > 0) {
        std::cout << "The Sphinx decided to let you pass. Will you return up the ladder to the foyer, or descend the steps beneath its feet?" << std::endl;
        std::cout << "1: Descend [-5 minutes]" << std::endl;
        std::cout << "2: Return up the ladder [-5 minutes]" << std::endl;
        int playerChoice = getInt(1, 2);

        if (playerChoice == 2) {
            //Space* tempSpace = templeQueue->getFront()->getNorth();
            //templeQueue->removeBack();
            //templeQueue->addFront(tempSpace);
            playerCharacter->setSpace(playerCharacter->getSpace()->getNorth());
            std::cout << "You return up the ladder, making your way back to the foyer." << std::endl;
            sphinxLair->setCharacter(NULL);
            rounds = rounds - 5;
        }
        else if (playerChoice == 1) {
            //Space* tempSpace = templeQueue->removeFront();
            //templeQueue->addBack(tempSpace);
            playerCharacter->setSpace(playerCharacter->getSpace()->getSouth());
            std::cout << "You descend the steps, making your way deeper into the temple." << std::endl;
            sphinxLair->setCharacter(NULL);
            rounds = rounds - 5;
        }
    }
}

void Rumble::playMightySeal(Character* playerCharacter, Space* mightySeal, int& rounds, int& passingArgument, bool& won, bool& dead)
{
    std::cout << std::endl;
    std::cout << "||||LEVEL -3||||" << std::endl;
    std::cout << "You are now in the Mighty Seal." << std::endl;
    std::cout << rounds << " minutes remain until automatic detonation." << std::endl;
    std::cout << std::endl;
    mightySeal->setCharacter(playerCharacter);
    int sealSuccess = mightySeal->draw(playerCharacter, passingArgument);

    if (sealSuccess == 0) {
        std::cout << "Proceed down the staircase behind the door?" << std::endl;
        std::cout << "1: Descend the staircase [-5 minutes]" << std::endl;
        std::cout << "2: Return to the Lair of the Sphinx [-5 minutes]" << std::endl;
        int playerChoice = getInt(1, 2);

        if (playerChoice == 2) {
            //Space* tempSpace = templeQueue->getFront()->getNorth();
            //templeQueue->removeBack();
            //templeQueue->addFront(tempSpace);
            playerCharacter->setSpace(playerCharacter->getSpace()->getNorth());
            std::cout << "You make your way back towards the Lair of the Sphinx." << std::endl;
            mightySeal->setCharacter(NULL);
            rounds = rounds - 5;
        }
        else if (playerChoice == 1) {
            //Space* tempSpace = templeQueue->removeFront();
            //templeQueue->addBack(tempSpace);
            playerCharacter->setSpace(playerCharacter->getSpace()->getSouth());
            std::cout << "You descend the staircase, making your way deeper into the temple." << std::endl;
            mightySeal->setCharacter(NULL);
            rounds = rounds - 5;
        }
    }
    else if (sealSuccess == -1) {
        std::cout << std::endl;
        std::cout << "What next?" << std::endl;
        std::cout << "1: Sit down and cry [-500 minutes]" << std::endl;
        std::cout << "2: Return to the Lair of the Sphinx [-5 minutes]" << std::endl;
        int playerChoice = getInt(1, 2);

        if (playerChoice == 2) {
            //Space* tempSpace = templeQueue->getFront()->getNorth();
            //templeQueue->removeBack();
            //templeQueue->addFront(tempSpace);
            playerCharacter->setSpace(playerCharacter->getSpace()->getNorth());
            std::cout << "You make your way back towards the Lair of the Sphinx." << std::endl;
            mightySeal->setCharacter(NULL);
            rounds = rounds - 5;
        }
        else if (playerChoice == 1) {
            //Space* tempSpace = templeQueue->removeFront();
            //templeQueue->addBack(tempSpace);
            std::cout << "You collapse to the floor in a blubbering mess." << std::endl;
            rounds = rounds - 500;
        }
    }
}

void Rumble::playTomb(Character* playerCharacter, Space* tomb, int& rounds, int& passingArgument, bool& won, bool& dead)
{
    std::cout << std::endl;
    std::cout << "||||LEVEL -4||||" << std::endl;
    std::cout << "You are now in the Tomb of the Gravediggers." << std::endl;
    std::cout << rounds << " minutes remain until automatic detonation." << std::endl;
    std::cout << std::endl;
    tomb->setCharacter(playerCharacter);
    tomb->draw(playerCharacter, passingArgument);

    std::cout << std::endl;
    std::cout << "Take the trapdoor down to the next level?" << std::endl;
    std::cout << "1: Descend through the trapdoor [-5 minutes]" << std::endl;
    std::cout << "2: Return up the staircase to the Mighty Seal [-5 minutes]" << std::endl;
    int playerChoice = getInt(1, 2);

    if (playerChoice == 2) {
        //Space* tempSpace = templeQueue->getFront()->getNorth();
        //templeQueue->removeBack();
        //templeQueue->addFront(tempSpace);
        playerCharacter->setSpace(playerCharacter->getSpace()->getNorth());
        std::cout << "You make your way back upstairs, towards the Mighty Seal." << std::endl;
        rounds = rounds - 5;
        tomb->setCharacter(NULL);
    }
    else if (playerChoice == 1) {
        //Space* tempSpace = templeQueue->removeFront();
        //templeQueue->addBack(tempSpace);
        playerCharacter->setSpace(playerCharacter->getSpace()->getSouth());
        std::cout << "You descend through the trapdoor, making your way deeper into the temple." << std::endl;
        rounds = rounds - 5;
        tomb->setCharacter(NULL);
    }

}

void Rumble::playAtrium(Character* playerCharacter, Space* atrium, int& rounds, int& passingArgument, bool& won, bool& dead)
{
    std::cout << std::endl;
    std::cout << "||||LEVEL -5||||" << std::endl;
    std::cout << "You are now in the Subterranean Atrium." << std::endl;
    std::cout << rounds << " minutes remain until automatic detonation." << std::endl;
    std::cout << std::endl;
    atrium->setCharacter(playerCharacter);
    int refractionGame = atrium->draw(playerCharacter, passingArgument);
    if (refractionGame == -1) {
        rounds = rounds - 500;
    }
    else {
        std::cout << "Will you descend to the den of the sleeping god, or retrace your steps?" << std::endl;
        std::cout << "1: Descend the walkway towards the depths [-5 minutes]" << std::endl;
        std::cout << "2: Return through the trapdoor to the tomb [-5 minutes]" << std::endl;
        int progressChoice = getInt(1, 2);
        if (progressChoice == 2) {
            //Space* tempSpace = templeQueue->getFront()->getNorth();
            //templeQueue->removeBack();
            //templeQueue->addFront(tempSpace);
            playerCharacter->setSpace(playerCharacter->getSpace()->getNorth());
            std::cout << "You make your way back up towards the Tomb." << std::endl;
            atrium->setCharacter(NULL);
            rounds = rounds - 5;
        }
        else if (progressChoice == 1) {
            //Space* tempSpace = templeQueue->removeFront();
            //templeQueue->addBack(tempSpace);
            playerCharacter->setSpace(playerCharacter->getSpace()->getSouth());
            std::cout << "You descend to the final level of the temple." << std::endl;
            atrium->setCharacter(NULL);
            rounds = rounds - 5;
        }
    }
}

void Rumble::playRest(Character* playerCharacter, Space* rest, int& rounds, int& passingArgument, bool& won, bool& dead)
{
    std::cout << std::endl;
    std::cout << "||||LEVEL -6||||" << std::endl;
    std::cout << "You have arrived at the Nameless One's Rest." << std::endl;
    std::cout << rounds << " minutes remain until automatic detonation." << std::endl;
    std::cout << std::endl;
    rest->setCharacter(playerCharacter);
    rest->draw(playerCharacter, passingArgument);

    std::cout << "Will you return to the atrium?" << std::endl;
    std::cout << "1: Head back to the atrium [-5 minutes]" << std::endl;
    std::cout << "2: Give up and stay here [-500 minutes]" << std::endl;
    int progressChoice = getInt(1, 2);
    if (progressChoice == 2) {
        rounds = rounds - 500;
    }
    else if (progressChoice == 1) {
        //Space* tempSpace = templeQueue->removeFront();
        //templeQueue->addBack(tempSpace);
        playerCharacter->setSpace(playerCharacter->getSpace()->getNorth());
        std::cout << "You make your way back to the atrium." << std::endl;
        rest->setCharacter(NULL);
        rounds = rounds - 5;
    }

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
    int rounds = 120;

    bool won = false;
    bool dead = false;

    Character* playerCharacter = new HarryPotter;
    //Queue* templeQueue = new Queue;
    Space* jungleFloor = new JungleFloor;
    Space* templeFoyer = new TempleFoyer;
    Space* sphinxLair = new LairOfTheSphinx;
    Space* mightySeal = new MightySeal;
    Space* tomb = new TombOfTheGraveDiggers;
    Space* atrium = new SubterraneanAtrium;
    Space* rest = new Rest;

    jungleFloor->setSouth(templeFoyer);
    templeFoyer->setNorth(jungleFloor);
    templeFoyer->setSouth(sphinxLair);
    sphinxLair->setNorth(templeFoyer);
    sphinxLair->setSouth(mightySeal);
    mightySeal->setNorth(sphinxLair);
    mightySeal->setSouth(tomb);
    tomb->setNorth(mightySeal);
    tomb->setSouth(atrium);
    atrium->setNorth(tomb);
    atrium->setSouth(rest);
    rest->setNorth(atrium);

    jungleFloor->setCharacter(playerCharacter);
    playerCharacter->setSpace(jungleFloor);

    //templeQueue->addBack(jungleFloor);
    //templeQueue->addBack(templeFoyer);
    //templeQueue->addBack(sphinxLair);

    int passingArgument = 0;

    //Loop while both teams have characters
    while (won == false && dead == false && rounds > 0) {
        if (playerCharacter->getSpace()->getName() == "Jungle Floor") {
            playJungleFloor(playerCharacter, jungleFloor, rounds, passingArgument, won, dead, rest);
        }
        else if (playerCharacter->getSpace()->getName() == "Temple Foyer") {
            playFoyer(playerCharacter, templeFoyer, rounds, passingArgument, won, dead, mightySeal, atrium);
        }
        else if (playerCharacter->getSpace()->getName() == "Lair of the Sphinx") {
            playSphinx(playerCharacter, sphinxLair, rounds, passingArgument, won, dead);
        }
        else if (playerCharacter->getSpace()->getName() == "The Mighty Seal") {
            playMightySeal(playerCharacter, mightySeal, rounds, passingArgument, won, dead);
        }
        else if (playerCharacter->getSpace()->getName() == "Tomb of the Gravediggers"){
            playTomb(playerCharacter, tomb, rounds, passingArgument, won, dead);
        }
        else if (playerCharacter->getSpace()->getName() == "Subterranean Atrium") {
            playAtrium(playerCharacter, atrium, rounds, passingArgument, won, dead);
        }
        else if (playerCharacter->getSpace()->getName() == "Nameless One's Rest") {
            playRest(playerCharacter, rest, rounds, passingArgument, won, dead);
        }
    }

    if (rounds <= 0) {
        std::cout << "The bomb exploded while you were inside the blast zone! What a way to go..." << std::endl;
    }
    else if (won == true) {
        std::cout << "The temple explodes in a blinding fireball as you walk off into the distance." << std::endl;
        std::cout << "But you don't look fazed. Everyone knows cool people don't look at explosions." << std::endl;
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
    delete mightySeal;
    delete tomb;
    delete atrium;
    delete rest;
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