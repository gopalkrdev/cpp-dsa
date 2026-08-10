#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == key) {
        return mid;
    }
    else if (arr[mid] < key) {
        return binarySearch(arr, mid + 1, high, key);
    }
    else {
        return binarySearch(arr, low, mid - 1, key);
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int key = 40;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
