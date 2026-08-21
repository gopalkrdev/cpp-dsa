#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(int coins[], int n, int amount) {

    // amount + 1 means impossible value
    vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {

        for (int j = 0; j < n; j++) {

            if (coins[j] <= i) {
                dp[i] = min(
                    dp[i],
                    dp[i - coins[j]] + 1
                );
            }
        }
    }

    if (dp[amount] > amount) {
        return -1;
    }

    return dp[amount];
}

int main() {

    int coins[] = {1, 2, 5};
    int n = 3;
    int amount = 11;

    cout << "Minimum coins required: "
         << coinChange(coins, n, amount)
         << endl;

    return 0;
}
