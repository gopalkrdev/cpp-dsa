#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int editDistance(string s1, string s2) {

    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(
        n + 1,
        vector<int>(m + 1, 0)
    );

    // Convert empty s1 to s2
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    // Convert s1 to empty s2
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {

            if (s1[i - 1] == s2[j - 1]) {

                // Characters already same
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {

                // Insert, Delete, Replace
                dp[i][j] = 1 + min({
                    dp[i][j - 1],     // Insert
                    dp[i - 1][j],     // Delete
                    dp[i - 1][j - 1]  // Replace
                });
            }
        }
    }

    return dp[n][m];
}

int main() {

    string s1 = "horse";
    string s2 = "ros";

    cout << "Minimum operations: "
         << editDistance(s1, s2)
         << endl;

    return 0;
}
