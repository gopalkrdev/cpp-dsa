#include <iostream>
using namespace std;

int searchRotated(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        // Left half is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= key && key < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Right half is sorted
        else {
            if (arr[mid] < key && key <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    int arr[] = {40, 50, 60, 10, 20, 30};
    int n = 6;
    int key = 20;

    int index = searchRotated(arr, n, key);

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
