#include <iostream>
using namespace std;

int maxProfit(int prices[], int n) {

    int profit = 0;

    for (int i = 1; i < n; i++) {

        // Price increased, so take the profit
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }

    return profit;
}

int main() {

    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = 6;

    cout << "Maximum profit: "
         << maxProfit(prices, n)
         << endl;

    return 0;
}
