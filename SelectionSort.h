#pragma once

#include <list>

#include "Character.h"

// Node containing a trait type ("Blonde Hair", "Earrings", etc.) and its frequency
struct Node {
	std::string type;
	int frequency;
};

// Anyway, we delivered the bomb
std::list<Node> tallyTraits(const std::list<Character>& cast);

// Performs a selection sort on the input list of nodes
void selectionSort(std::list<Node>& traits);

// Show me the way to go home
std::string mostCommonTrait(const std::list<Character>& cast, int yesAnswers);