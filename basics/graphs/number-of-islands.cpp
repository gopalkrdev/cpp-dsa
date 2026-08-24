#include <iostream>
#include <vector>
using namespace std;

void dfs(
    int row,
    int col,
    vector<vector<int>>& grid
) {
    int m = grid.size();
    int n = grid[0].size();

    // Boundary check
    if (row < 0 || row >= m ||
        col < 0 || col >= n) {
        return;
    }

    // Water or already visited
    if (grid[row][col] == 0) {
        return;
    }

    // Mark as visited
    grid[row][col] = 0;

    // Up
    dfs(row - 1, col, grid);

    // Down
    dfs(row + 1, col, grid);

    // Left
    dfs(row, col - 1, grid);

    // Right
    dfs(row, col + 1, grid);
}

int numberOfIslands(
    vector<vector<int>>& grid
) {
    int m = grid.size();
    int n = grid[0].size();

    int islands = 0;

    for (int i = 0; i < m; i++) {

        for (int j = 0; j < n; j++) {

            if (grid[i][j] == 1) {

                islands++;

                dfs(i, j, grid);
            }
        }
    }

    return islands;
}

int main() {

    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 1, 1}
    };

    cout << "Number of islands: "
         << numberOfIslands(grid)
         << endl;

    return 0;
}
