#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Element {
    int value;
    int row;
    int col;
};

struct Compare {
    bool operator()(Element a, Element b) {
        return a.value > b.value;
    }
};

int kthSmallest(
    vector<vector<int>>& matrix,
    int k
) {
    int n = matrix.size();

    priority_queue<
        Element,
        vector<Element>,
        Compare
    > minHeap;

    // First element of every row
    for (int row = 0; row < n; row++) {

        minHeap.push({
            matrix[row][0],
            row,
            0
        });
    }

    int answer = -1;

    for (int count = 0; count < k; count++) {

        Element current = minHeap.top();
        minHeap.pop();

        answer = current.value;

        int nextCol = current.col + 1;

        // Add next element from same row
        if (nextCol < n) {

            minHeap.push({
                matrix[current.row][nextCol],
                current.row,
                nextCol
            });
        }
    }

    return answer;
}

int main() {

    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };

    int k = 8;

    cout << "Kth smallest element: "
         << kthSmallest(matrix, k)
         << endl;

    return 0;
}
