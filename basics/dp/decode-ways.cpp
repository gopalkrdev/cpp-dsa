#include <iostream>
#include <string>
#include <vector>
using namespace std;

int numDecodings(string s) {

    int n = s.length();

    if (n == 0 || s[0] == '0') {
        return 0;
    }

    vector<int> dp(n + 1, 0);

    // Empty string has one way
    dp[0] = 1;

    // First character
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {

        // Take one digit
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }

        // Take two digits
        int number =
            (s[i - 2] - '0') * 10 +
            (s[i - 1] - '0');

        if (number >= 10 && number <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    return dp[n];
}

int main() {

    string s = "226";

    cout << "Number of decoding ways: "
         << numDecodings(s)
         << endl;

    return 0;
}
