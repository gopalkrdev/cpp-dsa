#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumPathSum(vector<vector<int>>& matrix) {

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp = matrix;

    for (int i = 1; i < n; i++) {

        for (int j = 0; j < m; j++) {

            int up = dp[i - 1][j];

            int leftDiagonal = 0;
            int rightDiagonal = 0;

            if (j > 0)
                leftDiagonal = dp[i - 1][j - 1];

            if (j < m - 1)
                rightDiagonal = dp[i - 1][j + 1];

            dp[i][j] += max({
                up,
                leftDiagonal,
                rightDiagonal
            });
        }
    }

    return *max_element(
        dp[n - 1].begin(),
        dp[n - 1].end()
    );
}

int main() {

    vector<vector<int>> matrix = {
        {10, 10, 2, 0, 20, 4},
        {1, 0, 0, 30, 2, 5},
        {0, 10, 4, 0, 2, 0},
        {1, 0, 2, 20, 0, 4}
    };

    cout << "Maximum path sum: "
         << maximumPathSum(matrix)
         << endl;

    return 0;
}
