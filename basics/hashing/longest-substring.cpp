#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {

    unordered_map<char, int> lastIndex;

    int left = 0;
    int maxLength = 0;

    for (int right = 0;
         right < s.length();
         right++) {

        char ch = s[right];

        if (lastIndex.find(ch)
            != lastIndex.end()) {

            left = max(
                left,
                lastIndex[ch] + 1
            );
        }

        lastIndex[ch] = right;

        int length = right - left + 1;

        maxLength = max(
            maxLength,
            length
        );
    }

    return maxLength;
}

int main() {

    string s = "abcabcbb";

    cout << "Longest substring length: "
         << lengthOfLongestSubstring(s)
         << endl;

    return 0;
}
