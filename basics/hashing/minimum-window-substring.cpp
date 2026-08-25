#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

string minWindow(string s, string t) {

    if (t.length() > s.length()) {
        return "";
    }

    vector<int> need(128, 0);
    vector<int> window(128, 0);

    // Frequency required from t
    for (char ch : t) {
        need[ch]++;
    }

    int left = 0;

    // Number of required characters
    // that are currently satisfied
    int formed = 0;

    int required = t.length();

    int minLength = INT_MAX;
    int start = 0;

    for (int right = 0;
         right < s.length();
         right++) {

        char ch = s[right];

        window[ch]++;

        // This character contributes
        // to the required frequency
        if (need[ch] > 0 &&
            window[ch] <= need[ch]) {

            formed++;
        }

        // Current window is valid
        while (formed == required) {

            int windowLength =
                right - left + 1;

            // Store minimum window
            if (windowLength < minLength) {

                minLength = windowLength;
                start = left;
            }

            // Remove left character
            char leftChar = s[left];

            window[leftChar]--;

            if (need[leftChar] > 0 &&
                window[leftChar] < need[leftChar]) {

                formed--;
            }

            left++;
        }
    }

    if (minLength == INT_MAX) {
        return "";
    }

    return s.substr(start, minLength);
}

int main() {

    string s = "ADOBECODEBANC";
    string t = "ABC";

    string result =
        minWindow(s, t);

    cout << "Minimum window: "
         << result
         << endl;

    return 0;
}
