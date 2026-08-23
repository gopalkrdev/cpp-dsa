#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {

    int n = prices.size();

    // dp[day][transactions][state]
    // state 0 = not holding stock
    // state 1 = holding stock

    vector<vector<vector<int>>> dp(
        n,
        vector<vector<int>>(3, vector<int>(2, 0))
    );

    // Initially, holding a stock means buying it
    for (int t = 1; t <= 2; t++) {
        dp[0][t][1] = -prices[0];
    }

    for (int i = 1; i < n; i++) {

        for (int t = 1; t <= 2; t++) {

            // Not holding stock:
            // either do nothing or sell today
            dp[i][t][0] = max(
                dp[i - 1][t][0],
                dp[i - 1][t][1] + prices[i]
            );

            // Holding stock:
            // either keep holding or buy today
            dp[i][t][1] = max(
                dp[i - 1][t][1],
                dp[i - 1][t - 1][0] - prices[i]
            );
        }
    }

    return dp[n - 1][2][0];
}

int main() {

    vector<int> prices = {
        3, 3, 5, 0, 0, 3, 1, 4
    };

    cout << "Maximum profit: "
         << maxProfit(prices)
         << endl;

    return 0;
}
