#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxCoins(vector<int>& nums) {

    int n = nums.size();

    // Add boundary balloons
    vector<int> a(n + 2, 1);

    for (int i = 0; i < n; i++) {
        a[i + 1] = nums[i];
    }

    vector<vector<int>> dp(
        n + 2,
        vector<int>(n + 2, 0)
    );

    // length = interval length
    for (int length = 1; length <= n; length++) {

        for (int left = 1;
             left + length - 1 <= n;
             left++) {

            int right = left + length - 1;

            // Choose the last balloon to burst
            for (int k = left; k <= right; k++) {

                int coins =
                    a[left - 1] * a[k] * a[right + 1]
                    + dp[left][k - 1]
                    + dp[k + 1][right];

                dp[left][right] =
                    max(dp[left][right], coins);
            }
        }
    }

    return dp[1][n];
}

int main() {

    vector<int> nums = {3, 1, 5, 8};

    cout << "Maximum coins: "
         << maxCoins(nums)
         << endl;

    return 0;
}
