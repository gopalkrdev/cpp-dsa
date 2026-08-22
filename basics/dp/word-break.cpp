#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {

    int n = s.length();

    unordered_set<string> dictionary(
        wordDict.begin(),
        wordDict.end()
    );

    vector<bool> dp(n + 1, false);

    // Empty string can always be formed
    dp[0] = true;

    for (int i = 1; i <= n; i++) {

        for (int j = 0; j < i; j++) {

            string word = s.substr(j, i - j);

            if (dp[j] && dictionary.count(word)) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {

    string s = "leetcode";

    vector<string> wordDict = {
        "leet",
        "code"
    };

    if (wordBreak(s, wordDict)) {
        cout << "String can be segmented" << endl;
    }
    else {
        cout << "String cannot be segmented" << endl;
    }

    return 0;
}
