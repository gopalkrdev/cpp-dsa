#include <iostream>
#include <algorithm>
using namespace std;

int longestSubarray(int arr[], int n) {
    int left = 0;
    int zeros = 0;
    int maxLength = 0;

    for (int right = 0; right < n; right++) {

        if (arr[right] == 0) {
            zeros++;
        }

        // We can have at most one zero
        while (zeros > 1) {
            if (arr[left] == 0) {
                zeros--;
            }

            left++;
        }

        // Delete one element
        maxLength = max(maxLength, right - left);
    }

    return maxLength;
}

int main() {
    int arr[] = {1, 1, 0, 1, 1, 1, 0, 1};
    int n = 8;

    cout << "Longest subarray after deleting one element: "
         << longestSubarray(arr, n)
         << endl;

    return 0;
}
