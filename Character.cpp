#include "Character.h"
#include <sstream>
#include <iomanip>

/****************************************************************************
* Character.cpp implements the methods declared in Character.h.
* The constructor initializes a character with given attributes.
* Getters provide safe access to private data, operator== checks uniqueness,
* and toString() returns a human-readable description of the character.
****************************************************************************/

// Constructor 
Character::Character(string n, int a,
        CharacterAttributes::HairColor h,
        CharacterAttributes::EyeColor e,
        CharacterAttributes::Accessories acc,
        CharacterAttributes::Gender g)
    : name(n), age(a), hair(h), eyes(e), accessory(acc), gender(g) {}

// Getters
string Character::getName() const {return name;}
int Character::getAge() const { return age; }
CharacterAttributes::HairColor Character::getHairColor() const { return hair; }
CharacterAttributes::EyeColor Character::getEyeColor() const { return eyes; }
CharacterAttributes::Accessories Character::getAccessory() const { return accessory; }
CharacterAttributes::Gender Character::getGender() const { return gender; }

// Comparison operator
bool Character::operator==(const Character& other) const {
    return (hair == other.hair &&
            eyes == other.eyes &&
            accessory == other.accessory &&
		    gender == other.gender);
}

// String representation

string Character::toString() const {
    stringstream ss;

    ss << left << setw(10) << name
        << setw(10) << ("(" + to_string(age) + ")")
        << setw(15) << CharacterAttributes::hairToString(hair)
        << setw(15) << CharacterAttributes::eyeToString(eyes)
        << setw(20) << CharacterAttributes::accessoriesToString(accessory)
        << setw(10) << CharacterAttributes::genderToString(gender);

    return ss.str();
}
