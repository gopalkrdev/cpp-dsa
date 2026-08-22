#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(int k, int prices[], int n) {

    if (n == 0 || k == 0) {
        return 0;
    }

    // If k is large, it becomes unlimited transactions
    if (k >= n / 2) {

        int profit = 0;

        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }

    // dp[t][0] = maximum profit after t transactions
    //            with no stock in hand
    //
    // dp[t][1] = maximum profit after t transactions
    //            while holding a stock

    vector<int> buy(k + 1, -1000000000);
    vector<int> sell(k + 1, 0);

    for (int price = 0; price < n; price++) {

        for (int t = 1; t <= k; t++) {

            buy[t] = max(
                buy[t],
                sell[t - 1] - prices[price]
            );

            sell[t] = max(
                sell[t],
                buy[t] + prices[price]
            );
        }
    }

    return sell[k];
}

int main() {

    int prices[] = {3, 2, 6, 5, 0, 3};

    int n = 6;
    int k = 2;

    cout << "Maximum profit: "
         << maxProfit(k, prices, n)
         << endl;

    return 0;
}
