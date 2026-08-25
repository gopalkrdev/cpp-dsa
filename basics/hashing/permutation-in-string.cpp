#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkInclusion(string s1, string s2) {

    if (s1.length() > s2.length()) {
        return false;
    }

    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);

    // Frequency of s1
    for (char ch : s1) {
        freq1[ch - 'a']++;
    }

    int windowSize = s1.length();

    // First window
    for (int i = 0; i < windowSize; i++) {
        freq2[s2[i] - 'a']++;
    }

    // Check first window
    if (freq1 == freq2) {
        return true;
    }

    // Sliding window
    for (int right = windowSize;
         right < s2.length();
         right++) {

        // Add new character
        freq2[s2[right] - 'a']++;

        // Remove left character
        int left = right - windowSize;

        freq2[s2[left] - 'a']--;

        // Check current window
        if (freq1 == freq2) {
            return true;
        }
    }

    return false;
}

int main() {

    string s1 = "ab";
    string s2 = "eidbaooo";

    if (checkInclusion(s1, s2)) {
        cout << "Permutation exists"
             << endl;
    }
    else {
        cout << "Permutation does not exist"
             << endl;
    }

    return 0;
}
