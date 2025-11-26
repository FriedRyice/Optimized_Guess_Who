#pragma once
#include <list>
#include <functional>
#include <string>
#include "Character.h"

void bubbleSort(std::list<Character>& cast,
    std::function<bool(const Character&, const Character&)> compare,
    const std::string& attributeName);
