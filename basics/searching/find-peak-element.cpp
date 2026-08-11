#include <iostream>
using namespace std;

int findPeak(int arr[], int n) {
    int low = 0;
    int high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[mid + 1]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    int arr[] = {1, 3, 5, 4, 2};
    int n = 5;

    int index = findPeak(arr, n);

    cout << "Peak element: " << arr[index] << endl;
    cout << "Peak index: " << index << endl;

    return 0;
}
