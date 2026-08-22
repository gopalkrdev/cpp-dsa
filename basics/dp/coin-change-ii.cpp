#include <iostream>
#include <vector>
using namespace std;

int change(int amount, int coins[], int n) {

    vector<int> dp(amount + 1, 0);

    // Amount 0 can always be made in 1 way:
    // choose no coins
    dp[0] = 1;

    for (int i = 0; i < n; i++) {

        for (int sum = coins[i]; sum <= amount; sum++) {

            dp[sum] += dp[sum - coins[i]];
        }
    }

    return dp[amount];
}

int main() {

    int coins[] = {1, 2, 5};
    int n = 3;

    int amount = 5;

    cout << "Number of ways: "
         << change(amount, coins, n)
         << endl;

    return 0;
}
