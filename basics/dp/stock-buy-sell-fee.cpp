#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {

    int n = prices.size();


    int hold = -prices[0];
    int cash = 0;

    for (int i = 1; i < n; i++) {

        int oldHold = hold;
        int oldCash = cash;

        hold = max(
            oldHold,
            oldCash - prices[i]
        );

        cash = max(
            oldCash,
            oldHold + prices[i] - fee
        );
    }

    return cash;
}

int main() {

    vector<int> prices = {
        1, 3, 2, 8, 4, 9
    };

    int fee = 2;

    cout << "Maximum profit: "
         << maxProfit(prices, fee)
         << endl;

    return 0;
}
