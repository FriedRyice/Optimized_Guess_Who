#pragma once
#include <string>
#include <vector>
using namespace std;

/************************************************************************
* Names.h
* Provides pools of male and female character names for cast generation.
* Names are guaranteed unique if removed from the pool after assignment.
************************************************************************/

namespace CharacterNames {
    static vector<string> maleNames = {
        "Adam", "Brian", "Charles", "David", "Ethan",
        "Frank", "George", "Henry", "Isaac", "Jack",
        "Kevin", "Liam", "Michael", "Nathan", "Oscar",
        "Paul", "Quentin", "Robert", "Samuel", "Thomas",
        "Victor", "William", "Xavier", "Yusuf", "Zachary"
    };

    static vector<string> femaleNames = {
        "Alice", "Beth", "Charlotte", "Diana", "Emma",
        "Fiona", "Grace", "Hannah", "Isabella", "Julia",
        "Katherine", "Laura", "Mia", "Nina", "Olivia",
        "Paula", "Queenie", "Rachel", "Sophia", "Tina",
        "Valerie", "Wendy", "Xenia", "Yvonne", "Zara"
    };
}
