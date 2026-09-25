#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string shortestCommonSupersequence(string s1, string s2) {

    int n = s1.length();
    int m = s2.length();

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

    string result;

    int i = n;
    int j = m;

    while (i > 0 && j > 0) {

        if (s1[i - 1] == s2[j - 1]) {

            result += s1[i - 1];

            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {

            result += s1[i - 1];
            i--;
        }
        else {

            result += s2[j - 1];
            j--;
        }
    }

    while (i > 0) {

        result += s1[i - 1];
        i--;
    }

    while (j > 0) {

        result += s2[j - 1];
        j--;
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {

    string s1 = "abac";
    string s2 = "cab";

    string result =
        shortestCommonSupersequence(s1, s2);

    cout << "Shortest Common Supersequence: "
         << result << endl;

    cout << "Length: "
         << result.length() << endl;

    return 0;
}
