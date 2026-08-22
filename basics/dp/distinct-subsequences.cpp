#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long numDistinct(string s, string t) {

    int n = s.length();
    int m = t.length();

    vector<vector<long long>> dp(
        n + 1,
        vector<long long>(m + 1, 0)
    );

    // Empty target can always be formed
    // by choosing nothing.
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {

            // If characters are different,
            // we cannot use s[i-1].
            dp[i][j] = dp[i - 1][j];

            // If characters are same,
            // we have two choices:
            // 1. Use this character
            // 2. Skip this character
            if (s[i - 1] == t[j - 1]) {

                dp[i][j] += dp[i - 1][j - 1];
            }
        }
    }

    return dp[n][m];
}

int main() {

    string s = "rabbbit";
    string t = "rabbit";

    cout << "Number of distinct subsequences: "
         << numDistinct(s, t)
         << endl;

    return 0;
}
