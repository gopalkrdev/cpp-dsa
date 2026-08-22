#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minCut(string s) {

    int n = s.length();

    // palindrome[i][j] = true if s[i...j] is palindrome
    vector<vector<bool>> palindrome(
        n,
        vector<bool>(n, false)
    );

    // Find all palindromic substrings
    for (int i = n - 1; i >= 0; i--) {

        for (int j = i; j < n; j++) {

            if (s[i] == s[j] &&
                (j - i <= 1 || palindrome[i + 1][j - 1])) {

                palindrome[i][j] = true;
            }
        }
    }

    // dp[i] = minimum cuts needed for s[0...i]
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++) {

        if (palindrome[0][i]) {
            dp[i] = 0;
        }
        else {
            dp[i] = i;

            for (int j = 1; j <= i; j++) {

                if (palindrome[j][i]) {
                    dp[i] = min(
                        dp[i],
                        dp[j - 1] + 1
                    );
                }
            }
        }
    }

    return dp[n - 1];
}

int main() {

    string s = "aab";

    cout << "Minimum cuts: "
         << minCut(s)
         << endl;

    return 0;
}
