#include "TombOfTheGravediggers.hpp"

TombOfTheGraveDiggers::TombOfTheGraveDiggers()
{
    name = "Tomb of the Gravediggers";
}

TombOfTheGraveDiggers::~TombOfTheGraveDiggers()
{
}

int TombOfTheGraveDiggers::draw(Character* incCharacter, int& passingArg)
{
    std::cout << "Before you stands an edifice, inscribed with the names of the lost souls who died building this foul place." << std::endl;
    std::cout << std::endl;
    std::cout << "The whispers of the damned seem to have something important to tell you." << std::endl;

    std::cout << "1: Listen to the spirits." << std::endl;
    std::cout << "2: Ignore them." << std::endl;

    int playerChoice = getInt(1, 2);

    if (playerChoice == 2) {
        std::cout << "You close your ears to the spirits, whilst they curse the day you were born." << std::endl;
    }
    else if (playerChoice == 1) {
        std::cout << "\"3! 1! then 2!\" shout the spirits." << std::endl;
        std::cout << "Odd message from the afterlife, but seems important. You should probably remember this sequence." << std::endl;
    }

	return 0;
}

/*********************************************************************
** Int input validator
** Paramaters are: ints describing inclusive range
** What it does: accepts integers in a range
** Returns: the selected integer, if it is in range
*********************************************************************/
int TombOfTheGraveDiggers::getInt(int min, int max)
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