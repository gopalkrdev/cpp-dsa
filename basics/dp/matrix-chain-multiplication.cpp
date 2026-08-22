#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainMultiplication(int arr[], int n) {

    // dp[i][j] = minimum cost to multiply
    // matrices from i to j
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // length = chain length
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

    // Matrices:
    // A1 = 10 x 20
    // A2 = 20 x 30
    // A3 = 30 x 40
    // A4 = 40 x 30

    int arr[] = {10, 20, 30, 40, 30};

    int n = 5;

    cout << "Minimum multiplication cost: "
         << matrixChainMultiplication(arr, n)
         << endl;

    return 0;
}
