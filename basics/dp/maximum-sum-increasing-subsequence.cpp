#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumSumIncreasingSubsequence(int arr[], int n) {

    // dp[i] = maximum sum of an increasing
    // subsequence ending at index i
    vector<int> dp(n);

    for (int i = 0; i < n; i++) {
        dp[i] = arr[i];
    }

    int answer = arr[0];

    for (int i = 1; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (arr[j] < arr[i]) {

                dp[i] = max(
                    dp[i],
                    dp[j] + arr[i]
                );
            }
        }

        answer = max(answer, dp[i]);
    }

    return answer;
}

int main() {

    int arr[] = {
        1, 101, 2, 3, 100, 4, 5
    };

    int n = 7;

    cout << "Maximum sum of increasing subsequence: "
         << maximumSumIncreasingSubsequence(arr, n)
         << endl;

    return 0;
}
