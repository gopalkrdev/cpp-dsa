#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestPalindrome(string s) {

    int n = s.length();

    if (n <= 1) {
        return s;
    }

    vector<vector<bool>> dp(
        n,
        vector<bool>(n, false)
    );

    int start = 0;
    int maxLength = 1;

    // Every single character is a palindrome
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // Check substrings of length 2 and more
    for (int length = 2; length <= n; length++) {

        for (int i = 0; i <= n - length; i++) {

            int j = i + length - 1;

            if (s[i] == s[j]) {

                if (length == 2) {
                    dp[i][j] = true;
                }
                else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }

            if (dp[i][j] && length > maxLength) {
                start = i;
                maxLength = length;
            }
        }
    }

    return s.substr(start, maxLength);
}

int main() {

    string s = "babad";

    string result = longestPalindrome(s);

    cout << "Longest palindromic substring: "
         << result << endl;

    cout << "Length: "
         << result.length() << endl;

    return 0;
}
