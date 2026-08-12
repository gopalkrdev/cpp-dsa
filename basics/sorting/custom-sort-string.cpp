#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string customSort(string order, string s) {
    int frequency[26] = {0};

    for (char ch : s) {
        frequency[ch - 'a']++;
    }

    string result = "";

    // Characters according to order
    for (char ch : order) {
        while (frequency[ch - 'a'] > 0) {
            result += ch;
            frequency[ch - 'a']--;
        }
    }

    // Remaining characters
    for (int i = 0; i < 26; i++) {
        while (frequency[i] > 0) {
            result += char('a' + i);
            frequency[i]--;
        }
    }

    return result;
}

int main() {
    string order = "cba";
    string s = "abcd";

    cout << "Custom sorted string: "
         << customSort(order, s)
         << endl;

    return 0;
}
