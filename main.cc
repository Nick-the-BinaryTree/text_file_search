#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef map<string, set<string>> inverted_index;

inverted_index addFile(string fileName) {
    inverted_index invertedIndex;
    ifstream file;
    string word;

    try {
        file.open(fileName);
        while (file >> word) {
            if (invertedIndex.count(word) == 0) {
                invertedIndex[word] = set<string>();
            }
            invertedIndex[word].insert(fileName);
        }
        file.close();
    } catch(...) {
        cout << "Could not read file." << endl;
    }
    return invertedIndex;
}

vector<string> searchTerm(string term, inverted_index &invertedIndex) {
    set<string> resSet = invertedIndex[term];
    vector<string> resVec;
    resVec.assign(resSet.begin(), resSet.end());
    return resVec;
}

inverted_index mergeIndices(inverted_index a, inverted_index b) {
    for (map<string, set<string>>::iterator iter = b.begin();
            iter != b.end(); iter++) {
            string bKey = iter->first;
            set<string> bSet = iter->second;
        if (!a.count(bKey)) {
            a[bKey] = set<string>();
        }
        for (string word : iter->second) {
            a[bKey].insert(word);
        }
    }
    return a;
}

void print(vector<string> words) {
    for (string word : words) {
        cout << word << endl;
    }
    cout << '\n' << endl;
}

int main() {
    inverted_index ii = addFile("banana_recipe.txt");
    ii = mergeIndices(ii, addFile("story_of_a_fish.txt"));

    vector<string> res = searchTerm("banana", ii);
    print(res);
    res = searchTerm("fish", ii);
    print(res);
    res = searchTerm("a", ii);
    print(res);

    return 0;
}