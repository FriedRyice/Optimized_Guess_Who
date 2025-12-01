#include <iostream>
#include <iomanip>
#include <list>
#include "Character.h"
#include "CharacterGenerator.h"
#include "BubbleSort.h"
#include "InsertionSort.h"


// Number of characters to generate
const int GEN_AMOUNT = 24;

// Quick and dirty input validation function to drastically cut down on else-if chains
bool validateInput(std::string arr[], std::string input, int length) {
    for(int i = 0; i < length; i++) {
        if(input == arr[i])
            return true;
    }
    std::cout << "That input is invalid.\n";
    return false;
}



// Prints the cast list in a nicely-formatted table
void printCast(std::list<Character> cast) {
    std::cout << left << setw(10) << "Name"
        << setw(10) << "Age"
        << setw(15) << "Hair"
        << setw(15) << "Eyes"
        << setw(20) << "Accessory"
        << setw(10) << "Gender" << endl;
    std::cout << string(80, '-') << endl;
    for(const auto& c : cast) {
        std::cout << c.toString() << endl;
    }
}

// The player must input their character's name to select them. Right now, loop until a valid input is given
Character playerSelect(std::list<Character> cast) {
    std::string input;
    while(true) {
        std::cout << "Please select a character by entering their name:\n";
        std::cout << "> ";
        std::getline(std::cin, input);
        std::list<Character>::iterator it = cast.begin();
        while(it != cast.end()) {
            Character c = *it;
            if(c.getName() == input)
                return c;
            it++;
        }
        if(it == cast.end())
            std::cout << "Could not find that character.\n";
    }
}

// The opponent will select a character using a random number generator
Character oppSelect(std::list<Character> cast) {
    int numIter = rand() % GEN_AMOUNT;
    std::list<Character>::iterator it = cast.begin();
    for(int i = 0; i < numIter; i++) {
        it++;
    }
    Character result = *it;
    return result;
}

