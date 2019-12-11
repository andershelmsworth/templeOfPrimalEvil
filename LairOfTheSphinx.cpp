/*********************************************************************
** Program Name: The Temple of Primal Evil
** Author: Andrew Helmsworth
** Date: 2019/12/08
** Description: Player Character object traverses linked list of Space objects,
** Description: ...& interacts with Spaces and InventoryObjects in a timed scenario.
** Sources: See works cited at end-of-program comment-block in main.cpp.
*********************************************************************/

//Inclusions
#include "LairOfTheSphinx.hpp"
#include "Die.hpp"

/*********************************************************************
** LairOfTheSphinx default constructor
** Paramaters are: none
** What it does: sets name, sets character to null
** Returns: No return data.
*********************************************************************/
LairOfTheSphinx::LairOfTheSphinx()
{
    name = "Lair of the Sphinx";
    character = NULL;
}

/*********************************************************************
** LairOfTheSphinx destructor
** Paramaters are: none
** What it does: destroys LairOfTheSphinx
** Returns: No return data.
*********************************************************************/
LairOfTheSphinx::~LairOfTheSphinx()
{
}

/*********************************************************************
** LairOfTheSphinx draw
** Paramaters are: none
** What it does: runs level interaction
** Returns: number of guesses reqd
*********************************************************************/
int LairOfTheSphinx::draw(Character* playerCharacter, int& incPassingArg)
{
	std::cout << "The Sphinx demands you answer its riddle!" << std::endl;
	std::cout << "\"WHAT NUMBER, FROM 1-20, AM I THINKING OF?\" it bellows." << std::endl;

    //Initialize and roll d20 of chosen number
    Die sphinxDie(20);
    int sphinxChoice = sphinxDie.roll(20);

    bool keepLooping = true;
    int guessCounter = 1;

    //Keep looping until player guesses
    while (keepLooping == true) {
        int playerGuess = getInt(1, 20);

        if (playerGuess < sphinxChoice) {
            //Was too low, repeating and incrementing guess
            std::cout << "\"TOO LOW. TRY AGAIN!\"" << std::endl;
            guessCounter++;
        }
        else if (playerGuess > sphinxChoice) {
            //Was too high, repeating and incrementing guess
            std::cout << "\"TOO HIGH. TRY AGAIN!\"" << std::endl;
            guessCounter++;
        }
        else if (playerGuess == sphinxChoice) {
            //Returning to Rumble since guessed
            std::cout << "\"VERY GOOD! YOU MAY PROCEED.\"" << std::endl;
            keepLooping = false;
        }
    }

    //List guesses taken
    std::cout << guessCounter << " minutes elapsed while guessing the answer." << std::endl;
    std::cout << std::endl;

    //Return guesses taken, and set passingArg
    incPassingArg = guessCounter;
	return guessCounter;
}


/*********************************************************************
** Int input validator
** Paramaters are: ints describing inclusive range
** What it does: accepts integers in a range
** Returns: the selected integer, if it is in range
*********************************************************************/
int LairOfTheSphinx::getInt(int min, int max)
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