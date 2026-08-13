#include <iostream>
#include <iomanip>
using namespace std;

double findMaxAverage(int arr[], int n, int k) {
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

        if (windowSum > maxSum) {
            maxSum = windowSum;
        }
    }

    return (double)maxSum / k;
}

int main() {
    int arr[] = {1, 12, -5, -6, 50, 3};
    int n = 6;
    int k = 4;

    cout << fixed << setprecision(5);

    cout << "Maximum average: "
         << findMaxAverage(arr, n, k)
         << endl;

    return 0;
}
