#include <iostream>
#include <climits>
using namespace std;

int minSubArrayLen(int arr[], int n, int target) {
    int left = 0;
    int currentSum = 0;
    int minLength = INT_MAX;

    for (int right = 0; right < n; right++) {
        currentSum += arr[right];

        while (currentSum >= target) {
            minLength = min(minLength, right - left + 1);

            currentSum -= arr[left];
            left++;
        }
    }

    if (minLength == INT_MAX)
        return 0;

    return minLength;
}

int main() {
    int arr[] = {2, 3, 1, 2, 4, 3};
    int n = 6;
    int target = 7;

    cout << "Minimum subarray length: "
         << minSubArrayLen(arr, n, target)
         << endl;

    return 0;
}
