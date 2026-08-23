#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(int k, vector<int>& prices) {

    int n = prices.size();

    if (n == 0 || k == 0) {
        return 0;
    }

    // If k is large, it becomes unlimited transactions
    if (k >= n / 2) {

        int profit = 0;

        for (int i = 1; i < n; i++) {
            profit += max(
                0,
                prices[i] - prices[i - 1]
            );
        }

        return profit;
    }

    // dp[t][0] = max profit after at most t
    // transactions without holding stock
    //
    // dp[t][1] = max profit after at most t
    // transactions while holding stock

    vector<vector<int>> dp(
        k + 1,
        vector<int>(2, 0)
    );

    for (int t = 1; t <= k; t++) {
        dp[t][1] = -prices[0];
    }

    for (int price : prices) {

        for (int t = 1; t <= k; t++) {

            // Sell today
            dp[t][0] = max(
                dp[t][0],
                dp[t][1] + price
            );

            // Buy today
            dp[t][1] = max(
                dp[t][1],
                dp[t - 1][0] - price
            );
        }
    }

    return dp[k][0];
}

int main() {

    vector<int> prices = {
        3, 2, 6, 5, 0, 3
    };

    int k = 2;

    cout << "Maximum profit: "
         << maxProfit(k, prices)
         << endl;

    return 0;
}
