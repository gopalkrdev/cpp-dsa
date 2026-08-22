#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {

    vector<int> dp(n, 1);

    for (int i = 1; i < m; i++) {

        for (int j = 1; j < n; j++) {
            dp[j] = dp[j] + dp[j - 1];
        }
    }

    return dp[n - 1];
}

int main() {

    int m = 3;
    int n = 7;

    cout << "Number of unique paths: "
         << uniquePaths(m, n)
         << endl;

    return 0;
}
