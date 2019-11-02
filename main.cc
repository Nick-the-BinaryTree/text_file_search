#include "lib.cc"

#include <iostream>

using namespace std;

typedef map<string, set<string>> inverted_index;

int main() {
    inverted_index ii = addFile("banana_recipe.txt", true);
    printInvertedIndex(ii);
    ii = mergeIndices(ii, addFile("story_of_a_fish.txt"));

    vector<string> res = searchTerm("banana", ii);
    res = searchTerm("fish", ii);
    res = searchTerm("a", ii);

    return 0;
}