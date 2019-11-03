#include "porter/porter2_stemmer.cpp"

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef map<string, set<string>> inverted_index;

inverted_index addFile(string fileName, bool shouldStem=false) {
    inverted_index invertedIndex;
    ifstream file;
    string word;

    file.open(fileName);

    if (file.fail()) {
        throw "Could not find file";
    }

    while (file >> word) {
        if (shouldStem) {
            Porter2Stemmer::stem(word);
        }
        if (invertedIndex.count(word) == 0) {
            invertedIndex[word] = set<string>();
        }
        invertedIndex[word].insert(fileName);
    }
    file.close();

    return invertedIndex;
}

vector<string> searchTerm(string term, inverted_index &invertedIndex) {
    set<string> resSet = invertedIndex[term];
    vector<string> resVec;
    resVec.assign(resSet.begin(), resSet.end());
    return resVec;
}

inverted_index mergeIndices(inverted_index a, inverted_index b) {
    for (inverted_index::iterator iter = b.begin();
            iter != b.end(); iter++) {
            string bKey = iter->first;
        if (!a.count(bKey)) {
            a[bKey] = set<string>();
        }
        for (string word : iter->second) {
            a[bKey].insert(word);
        }
    }
    return a;
}

string getSearchResultString(vector<string> words) {
    string res = "";
    for (string word : words) {
        res.append(word).append("\n");
    }
    return res;
}

void printInvertedIndex(inverted_index ii) {
    cout << "{ " << endl;
    for (inverted_index::iterator iter = ii.begin();
            iter != ii.end(); iter++) {
            if (iter != ii.begin()) {
                cout << ", " << endl;
            }
            cout << "{ \"" << iter->first << "\", " << endl;
            
            set<string> wordSet = iter->second;
            cout << "{ " << endl;
            for (set<string>::iterator iter2 = wordSet.begin();
                iter2 != wordSet.end(); iter2++) {
                if (iter2 != wordSet.begin()) {
                    cout << ", " << endl;
                }
                cout << "\"" << *iter2 << "\"" << endl;
            }
            cout << "} " << endl;

            cout << " }";

    }
    cout << " }" << endl;
}

void printVector(vector<string> words) {
    for (string word : words) {
        cout << word << endl;
    }
    cout << '\n' << endl;
}