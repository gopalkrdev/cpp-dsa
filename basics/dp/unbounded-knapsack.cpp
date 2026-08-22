#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int unboundedKnapsack(int weight[], int value[], int n, int capacity) {

    vector<int> dp(capacity + 1, 0);

    for (int w = 0; w <= capacity; w++) {

        for (int i = 0; i < n; i++) {

            if (weight[i] <= w) {

                dp[w] = max(
                    dp[w],
                    value[i] + dp[w - weight[i]]
                );
            }
        }
    }

    return dp[capacity];
}

int main() {

    int weight[] = {2, 3, 4, 5};
    int value[] = {3, 4, 5, 6};

    int n = 4;
    int capacity = 8;

    cout << "Maximum value: "
         << unboundedKnapsack(
                weight,
                value,
                n,
                capacity
            )
         << endl;

    return 0;
}
