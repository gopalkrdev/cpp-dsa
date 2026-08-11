#include <iostream>
using namespace std;

int singleElement(int arr[], int n) {
    int low = 0;
    int high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // Make mid even
        if (mid % 2 == 1) {
            mid--;
        }

        if (arr[mid] == arr[mid + 1]) {
            low = mid + 2;
        } else {
            high = mid;
        }
    }

    return arr[low];
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    int n = 9;

    cout << "Single element: "
         << singleElement(arr, n) << endl;

    return 0;
}
