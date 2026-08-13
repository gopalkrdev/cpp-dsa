#include <iostream>
using namespace std;

int numSubarrayProductLessThanK(int arr[], int n, int k) {
    if (k <= 1)
        return 0;

    int left = 0;
    int product = 1;
    int count = 0;

    for (int right = 0; right < n; right++) {
        product *= arr[right];

        while (product >= k && left <= right) {
            product /= arr[left];
            left++;
        }

        // All subarrays ending at right
        // from left to right are valid.
        count += right - left + 1;
    }

    return count;
}

int main() {
    int arr[] = {10, 5, 2, 6};
    int n = 4;
    int k = 100;

    cout << "Number of subarrays: "
         << numSubarrayProductLessThanK(arr, n, k)
         << endl;

    return 0;
}
