#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCost(vector<vector<int>>& cost) {

    int n = cost.size();

    vector<vector<int>> dp(
        n,
        vector<int>(3, 0)
    );

    // First house
    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    for (int i = 1; i < n; i++) {

        // Current house red
        dp[i][0] = cost[i][0] +
                   min(dp[i - 1][1],
                       dp[i - 1][2]);

        // Current house blue
        dp[i][1] = cost[i][1] +
                   min(dp[i - 1][0],
                       dp[i - 1][2]);

        // Current house green
        dp[i][2] = cost[i][2] +
                   min(dp[i - 1][0],
                       dp[i - 1][1]);
    }

    return min({
        dp[n - 1][0],
        dp[n - 1][1],
        dp[n - 1][2]
    });
}

int main() {

    vector<vector<int>> cost = {
        {17, 2, 17},
        {16, 16, 5},
        {14, 3, 19}
    };

    cout << "Minimum painting cost: "
         << minCost(cost)
         << endl;

    return 0;
}
