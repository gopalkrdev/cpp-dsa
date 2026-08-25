#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> findAnagrams(
    string s,
    string p
) {
    vector<int> result;

    if (p.length() > s.length()) {
        return result;
    }

    vector<int> need(26, 0);
    vector<int> window(26, 0);

    // Frequency of pattern
    for (char ch : p) {
        need[ch - 'a']++;
    }

    int windowSize = p.length();

    // First window
    for (int i = 0; i < windowSize; i++) {
        window[s[i] - 'a']++;
    }

    // Check first window
    if (window == need) {
        result.push_back(0);
    }

    // Sliding window
    for (int right = windowSize;
         right < s.length();
         right++) {

        // Add new character
        window[s[right] - 'a']++;

        // Remove old character
        int left = right - windowSize;

        window[s[left] - 'a']--;

        // Check current window
        if (window == need) {
            result.push_back(left + 1);
        }
    }

    return result;
}

int main() {

    string s = "cbaebabacd";
    string p = "abc";

    vector<int> result =
        findAnagrams(s, p);

    cout << "Anagram starting indices: ";

    for (int index : result) {
        cout << index << " ";
    }

    cout << endl;

    return 0;
}
