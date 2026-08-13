#include <iostream>
#include <algorithm>
using namespace std;

int maxSumSubarray(int arr[], int n, int k) {
    if (k > n)
        return -1;

    int windowSum = 0;

    // First window
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    // Slide the window
    for (int i = k; i < n; i++) {
        windowSum += arr[i];
        windowSum -= arr[i - k];

        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    int arr[] = {2, 1, 5, 1, 3, 2};
    int n = 6;
    int k = 3;

    cout << "Maximum sum of subarray of size "
         << k << ": "
         << maxSumSubarray(arr, n, k)
         << endl;

    return 0;
}
