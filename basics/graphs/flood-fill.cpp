#include <iostream>
#include <vector>
using namespace std;

void dfs(
    int row,
    int col,
    int oldColor,
    int newColor,
    vector<vector<int>>& image
) {
    int m = image.size();
    int n = image[0].size();

    // Boundary check
    if (row < 0 || row >= m ||
        col < 0 || col >= n) {
        return;
    }

    // Different color
    if (image[row][col] != oldColor) {
        return;
    }

    // Change color
    image[row][col] = newColor;

    // Up
    dfs(row - 1, col, oldColor, newColor, image);

    // Down
    dfs(row + 1, col, oldColor, newColor, image);

    // Left
    dfs(row, col - 1, oldColor, newColor, image);

    // Right
    dfs(row, col + 1, oldColor, newColor, image);
}

vector<vector<int>> floodFill(
    vector<vector<int>>& image,
    int sr,
    int sc,
    int newColor
) {
    int oldColor = image[sr][sc];

    // Important: same color
    if (oldColor == newColor) {
        return image;
    }

    dfs(
        sr,
        sc,
        oldColor,
        newColor,
        image
    );

    return image;
}

int main() {

    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1;
    int sc = 1;
    int newColor = 2;

    floodFill(
        image,
        sr,
        sc,
        newColor
    );

    cout << "After Flood Fill:" << endl;

    for (auto row : image) {

        for (int value : row) {
            cout << value << " ";
        }

        cout << endl;
    }

    return 0;
}
