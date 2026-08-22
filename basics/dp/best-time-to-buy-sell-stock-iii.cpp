#include <iostream>
#include <algorithm>
using namespace std;

int maxProfit(int prices[], int n) {

    int buy1 = -prices[0];
    int sell1 = 0;

    int buy2 = -prices[0];
    int sell2 = 0;

    for (int i = 1; i < n; i++) {

        // First transaction
        buy1 = max(buy1, -prices[i]);
        sell1 = max(sell1, buy1 + prices[i]);

        // Second transaction
        buy2 = max(buy2, sell1 - prices[i]);
        sell2 = max(sell2, buy2 + prices[i]);
    }

    return sell2;
}

int main() {

    int prices[] = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = 8;

    cout << "Maximum profit: "
         << maxProfit(prices, n)
         << endl;

    return 0;
}
