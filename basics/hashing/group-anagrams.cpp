#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(
    vector<string>& words
) {
    unordered_map<
        string,
        vector<string>
    > groups;

    for (string word : words) {

        string key = word;

        // Sort characters
        sort(key.begin(), key.end());

        // Same key = same anagram group
        groups[key].push_back(word);
    }

    vector<vector<string>> result;

    for (auto entry : groups) {

        result.push_back(entry.second);
    }

    return result;
}

int main() {

    vector<string> words = {
        "eat",
        "tea",
        "tan",
        "ate",
        "nat",
        "bat"
    };

    vector<vector<string>> result =
        groupAnagrams(words);

    cout << "Grouped Anagrams:\n";

    for (vector<string>& group : result) {

        cout << "[ ";

        for (string& word : group) {
            cout << word << " ";
        }

        cout << "]\n";
    }

    return 0;
}
