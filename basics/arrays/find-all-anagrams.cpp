#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> result;

    if (p.length() > s.length())
        return result;

    int frequencyP[26] = {0};
    int frequencyWindow[26] = {0};

    for (char ch : p) {
        frequencyP[ch - 'a']++;
    }

    int windowSize = p.length();

    for (int i = 0; i < s.length(); i++) {
        frequencyWindow[s[i] - 'a']++;

        // Remove element outside the window
        if (i >= windowSize) {
            frequencyWindow[s[i - windowSize] - 'a']--;
        }

        // Compare frequencies
        if (i >= windowSize - 1) {
            bool same = true;

            for (int j = 0; j < 26; j++) {
                if (frequencyP[j] != frequencyWindow[j]) {
                    same = false;
                    break;
                }
            }

            if (same) {
                result.push_back(i - windowSize + 1);
            }
        }
    }

    return result;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";

    vector<int> result = findAnagrams(s, p);

    cout << "Anagram starting indices: ";

    for (int index : result) {
        cout << index << " ";
    }

    cout << endl;

    return 0;
}
