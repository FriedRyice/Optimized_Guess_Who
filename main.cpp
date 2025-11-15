#include <iostream>
#include <iomanip>
#include "CharacterGenerator.h"

using namespace std;

int main() {

	// You can delete this, I was just looking at the CharacterGenerator in action (Rylan)
    int castSize;
    cout << "How many characters should be in the cast? ";
    cin >> castSize;

    CharacterGenerator generator;
    generator.generate(castSize);

    // Print header row
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
