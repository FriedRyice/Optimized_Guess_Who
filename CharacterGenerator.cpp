#include "CharacterGenerator.h"
#include "Names.h"
#include <algorithm>
#include <random>

using namespace std;

/*****************************************************************************
 * CharacterGenerator.cpp
 * ----------------------
 * Implements the CharacterGenerator class. Responsible for generating
 * unique characters with randomized attributes and gender‑appropriate names.
 ****************************************************************************/

 // Constructor: initialize RNG and distributions
CharacterGenerator::CharacterGenerator()
    : rng(random_device{}()),
    ageDist(18, 60),
    hairDist(0, 4),       // HairColor enum range
    eyeDist(0, 5),        // EyeColor enum range
    accessoryDist(1, 5),  // Accessories enum range
    genderDist(1, 2)      // Gender enum range
{}

// Helper: check uniqueness against existing cast
bool CharacterGenerator::isUnique(const Character& newChar) {
    for (const auto& c : cast) {
        if (c == newChar) return false;
    }
    return true;
}

// Helper: build one character with randomized attributes
Character CharacterGenerator::generateCharacter() {
    int age = ageDist(rng);
    auto hair = static_cast<CharacterAttributes::HairColor>(hairDist(rng));
    auto eyes = static_cast<CharacterAttributes::EyeColor>(eyeDist(rng));
    auto accessory = static_cast<CharacterAttributes::Accessories>(accessoryDist(rng));
    auto gender = static_cast<CharacterAttributes::Gender>(genderDist(rng));

    string chosenName;

    if (gender == CharacterAttributes::Gender::Male) {
        uniform_int_distribution<int> nameDist(0, static_cast<int>(CharacterNames::maleNames.size()) - 1);
        chosenName = CharacterNames::maleNames[nameDist(rng)];
        CharacterNames::maleNames.erase(
            remove(CharacterNames::maleNames.begin(), CharacterNames::maleNames.end(), chosenName),
            CharacterNames::maleNames.end()
        );
    }
    else {
        uniform_int_distribution<int> nameDist(0, static_cast<int>(CharacterNames::femaleNames.size()) - 1);
        chosenName = CharacterNames::femaleNames[nameDist(rng)];
        CharacterNames::femaleNames.erase(
            remove(CharacterNames::femaleNames.begin(), CharacterNames::femaleNames.end(), chosenName),
            CharacterNames::femaleNames.end()
        );
    }

    // Construct and return the new Character
    return Character(chosenName, age, hair, eyes, accessory, gender);
}

// Public: generate 'count' unique characters
void CharacterGenerator::generate(int count) {
    while (static_cast<int>(cast.size()) < count) {
        Character newChar = generateCharacter();
        if (isUnique(newChar)) {
            cast.push_back(newChar);
        }
    }
}
