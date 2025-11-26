#include <list>
#include <iostream>
#include <functional>
#include <algorithm>
#include "Character.h"
#include "BubbleSort.h"

using namespace std;

/*************************************************************************
*  Generic Bubble Sort for list<Character>
*  Takes a list of Character objects (the cast)
*  Uses a comparison function (lambda) to decide ordering by an attribute
*  Prints how many actions (comparisons + swaps) were performed
*************************************************************************/

void bubbleSort(list<Character>& cast,
    function<bool(const Character&, const Character&)> compare,
    const string& attributeName) {
    int actions = 0;   // Counter for total operations performed
    bool swapped;      // Flag to track if any swaps occurred in a pass

    // If the cast is empty, nothing to sort
    if (cast.empty()) return;

    // Bubble Sort runs until no swaps are needed
    do {
        swapped = false;                // Reset swap flag at start of each pass
        auto it1 = cast.begin();        // Iterator pointing to current element
        auto it2 = next(it1);           // Iterator pointing to the next element

        // Traverse the list comparing adjacent elements
        while (it2 != cast.end()) {
            actions++; // Count the comparison
            if (compare(*it1, *it2)) {  // If out of order based on attribute
                iter_swap(it1, it2);    // Swap the two characters
                actions++;              // Count the swap as an action
                swapped = true;         // Mark that a swap occurred
            }
            ++it1; // Move both iterators forward
            ++it2;
        }
    } while (swapped); // Repeat until a full pass occurs with no swaps

    // Print the total number of actions performed and the attribute sorted by
    cout << "Program performed " << actions
        << " actions during bubble sort by " << attributeName << "." << endl;
}
