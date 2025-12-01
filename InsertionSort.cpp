#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <sstream>
#include "Character.h"
using namespace std;

//This is for counting number of times traits occur
struct TraitCount {
    string traitName;
    int count;
};
//This makes lists of the previous counter
list<TraitCount> TraitCountsStructList(const list<Character>& cast)
{
    unordered_map<string, int> freq; //Hash table contains attribute type (hair, eye, age, etc.) and specific value (black, red, 20, etc.)

    for (const auto& c : cast) //This goes over every member of the cast
    {
        freq[CharacterAttributes::hairToString(c.getHairColor())]++; //These count each instance of the attributes using freq

        freq[CharacterAttributes::eyeToString(c.getEyeColor())]++;

        freq[CharacterAttributes::accessoriesToString(c.getAccessory())]++;

        freq[CharacterAttributes::genderToString(c.getGender())]++;
    }

    list<TraitCount> traits; //Creates traits list
    for (auto& pair : freq) //Iterates through has map
        traits.push_back({ pair.first, pair.second }); //And adds to TraitCount
    return traits;
}

//This is the actual function. The thing that sorts
void insertionSortTraits(list<TraitCount>& traits)
{
    if (traits.size() < 2) //If list is too small, skip sorting
        return;

    auto it = traits.begin();          //}
    ++it;                              //}Iterating through the list
                                       //}
    while (it != traits.end())
    {
        auto current = it++;           //}Stores element we want to insert
        auto pos = current;            //}move it to next element

        while (pos != traits.begin() && prev(pos)->count > current->count)
        {
            --pos;                     //pos moves back until correct spot is found
        }

        if (pos != current)            //move to pos
            traits.splice(pos, traits, current);
    }
}

string findMostCommonTrait(const list<Character>& cast) //Finds most common trait
{
    auto traits = TraitCountsStructList(cast); //Puts traits into list

    insertionSortTraits(traits); //Sorts list into ascending order

    return traits.back().traitName; //Returns most common trait
}
