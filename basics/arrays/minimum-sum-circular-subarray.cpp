#include <iostream>
#include <algorithm>
using namespace std;

int kadaneMax(int arr[], int n) {
    int current = arr[0];
    int best = arr[0];

    for (int i = 1; i < n; i++) {
        current = max(arr[i], current + arr[i]);
        best = max(best, current);
    }

    return best;
}

int kadaneMin(int arr[], int n) {
    int current = arr[0];
    int best = arr[0];

    for (int i = 1; i < n; i++) {
        current = min(arr[i], current + arr[i]);
        best = min(best, current);
    }

    return best;
}

int maxCircularSum(int arr[], int n) {
    int normalMax = kadaneMax(arr, n);

    // If all elements are negative
    if (normalMax < 0) {
        return normalMax;
    }

    int totalSum = 0;

    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    int minimumSum = kadaneMin(arr, n);

    int circularMax = totalSum - minimumSum;

    return max(normalMax, circularMax);
}

int main() {
    int arr[] = {5, -3, 5};
    int n = 3;

    cout << "Maximum circular subarray sum: "
         << maxCircularSum(arr, n)
         << endl;

    return 0;
}
