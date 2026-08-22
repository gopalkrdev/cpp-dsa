#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int minDeletions(string s) {

    int n = s.length();

    // dp[i] = minimum deletions needed
    // for substring s[0...i]
    int dp[n];

    for (int i = 0; i < n; i++) {
        dp[i] = 0;
    }

    // left stores dp[i-1][j-1]
    // right stores dp[i][j-1]
    for (int i = n - 2; i >= 0; i--) {

        int prev = 0;

        for (int j = i + 1; j < n; j++) {

            int current = dp[j];

            if (s[i] == s[j]) {

                dp[j] = prev;
            }
            else {

                dp[j] = 1 + min(
                    dp[j],
                    dp[j - 1]
                );
            }

            prev = current;
        }
    }

    return dp[n - 1];
}

int main() {

    string s = "aebcbda";

    cout << "Minimum deletions: "
         << minDeletions(s)
         << endl;

    return 0;
}