// The main game loop. Returns either a 1 (for player win) or a 2 (for opponent win)
int gameLoop(std::list<Character> playerCast, std::list<Character> oppCast, Character playerChar, Character oppChar) {
    std::string attrGuess;
    int typeGuess;
    std::string attributeArr[] = {"Hair Color", "Eye Color", "Accessories", "Gender"};
    while(true) {
        std::cout << "Your turn!\n";
        std::cout << "Which attribute do you want to guess for?\n";
        for(int i = 0; i < 4; i++) {
            std::cout << " - " << attributeArr[i] << '\n';
        }
        std::cout << "> ";
        std::getline(std::cin, attrGuess);
        if(validateInput(attributeArr, attrGuess, 4)) {
            int enumStart;
            int enumEnd;
            std::cout << "What type of attribute is it? Enter the number\n";
            if(attrGuess == "Hair Color") {
                enumStart = 0;
                enumEnd = 4;
                for(int i = enumStart; i <= enumEnd; i++) {
                    std::cout << i << " - " << CharacterAttributes::hairToString((CharacterAttributes::HairColor)i) << '\n';
                }
                std::cout << "> ";
                std::cin >> typeGuess;
                std::cin.ignore(65536, '\n');
                CharacterAttributes::HairColor hairGuess = (CharacterAttributes::HairColor)typeGuess;
                std::cout << "You: \"Does your character have " << CharacterAttributes::hairToString(hairGuess) << " hair?\"\n";
                if(oppChar.getHairColor() == hairGuess) {
                    std::cout << "Opponent: \"Yes.\"\n";
                    std::list<Character>::iterator it = oppCast.begin();
                    while(it != oppCast.end()) {
                        Character c = *it;
                        it++;
                        if(c.getHairColor() != hairGuess) {
                            oppCast.remove(c);
                        }
                    }
                } else {
                    std::cout << "Opponent: \"No.\"\n";
                    std::list<Character>::iterator it = oppCast.begin();
                    while(it != oppCast.end()) {
                        Character c = *it;
                        it++;
                        if(c.getHairColor() == hairGuess) {
                            oppCast.remove(c);
                        }
                    }
                }
            } else if(attrGuess == "Eye Color") {
                enumStart = 0;
                enumEnd = 5;
                for(int i = enumStart; i <= enumEnd; i++) {
                    std::cout << i << " - " << CharacterAttributes::eyeToString((CharacterAttributes::EyeColor)i) << '\n';
                }
                std::cout << "> ";
                std::cin >> typeGuess;
                std::cin.ignore(65536, '\n');
                CharacterAttributes::EyeColor eyeGuess = (CharacterAttributes::EyeColor)typeGuess;
                std::cout << "You: \"Does your character have " << CharacterAttributes::eyeToString(eyeGuess) << " eyes?\"\n";
                if(oppChar.getEyeColor() == eyeGuess) {
                    std::cout << "Opponent: \"Yes.\"\n";
                    std::list<Character>::iterator it = oppCast.begin();
                    while(it != oppCast.end()) {
                        Character c = *it;
                        it++;
                        if(c.getEyeColor() != eyeGuess) {
                            oppCast.remove(c);
                        }
                    }
                } else {
                    std::cout << "Opponent: \"No.\"\n";
                    std::list<Character>::iterator it = oppCast.begin();
                    while(it != oppCast.end()) {
                        Character c = *it;
                        it++;
                        if(c.getEyeColor() == eyeGuess) {
                            oppCast.remove(c);
                        }
                    }
                }
            } else if(attrGuess == "Accessories") {
                enumStart = 1;
                enumEnd = 5;
                for(int i = enumStart; i <= enumEnd; i++) {
                    std::cout << i << " - " << CharacterAttributes::accessoriesToString((CharacterAttributes::Accessories)i) << '\n';
                }
                std::cout << "> ";
                std::cin >> typeGuess;
                std::cin.ignore(65536, '\n');
                CharacterAttributes::Accessories accGuess = (CharacterAttributes::Accessories)typeGuess;
                std::cout << "You: \"Does your character have " << CharacterAttributes::accessoriesToString(accGuess) << "?\"\n";
                if(oppChar.getAccessory() == accGuess) {
                    std::cout << "Opponent: \"Yes.\"\n";
                    std::list<Character>::iterator it = oppCast.begin();
                    while(it != oppCast.end()) {
                        Character c = *it;
                        it++;
                        if(c.getAccessory() != accGuess) {
                            oppCast.remove(c);
                        }
                    }
                } else {
                    std::cout << "Opponent: \"No.\"\n";
                    std::list<Character>::iterator it = oppCast.begin();
                    while(it != oppCast.end()) {
                        Character c = *it;
                        it++;
                        if(c.getAccessory() == accGuess) {
                            oppCast.remove(c);
                        }
                    }
                }
            } else if(attrGuess == "Gender") {
                enumStart = 1;
                enumEnd = 2;
                for(int i = enumStart; i <= enumEnd; i++) {
                    std::cout << i << " - " << CharacterAttributes::genderToString((CharacterAttributes::Gender)i) << '\n';
                }
                std::cout << "> ";
                std::cin >> typeGuess;
                std::cin.ignore(65536, '\n');
                CharacterAttributes::Gender genGuess = (CharacterAttributes::Gender)typeGuess;
                std::cout << "You: \"Is your character " << CharacterAttributes::genderToString(genGuess) << "?\"\n";
                if(oppChar.getGender() == genGuess) {
                    std::cout << "Opponent: \"Yes.\"\n";
                    std::list<Character>::iterator it = oppCast.begin();
                    while(it != oppCast.end()) {
                        Character c = *it;
                        it++;
                        if(c.getGender() != genGuess) {
                            oppCast.remove(c);
                        }
                    }
                } else {
                    std::cout << "Opponent: \"No.\"\n";
                    std::list<Character>::iterator it = oppCast.begin();
                    while(it != oppCast.end()) {
                        Character c = *it;
                        it++;
                        if(c.getGender() == genGuess) {
                            oppCast.remove(c);
                        }
                    }
                }
            }
        }
        std::cout << "Characters remaining:\n";
        printCast(oppCast);
        std::cout << '\n';
        if(oppCast.size() <= 1)
            return 1;
        std::cout << "Opponent's turn!\n";

        // Using a random guess to start with

        int oppAttrGuess = rand() % 4;
        int oppTypeGuess;

        // Asking yes or no would be redundant because you shouldn't lie to the AI

        switch(oppAttrGuess) {
        case 0:
            CharacterAttributes::HairColor oppHairGuess;
            oppTypeGuess = rand() % 5;
            oppHairGuess = (CharacterAttributes::HairColor)oppTypeGuess;
            std::cout << "Opponent: \"Does your character have " << CharacterAttributes::hairToString(oppHairGuess) << " hair?\"\n";
            if(playerChar.getHairColor() == oppHairGuess) {
                std::cout << "You: \"Yes.\"\n";
                std::list<Character>::iterator it = playerCast.begin();
                while(it != playerCast.end()) {
                    Character c = *it;
                    it++;
                    if(c.getHairColor() != oppHairGuess) {
                        playerCast.remove(c);
                    }
                }
            } else {
                std::cout << "You: \"No.\"\n";
                std::list<Character>::iterator it = playerCast.begin();
                while(it != playerCast.end()) {
                    Character c = *it;
                    it++;
                    if(c.getHairColor() != oppHairGuess) {
                        playerCast.remove(c);
                    }
                }
            }
            break;
        case 1:
            CharacterAttributes::EyeColor oppEyeGuess;
            oppTypeGuess = rand() % 6;
            oppEyeGuess = (CharacterAttributes::EyeColor)oppTypeGuess;
            std::cout << "Opponent: \"Does your character have " << CharacterAttributes::eyeToString(oppEyeGuess) << " eyes?\"\n";
            if(playerChar.getEyeColor() == oppEyeGuess) {
                std::cout << "You: \"Yes.\"\n";
                std::list<Character>::iterator it = playerCast.begin();
                while(it != playerCast.end()) {
                    Character c = *it;
                    it++;
                    if(c.getEyeColor() != oppEyeGuess) {
                        playerCast.remove(c);
                    }
                }
            } else {
                std::cout << "You: \"No.\"\n";
                std::list<Character>::iterator it = playerCast.begin();
                while(it != playerCast.end()) {
                    Character c = *it;
                    it++;
                    if(c.getEyeColor() != oppEyeGuess) {
                        playerCast.remove(c);
                    }
                }
            }
            break;
        case 2:
            CharacterAttributes::Accessories oppAccGuess;
            oppTypeGuess = rand() % 4 + 1;
            oppAccGuess = (CharacterAttributes::Accessories)oppTypeGuess;
            std::cout << "Opponent: \"Does your character have " << CharacterAttributes::accessoriesToString(oppAccGuess) << "?\"\n";
            if(playerChar.getAccessory() == oppAccGuess) {
                std::cout << "You: \"Yes.\"\n";
                std::list<Character>::iterator it = playerCast.begin();
                while(it != playerCast.end()) {
                    Character c = *it;
                    it++;
                    if(c.getAccessory() != oppAccGuess) {
                        playerCast.remove(c);
                    }
                }
            } else {
                std::cout << "You: \"No.\"\n";
                std::list<Character>::iterator it = playerCast.begin();
                while(it != playerCast.end()) {
                    Character c = *it;
                    it++;
                    if(c.getAccessory() != oppAccGuess) {
                        playerCast.remove(c);
                    }
                }
            }
            break;
        case 3:
            CharacterAttributes::Gender oppGenGuess;
            oppTypeGuess = rand() % 2 + 1;
            oppGenGuess = (CharacterAttributes::Gender)oppTypeGuess;
            std::cout << "Opponent: \"Is your character " << CharacterAttributes::genderToString(oppGenGuess) << "?\"\n";
            if(playerChar.getGender() == oppGenGuess) {
                std::cout << "You: \"Yes.\"\n";
                std::list<Character>::iterator it = playerCast.begin();
                while(it != playerCast.end()) {
                    Character c = *it;
                    it++;
                    if(c.getGender() != oppGenGuess) {
                        playerCast.remove(c);
                    }
                }
            } else {
                std::cout << "You: \"No.\"\n";
                std::list<Character>::iterator it = playerCast.begin();
                while(it != playerCast.end()) {
                    Character c = *it;
                    it++;
                    if(c.getGender() != oppGenGuess) {
                        playerCast.remove(c);
                    }
                }
            }
            break;
        default:
            break;
        }
        std::cout << '\n';
        if(playerCast.size() <= 1)
            return 2;
    }
}

