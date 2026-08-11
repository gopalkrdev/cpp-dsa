#include <iostream>
using namespace std;

bool searchMatrix(int matrix[][4], int rows, int cols, int target) {
    int low = 0;
    int high = rows * cols - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int row = mid / cols;
        int col = mid % cols;

        if (matrix[row][col] == target) {
            return true;
        }
        else if (matrix[row][col] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return false;
}

int main() {
    int matrix[3][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 16;

    if (searchMatrix(matrix, 3, 4, target)) {
        cout << "Element found" << endl;
    }
    else {
        cout << "Element not found" << endl;
    }

    return 0;
}
