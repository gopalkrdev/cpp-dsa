#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int longestSubstring(string s) {
    unordered_set<char> characters;

    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < s.length(); right++) {

        while (characters.find(s[right]) != characters.end()) {
            characters.erase(s[left]);
            left++;
        }

        characters.insert(s[right]);

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";

    cout << "Longest substring length: "
         << longestSubstring(s)
         << endl;

    return 0;
}
