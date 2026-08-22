#include <iostream>
#include <vector>
using namespace std;

bool canPartition(int arr[], int n) {

    int totalSum = 0;

    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    // Odd total cannot be divided equally
    if (totalSum % 2 != 0) {
        return false;
    }

    int target = totalSum / 2;

    vector<bool> dp(target + 1, false);

    dp[0] = true;

    for (int i = 0; i < n; i++) {

        // Reverse loop so each element
        // is used only once
        for (int sum = target; sum >= arr[i]; sum--) {

            dp[sum] = dp[sum] ||
                      dp[sum - arr[i]];
        }
    }

    return dp[target];
}

int main() {

    int arr[] = {1, 5, 11, 5};
    int n = 4;

    if (canPartition(arr, n)) {
        cout << "Array can be partitioned equally"
             << endl;
    }
    else {
        cout << "Array cannot be partitioned equally"
             << endl;
    }

    return 0;
}
