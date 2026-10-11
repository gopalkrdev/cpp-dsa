#include <iostream>
#include <vector>
using namespace std;

int findTargetSumWays(int arr[], int n, int target) {

    int total = 0;

    for (int i = 0; i < n; i++) {
        total += arr[i];
    }

    if (abs(target) > total) {
        return 0;
    }


    if ((total + target) % 2 != 0) {
        return 0;
    }

    int subsetSum = (total + target) / 2;

    vector<int> dp(subsetSum + 1, 0);

    dp[0] = 1;

    for (int i = 0; i < n; i++) {

        for (int sum = subsetSum; sum >= arr[i]; sum--) {
            dp[sum] += dp[sum - arr[i]];
        }
    }

    return dp[subsetSum];
}

int main() {

    int arr[] = {1, 1, 1, 1, 1};
    int n = 5;

    int target = 3;

    cout << "Number of ways: "
         << findTargetSumWays(arr, n, target)
         << endl;

    return 0;
}
