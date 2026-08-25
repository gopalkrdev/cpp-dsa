#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {

    // Different lengths cannot be anagrams
    if (s.length() != t.length()) {
        return false;
    }

    int freq[26] = {};

    // Count characters of s
    for (char ch : s) {
        freq[ch - 'a']++;
    }

    // Remove characters of t
    for (char ch : t) {
        freq[ch - 'a']--;
    }

    // Check all frequencies
    for (int i = 0; i < 26; i++) {

        if (freq[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {

    string s = "listen";
    string t = "silent";

    if (isAnagram(s, t)) {
        cout << "Valid Anagram" << endl;
    }
    else {
        cout << "Not an Anagram" << endl;
    }

    return 0;
}
