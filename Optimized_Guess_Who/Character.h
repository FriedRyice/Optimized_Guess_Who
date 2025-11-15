#pragma once
#include <string>
#include <vector>
#include "CharacterAttributes.h"
using namespace std;

/***************************************************************************************************
* Character represents a single cast member in the game.
* It stores private data such as name, age, and attributes (hair, eyes, accessory, gender).
* Public methods include a constructor, getters, comparison operator, and a toString() for display.
***************************************************************************************************/

class Character
{
private:
	string name;
	int age; // NOTE: currently cosmetic doesn't affect guessing.
	CharacterAttributes::HairColor hair;
	CharacterAttributes::EyeColor eyes;
	CharacterAttributes::Accessories accessory;
	CharacterAttributes::Gender gender;

public:
	// Constructor
	Character(string n, int a,
		CharacterAttributes::HairColor h,
		CharacterAttributes::EyeColor e,
		CharacterAttributes::Accessories acc,
		CharacterAttributes::Gender g);

	// Getters
	string getName() const;
	int getAge() const;
	CharacterAttributes::HairColor getHairColor() const;
	CharacterAttributes::EyeColor getEyeColor() const;
	CharacterAttributes::Accessories getAccessory() const;
	CharacterAttributes::Gender getGender() const;

	// Checks if each character is unique
	bool operator==(const Character& other) const;

	// string representation
	string toString() const;
};

