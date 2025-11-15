#pragma once
#include <string>
#include <vector>
using namespace std;

/****************************************************************************************
* CharacterAttributes defines all possible attribute categories for a character.
* It uses scoped enums (enum class) to avoid naming collisions and ensure type safety.
* Converter functions are provided to translate enum values into human-readable strings.
****************************************************************************************/

class CharacterAttributes
{
public:
	// Define attirbutes as number values
	enum class HairColor { Black = 0, Brown = 1, Blonde = 2, Red = 3, WhiteGrey = 4};
	enum class EyeColor { Brown = 0, Blue = 1, Green = 2, Hazel = 3, Amber = 4, Grey = 5};
	enum class Accessories { Glasses = 1, Contacts = 2, Hat = 3, Earrings = 4, Necklace = 5};
	enum class Gender { Male = 1, Female = 2};

	// Converts enum values to strings for display (Hair)
	static string hairToString(HairColor h) {
		switch (h) {
		case HairColor::Black: return "Black";
		case HairColor::Brown: return "Brown";
		case HairColor::Blonde: return "Blonde";
		case HairColor::Red: return "Red";
		case HairColor::WhiteGrey: return "White/Grey";
		default: return "Unknown";
		}
	}

	// Converts enum values to strings for display (Eyes)
	static string eyeToString(EyeColor e) {
		switch (e) {
		case EyeColor::Brown: return "Brown";
		case EyeColor::Blue: return "Blue";
		case EyeColor::Green: return "Green";
		case EyeColor::Hazel: return "Hazel";
		case EyeColor::Amber: return "Amber";
		case EyeColor::Grey: return "Grey";
		default: return "Unknown";
		}
	}

	// Converts	enum values to strings for display (Acessories)
	static string accessoriesToString(Accessories a) {
		switch (a) {
		case Accessories::Glasses: return "Glasses";
		case Accessories::Contacts: return "Contacts";
		case Accessories::Hat: return "Hat";
		case Accessories::Earrings: return "Earrings";
		case Accessories::Necklace: return "Necklace";
		default: return "Unknown";
		}
	}

	// Converts enum values to strings for display (Gender)
	static string genderToString(Gender g) {
		switch (g) {
		case Gender::Male: return "Male";
		case Gender::Female: return "Female";
		default: return "Unknown";
		}
	}
};

