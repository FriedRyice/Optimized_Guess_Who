#include <iostream>
#include <iomanip>
#include <list>
#include "Character.h"
#include "CharacterGenerator.h"
#include "BubbleSort.h"

using namespace std;

// Example main to showcase character generation, sorting, and elimination.

int main() {
    // Generate the cast (24 characters for example)
    CharacterGenerator generator;
    generator.generate(24);                  // create 24 characters
    list<Character> cast = generator.getCast(); // retrieve the list

    // Sort the cast by hair color using Bubble Sort
    bubbleSort(cast,
        [](const Character& a, const Character& b) {
            return a.getHairColor() > b.getHairColor(); // compare by enum
        },
        "hair");

    // Ask a question about hair color
    string answer;
    cout << "Does your character have red hair? (yes/no): ";
    cin >> answer;

    // Eliminate characters based on the answer
    if (answer == "yes") {
        cast.remove_if([](const Character& c) {
            return c.getHairColor() != CharacterAttributes::HairColor::Red;
            });
    }
    else {
        cast.remove_if([](const Character& c) {
            return c.getHairColor() == CharacterAttributes::HairColor::Red;
            });
    }

    // Show remaining characters with header
    cout << "\nRemaining characters after elimination:\n";
    cout << left << setw(10) << "Name"
        << setw(10) << "Age"
        << setw(15) << "Hair"
        << setw(15) << "Eyes"
        << setw(20) << "Accessory"
        << setw(10) << "Gender" << endl;
    cout << string(70, '-') << endl;

    for (const auto& c : cast) {
        cout << c.toString() << endl; // nicely formatted row
    }

    // If only one character remains, make a guess
    if (cast.size() == 1) {
        cout << "\nIs your character " << cast.front().getName() << "?" << endl;
    }

    return 0;
}
