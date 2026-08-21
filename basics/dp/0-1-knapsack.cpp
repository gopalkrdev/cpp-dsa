#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int weights[], int values[], int n, int capacity) {

    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; i++) {

        // Reverse loop is important for 0/1 Knapsack
        for (int w = capacity; w >= weights[i]; w--) {

            dp[w] = max(
                dp[w],
                values[i] + dp[w - weights[i]]
            );
        }
    }

    return dp[capacity];
}

int main() {

    int weights[] = {10, 20, 30};
    int values[] = {60, 100, 120};

    int n = 3;
    int capacity = 50;

    cout << "Maximum value: "
         << knapsack(weights, values, n, capacity)
         << endl;

    return 0;
}