int main() {
    std::string arr1[] = {"1", "2", "3", "q"};
    

    std::cout << "Welcome to Optimized Guess Who!\n";
    std::cout << "By David Patronas, Rylan Willis, and Alex Rinder\n\n";
    std::string input;
    CharacterGenerator generator;
    generator.generate(GEN_AMOUNT);
        std::list<Character> playerCast = generator.getCast();

    srand(time(NULL));
    do {
        std::cout << "Select the algorithm you want to play against, or type 'q' to quit:\n";
        std::cout << "1 - Bubble Sort\n";
        std::cout << "2 - Sort 2 NOT IMPLEMENTED YET\n";
        std::cout << "3 - Sort 3 NOT IMPLEMENTED YET\n";
        std::cout << "> ";
        std::getline(std::cin, input);
        if(validateInput(arr1, input, 4)) {
            if(input == "q")
                break;
            std::cout << "Characters:\n";
            printCast(playerCast);
            Character playerChar = playerSelect(playerCast);
            std::cout << "You have selected " << playerChar.getName() << ".\n";
            std::cout << "Your opponent will now select a character...\n";
            list<Character> oppCast = playerCast;
            Character oppChar = oppSelect(oppCast);
            // Just sorting by hair color for now.
            if(input == "1")
                bubbleSort(playerCast, [](const Character& a, const Character& b) {return a.getHairColor() > b.getHairColor(); }, "hair");
            else if(input == "2")
                std::cout << "We haven't done this one yet...\n";
            else if(input == "3")
                std::cout << "We haven't done this one yet...\n";
            std::cout << "Start!\n";
            std::cout << '\n';
            int game = gameLoop(playerCast, oppCast, playerChar, oppChar);
            if(game == 1)
                std::cout << "You win!\n";
            else
                std::cout << "You lose!\n";
            std::cout << "The opponent's character was " << oppChar.getName() << ".\n";
        }
    } while(input != "q");

    std::cout << "Thanks for playing!\n";

    // If only one character remains, make a guess

    /*if(cast.size() == 1) {
        cout << "\nIs your character " << cast.front().getName() << "?" << endl;
    }*/

    return 0;

}
