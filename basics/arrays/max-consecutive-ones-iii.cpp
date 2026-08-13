#include <iostream>
#include <algorithm>
using namespace std;

int longestOnes(int arr[], int n, int k) {
    int left = 0;
    int zeros = 0;
    int maxLength = 0;

    for (int right = 0; right < n; right++) {

        if (arr[right] == 0) {
            zeros++;
        }

        // More than k zeros -> shrink window
        while (zeros > k) {
            if (arr[left] == 0) {
                zeros--;
            }

            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    int arr[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int n = 11;
    int k = 2;

    cout << "Longest consecutive ones: "
         << longestOnes(arr, n, k)
         << endl;

    return 0;
}
