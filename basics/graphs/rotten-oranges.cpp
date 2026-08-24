#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> q;

    int fresh = 0;
    int minutes = 0;

    // Put all rotten oranges into queue
    // and count fresh oranges
    for (int i = 0; i < m; i++) {

        for (int j = 0; j < n; j++) {

            if (grid[i][j] == 2) {
                q.push({i, j});
            }

            else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    // Multi-source BFS
    while (!q.empty() && fresh > 0) {

        int size = q.size();

        // One complete level = one minute
        for (int i = 0; i < size; i++) {

            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for (int d = 0; d < 4; d++) {

                int newRow = row + dr[d];
                int newCol = col + dc[d];

                // Check boundary
                if (newRow < 0 || newRow >= m ||
                    newCol < 0 || newCol >= n) {
                    continue;
                }

                // Fresh orange found
                if (grid[newRow][newCol] == 1) {

                    grid[newRow][newCol] = 2;

                    fresh--;

                    q.push({
                        newRow,
                        newCol
                    });
                }
            }
        }

        minutes++;
    }

    // Fresh oranges still remain
    if (fresh > 0) {
        return -1;
    }

    return minutes;
}

int main() {

    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    cout << "Minimum time: "
         << orangesRotting(grid)
         << endl;

    return 0;
}
