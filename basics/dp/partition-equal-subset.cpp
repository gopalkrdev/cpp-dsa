#include <iostream>
#include <vector>
using namespace std;

bool canPartition(int arr[], int n) {

    int totalSum = 0;

    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    // Odd total cannot be divided into two equal parts
    if (totalSum % 2 != 0) {
        return false;
    }

    int target = totalSum / 2;

    vector<bool> dp(target + 1, false);

    dp[0] = true;

    for (int i = 0; i < n; i++) {

        // Reverse loop because each element can be used only once
        for (int sum = target; sum >= arr[i]; sum--) {

            if (dp[sum - arr[i]]) {
                dp[sum] = true;
            }
        }
    }

    return dp[target];
}

int main() {

    int arr[] = {1, 5, 11, 5};
    int n = 4;

    if (canPartition(arr, n)) {
        cout << "Array can be partitioned into two equal subsets"
             << endl;
    }
    else {
        cout << "Array cannot be partitioned into two equal subsets"
             << endl;
    }

    return 0;
}
