#include <iostream>
#include <algorithm>
using namespace std;

int maxProfit(int prices[], int n) {

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++) {

        // Sell today
        int profit = prices[i] - minPrice;

        maxProfit = max(maxProfit, profit);

        // Update minimum buying price
        minPrice = min(minPrice, prices[i]);
    }

    return maxProfit;
}

int main() {

    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = 6;

    cout << "Maximum profit: "
         << maxProfit(prices, n)
         << endl;

    return 0;
}
