#include <iostream>
#include <string>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
    if (t.length() > s.length())
        return "";

    int required[256] = {0};

    for (char ch : t) {
        required[(unsigned char)ch]++;
    }

    int left = 0;
    int count = 0;

    int minLength = INT_MAX;
    int startIndex = 0;

    for (int right = 0; right < s.length(); right++) {

        unsigned char current = s[right];

        if (required[current] > 0) {
            required[current]--;
            count++;
        }

        while (count == t.length()) {

            if (right - left + 1 < minLength) {
                minLength = right - left + 1;
                startIndex = left;
            }

            unsigned char leftChar = s[left];

            if (required[leftChar] >= 0) {
                required[leftChar]++;
                count--;
            }

            left++;
        }
    }

    if (minLength == INT_MAX)
        return "";

    return s.substr(startIndex, minLength);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string result = minWindow(s, t);

    if (result.empty()) {
        cout << "No valid window found" << endl;
    } else {
        cout << "Minimum window: "
             << result << endl;
    }

    return 0;
}
