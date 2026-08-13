#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int characterReplacement(string s, int k) {
    int frequency[26] = {0};

    int left = 0;
    int maxFrequency = 0;
    int maxLength = 0;

    for (int right = 0; right < s.length(); right++) {

        int index = s[right] - 'A';
        frequency[index]++;

        maxFrequency = max(maxFrequency, frequency[index]);

        int windowLength = right - left + 1;

        // Characters that need to be replaced
        int replacements = windowLength - maxFrequency;

        while (replacements > k) {
            frequency[s[left] - 'A']--;
            left++;

            windowLength = right - left + 1;
            replacements = windowLength - maxFrequency;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    string s = "AABABBA";
    int k = 1;

    cout << "Longest repeating character length: "
         << characterReplacement(s, k)
         << endl;

    return 0;
}
