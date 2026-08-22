#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(int arr[], int n, int target) {

    vector<bool> dp(target + 1, false);

    // Sum 0 is always possible: choose nothing
    dp[0] = true;

    for (int i = 0; i < n; i++) {

        // Reverse traversal is important
        for (int sum = target; sum >= arr[i]; sum--) {

            if (dp[sum - arr[i]]) {
                dp[sum] = true;
            }
        }
    }

    return dp[target];
}

int main() {

    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = 6;

    int target = 9;

    if (subsetSum(arr, n, target)) {
        cout << "Subset with given sum exists" << endl;
    }
    else {
        cout << "Subset with given sum does not exist" << endl;
    }

    return 0;
}
