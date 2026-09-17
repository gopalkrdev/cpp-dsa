#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainMultiplication(int arr[], int n) {

 
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int length = 2; length < n; length++) {

        for (int i = 1; i < n - length + 1; i++) {

            int j = i + length - 1;

            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {

                int cost =
                    dp[i][k]
                    + dp[k + 1][j]
                    + arr[i - 1] * arr[k] * arr[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n - 1];
}

int main() {

   

    int arr[] = {10, 20, 30, 40, 30};

    int n = 5;

    cout << "Minimum multiplication cost: "
         << matrixChainMultiplication(arr, n)
         << endl;

    return 0;
}
