#include <iostream>
using namespace std;

int lastOccurrence(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            result = mid;
            low = mid + 1;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int arr[] = {10, 20, 20, 20, 30, 40, 50};
    int n = 7;
    int key = 20;

    int result = lastOccurrence(arr, n, key);

    if (result != -1) {
        cout << "Last occurrence at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
