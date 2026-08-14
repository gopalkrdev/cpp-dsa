#include <iostream>
#include <string>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length())
        return false;

    int freq1[26] = {0};
    int freq2[26] = {0};

    for (char ch : s1) {
        freq1[ch - 'a']++;
    }

    int windowSize = s1.length();

    for (int i = 0; i < s2.length(); i++) {
        freq2[s2[i] - 'a']++;

        if (i >= windowSize) {
            freq2[s2[i - windowSize] - 'a']--;
        }

        if (i >= windowSize - 1) {
            bool same = true;

            for (int j = 0; j < 26; j++) {
                if (freq1[j] != freq2[j]) {
                    same = false;
                    break;
                }
            }

            if (same)
                return true;
        }
    }

    return false;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";

    if (checkInclusion(s1, s2)) {
        cout << "Permutation exists" << endl;
    } else {
        cout << "Permutation does not exist" << endl;
    }

    return 0;
}
