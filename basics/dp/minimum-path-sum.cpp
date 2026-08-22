#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    vector<int> dp(n, 0);

    dp[0] = grid[0][0];

    // First row
    for (int j = 1; j < n; j++) {
        dp[j] = dp[j - 1] + grid[0][j];
    }

    // Remaining rows
    for (int i = 1; i < m; i++) {

        dp[0] = dp[0] + grid[i][0];

        for (int j = 1; j < n; j++) {

            dp[j] = min(dp[j], dp[j - 1])
                    + grid[i][j];
        }
    }

    return dp[n - 1];
}

int main() {

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    cout << "Minimum path sum: "
         << minPathSum(grid)
         << endl;

    return 0;
}
