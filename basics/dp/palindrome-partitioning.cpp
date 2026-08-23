#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

bool isPalindrome(string &s, int left, int right) {

    while (left < right) {

        if (s[left] != s[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int minCuts(string s) {

    int n = s.length();

    // dp[i] = minimum cuts needed
    // for substring s[0...i]
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++) {

        if (isPalindrome(s, 0, i)) {
            dp[i] = 0;
        }
        else {

            dp[i] = INT_MAX;

            for (int j = 1; j <= i; j++) {

                if (isPalindrome(s, j, i)) {

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
         << minCuts(s)
         << endl;

    return 0;
}
