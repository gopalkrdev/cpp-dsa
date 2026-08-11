#include <iostream>
using namespace std;

int upperBound(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > key) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int arr[] = {1, 2, 4, 4, 5, 7, 9};
    int n = 7;
    int key = 4;

    int index = upperBound(arr, n, key);

    cout << "Upper bound index: " << index << endl;

    return 0;
}
