#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    int frequency[26] = {0};

    for (char ch : s) {
        frequency[ch - 'a']++;
    }

    for (char ch : t) {
        frequency[ch - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (frequency[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string s = "anagram";
    string t = "nagaram";

    if (isAnagram(s, t)) {
        cout << "Strings are anagrams" << endl;
    } else {
        cout << "Strings are not anagrams" << endl;
    }

    return 0;
}
