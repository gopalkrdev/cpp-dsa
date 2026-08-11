#include <iostream>
#include <algorithm>
using namespace std;

bool canSplit(int arr[], int n, int k, int maxSum) {
    int parts = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxSum) {
            return false;
        }

        if (currentSum + arr[i] <= maxSum) {
            currentSum += arr[i];
        } else {
            parts++;
            currentSum = arr[i];
        }
    }

    return parts <= k;
}

int splitArray(int arr[], int n, int k) {
    int low = *max_element(arr, arr + n);
    int high = 0;

    for (int i = 0; i < n; i++) {
        high += arr[i];
    }

    int answer = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canSplit(arr, n, k, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    int arr[] = {7, 2, 5, 10, 8};
    int n = 5;
    int k = 2;

    cout << "Minimum largest subarray sum: "
         << splitArray(arr, n, k)
         << endl;

    return 0;
}
