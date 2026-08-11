#include <iostream>
using namespace std;

int findKthMissing(int arr[], int n, int k) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int missing = arr[mid] - (mid + 1);

        if (missing < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low + k;
}

int main() {
    int arr[] = {2, 3, 4, 7, 11};
    int n = 5;
    int k = 5;

    cout << "Kth missing positive number: "
         << findKthMissing(arr, n, k) << endl;

    return 0;
}
