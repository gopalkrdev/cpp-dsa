#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int characterReplacement(string s, int k) {

    vector<int> freq(26, 0);

    int left = 0;
    int maxFreq = 0;
    int maxLength = 0;

    for (int right = 0; right < s.length(); right++) {

        int index = s[right] - 'A';

        freq[index]++;

        maxFreq = max(maxFreq, freq[index]);

        int windowLength = right - left + 1;

        int replacements =
            windowLength - maxFreq;

        // Window is invalid
        if (replacements > k) {

            freq[s[left] - 'A']--;

            left++;
        }

        windowLength = right - left + 1;

        maxLength =
            max(maxLength, windowLength);
    }

    return maxLength;
}

int main() {

    string s = "ABAB";
    int k = 2;

    cout << "Longest length: "
         << characterReplacement(s, k)
         << endl;

    return 0;
}
