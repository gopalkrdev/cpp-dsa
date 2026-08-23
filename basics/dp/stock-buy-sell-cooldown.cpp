#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {

    int n = prices.size();

    if (n == 0) {
        return 0;
    }

    // hold  = stock currently held
    // sold  = stock sold today
    // rest  = no stock and not selling today

    vector<int> hold(n);
    vector<int> sold(n);
    vector<int> rest(n);

    hold[0] = -prices[0];
    sold[0] = 0;
    rest[0] = 0;

    for (int i = 1; i < n; i++) {

        // Continue holding OR buy today
        hold[i] = max(
            hold[i - 1],
            rest[i - 1] - prices[i]
        );

        // Sell today
        sold[i] = hold[i - 1] + prices[i];

        // Stay at rest OR previous day was sold
        rest[i] = max(
            rest[i - 1],
            sold[i - 1]
        );
    }

    return max(
        sold[n - 1],
        rest[n - 1]
    );
}

int main() {

    vector<int> prices = {
        1, 2, 3, 0, 2
    };

    cout << "Maximum profit: "
         << maxProfit(prices)
         << endl;

    return 0;
}
