#pragma once
#include <list>
#include <random>
#include "Character.h"
#include "Names.h"
using namespace std;

/***************************************************************************
 * CharacterGenerator.h
 * --------------------
 * Declares the CharacterGenerator class, responsible for producing a cast
 * of unique characters for the Guess Who–style game.
 *
 * Each character is assigned:
 *   - A unique, gender‑appropriate name (from Names.h)
 *   - A random age (currently cosmetic, not used in guessing logic)
 *   - Random attributes (hair color, eye color, accessory, gender)
 *
 * Uniqueness is enforced by comparing attributes and removing names from
 * the pool once they are assigned.
 *************************************************************************/

class CharacterGenerator {
private:
    // Internal storage for the generated cast
    list<Character> cast;

    // Random number generator and distributions
    mt19937 rng;
    uniform_int_distribution<int> ageDist;
    uniform_int_distribution<int> hairDist;
    uniform_int_distribution<int> eyeDist;
    uniform_int_distribution<int> accessoryDist;
    uniform_int_distribution<int> genderDist;

    // Helper function: builds one character with randomized attributes
    Character generateCharacter();

    // Helper function: checks if a new character is unique compared to existing ones
    bool isUnique(const Character& newChar);

public:
    // Constructor initializes RNG and distributions
    CharacterGenerator();

    // Generates 'count' number of unique characters
    void generate(int count);

    // Provides read-only access to the generated cast
    const list<Character>& getCast() const { return cast; }
};
