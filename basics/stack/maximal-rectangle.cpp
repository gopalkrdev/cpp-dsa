#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int largestRectangleArea(vector<int>& heights) {

    int n = heights.size();

    stack<int> st;

    int maxArea = 0;

    for (int i = 0; i <= n; i++) {

        int currentHeight =
            (i == n) ? 0 : heights[i];

        while (!st.empty() &&
               currentHeight < heights[st.top()]) {

            int height = heights[st.top()];
            st.pop();

            int width;

            if (st.empty()) {
                width = i;
            }
            else {
                width = i - st.top() - 1;
            }

            int area = height * width;

            maxArea = max(maxArea, area);
        }

        st.push(i);
    }

    return maxArea;
}

int maximalRectangle(
    vector<vector<char>>& matrix
) {

    if (matrix.empty()) {
        return 0;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> heights(cols, 0);

    int maxArea = 0;

    for (int i = 0; i < rows; i++) {

        // Build histogram
        for (int j = 0; j < cols; j++) {

            if (matrix[i][j] == '1') {
                heights[j]++;
            }
            else {
                heights[j] = 0;
            }
        }

        // Largest rectangle for current row
        maxArea = max(
            maxArea,
            largestRectangleArea(heights)
        );
    }

    return maxArea;
}

int main() {

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << "Maximal Rectangle Area: "
         << maximalRectangle(matrix)
         << endl;

    return 0;
}
