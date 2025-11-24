#include <iostream>
#include <iomanip>
#include "CharacterGenerator.h"

using namespace std;

int main() {

    int castSize;
    CharacterGenerator generator;

    // Keep prompting until valid input
    while (true) {
        cout << "How many characters should be in the cast? (1-24): ";
        cin >> castSize;

        if (castSize >= 1 && castSize <= 24) {
            generator.generate(castSize);
            break; // valid input, exit loop
        }
        else {
            cout << "Invalid number. Please try again." << endl;
        }
    }

    // Print header row
    cout << "\n";
    cout << left << setw(10) << "Name"
        << setw(10) << "Age"
        << setw(15) << "Hair"
        << setw(15) << "Eyes"
        << setw(20) << "Accessory"
        << setw(10) << "Gender" << endl;

    cout << string(80, '-') << endl;

    // Print each character in the cast
    for (const auto& c : generator.getCast()) {
        cout << c.toString() << endl;
    }

    return 0;
}
