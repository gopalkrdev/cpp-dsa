#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {

    int n = s1.length();
    int m = s2.length();

    // Length must be equal
    if (n + m != s3.length()) {
        return false;
    }

    vector<vector<bool>> dp(
        n + 1,
        vector<bool>(m + 1, false)
    );

    dp[0][0] = true;

    for (int i = 0; i <= n; i++) {

        for (int j = 0; j <= m; j++) {

            if (i == 0 && j == 0) {
                continue;
            }

            // Take character from s1
            if (i > 0 &&
                dp[i - 1][j] &&
                s1[i - 1] == s3[i + j - 1]) {

                dp[i][j] = true;
            }

            // Take character from s2
            if (j > 0 &&
                dp[i][j - 1] &&
                s2[j - 1] == s3[i + j - 1]) {

                dp[i][j] = true;
            }
        }
    }

    return dp[n][m];
}

int main() {

    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";

    if (isInterleave(s1, s2, s3)) {
        cout << "Strings can form s3" << endl;
    }
    else {
        cout << "Strings cannot form s3" << endl;
    }

    return 0;
}
