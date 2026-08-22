#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minInsertions(string s) {

    int n = s.length();

    vector<vector<int>> dp(
        n,
        vector<int>(n, 0)
    );

    // length = current substring length
    for (int length = 2; length <= n; length++) {

        for (int i = 0; i <= n - length; i++) {

            int j = i + length - 1;

            if (s[i] == s[j]) {

                dp[i][j] = dp[i + 1][j - 1];

            }
            else {

                dp[i][j] = 1 + min(
                    dp[i + 1][j],
                    dp[i][j - 1]
                );
            }
        }
    }

    return dp[0][n - 1];
}

int main() {

    string s = "mbadm";

    cout << "Minimum insertions: "
         << minInsertions(s)
         << endl;

    return 0;
}
