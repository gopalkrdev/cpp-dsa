#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    string s1 = "heap";
    string s2 = "pea";

    int n = s1.length();
    int m = s2.length();

    // Find LCS
    vector<vector<int>> dp(
        n + 1,
        vector<int>(m + 1, 0)
    );

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {

            if (s1[i - 1] == s2[j - 1]) {

                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {

                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i][j - 1]
                );
            }
        }
    }

    int lcs = dp[n][m];

    int deletions = n - lcs;
    int insertions = m - lcs;

    cout << "LCS length: " << lcs << endl;
    cout << "Minimum deletions: " << deletions << endl;
    cout << "Minimum insertions: " << insertions << endl;
    cout << "Total operations: "
         << deletions + insertions << endl;

    return 0;
}
