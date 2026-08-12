#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

void closestPair(int arr[], int n, int target) {
    sort(arr, arr + n);

    int left = 0;
    int right = n - 1;

    int bestLeft = arr[left];
    int bestRight = arr[right];

    int minDifference = abs(arr[left] + arr[right] - target);

    while (left < right) {
        int sum = arr[left] + arr[right];
        int difference = abs(sum - target);

        if (difference < minDifference) {
            minDifference = difference;
            bestLeft = arr[left];
            bestRight = arr[right];
        }

        if (sum < target) {
            left++;
        }
        else if (sum > target) {
            right--;
        }
        else {
            break;
        }
    }

    cout << "Closest pair: "
         << bestLeft << " and "
         << bestRight << endl;

    cout << "Sum: "
         << bestLeft + bestRight << endl;
}

int main() {
    int arr[] = {10, 22, 28, 29, 30, 40};
    int n = 6;
    int target = 54;

    closestPair(arr, n, target);

    return 0;
}
