#include <algorithm>
#include <iostream>
#include <list>
#include <unordered_map>

#include "Character.h"
#include "SelectionSort.h"

std::list<Node> tallyTraits(const std::list<Character>& cast) {
	std::unordered_map<std::string, int> freq;
	for(const auto& c : cast) {
		freq[CharacterAttributes::hairToString(c.getHairColor())]++;
		freq[CharacterAttributes::eyeToString(c.getEyeColor())]++;
		freq[CharacterAttributes::accessoriesToString(c.getAccessory())]++;
		freq[CharacterAttributes::genderToString(c.getGender())]++;
	}
	list<Node> traits;
	for(auto& pair : freq)
		traits.push_back({ pair.first, pair.second });
	return traits;
}

void selectionSort(list<Node>& traits) {
	int actions = 0;
	auto it = traits.begin();
	while(it != traits.end()) {
		Node n = *it;
		int min = n.frequency;
		auto it2 = it;
		auto swapIt = it2;
		while(it2 != traits.end()) {
			Node n2 = *it2;
			if(n2.frequency < min)
				swapIt = it2;
			it2++;
			actions++;
		}
		iter_swap(it, swapIt);
		it++;
		actions++;
	}
	std::cout << "The selection sort performed " << actions << " actions sorting the traits.\n";
}

std::string mostCommonTrait(const std::list<Character>& cast, int yesAnswers) {
	auto traits = tallyTraits(cast);
	selectionSort(traits);
	auto it = traits.end();
	it--;
	for(int i = 0; i < yesAnswers; i++)
		it--;
	Node n = *it;
	std::string result = n.type;
	return result;
	//MY HANDS ARE TYPING WORDS
}