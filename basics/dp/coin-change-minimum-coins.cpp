#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(int coins[], int n, int amount) {

    // dp[x] = minimum coins needed to make amount x
    vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;

    for (int x = 1; x <= amount; x++) {

        for (int i = 0; i < n; i++) {

            if (coins[i] <= x) {

                dp[x] = min(
                    dp[x],
                    1 + dp[x - coins[i]]
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

    int answer = coinChange(
        coins,
        n,
        amount
    );

    cout << "Minimum coins: "
         << answer
         << endl;

    return 0;
}
