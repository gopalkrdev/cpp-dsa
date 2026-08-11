#include <iostream>
using namespace std;

int findFloor(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= key) {
            ans = arr[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int findCeil(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= key) {
            ans = arr[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = 5;
    int key = 6;

    cout << "Floor: " << findFloor(arr, n, key) << endl;
    cout << "Ceil: " << findCeil(arr, n, key) << endl;

    return 0;
}
