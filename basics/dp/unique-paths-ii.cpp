#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    // Starting cell itself is blocked
    if (grid[0][0] == 1) {
        return 0;
    }

    vector<int> dp(n, 0);

    dp[0] = 1;

    for (int i = 0; i < m; i++) {

        for (int j = 0; j < n; j++) {

            // Obstacle
            if (grid[i][j] == 1) {
                dp[j] = 0;
            }
            else if (j > 0) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
    }

    return dp[n - 1];
}

int main() {

    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    cout << "Number of unique paths: "
         << uniquePathsWithObstacles(grid)
         << endl;

    return 0;
}
