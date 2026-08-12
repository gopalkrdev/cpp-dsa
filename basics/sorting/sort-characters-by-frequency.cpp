#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<char, int> a, pair<char, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }

    return a.second > b.second;
}

int main() {
    string str;

    cout << "Enter a string: ";
    cin >> str;

    map<char, int> frequency;

    for (char ch : str) {
        frequency[ch]++;
    }

    vector<pair<char, int>> characters;

    for (auto item : frequency) {
        characters.push_back(item);
    }

    sort(characters.begin(), characters.end(), compare);

    cout << "Sorted by frequency: ";

    for (auto item : characters) {
        for (int i = 0; i < item.second; i++) {
            cout << item.first;
        }
    }

    cout << endl;

    return 0;
}
