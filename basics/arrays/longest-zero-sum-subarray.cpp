#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int longestZeroSumSubarray(int arr[], int n) {
    unordered_map<int, int> firstIndex;

    int prefixSum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Prefix sum becomes zero
        if (prefixSum == 0) {
            maxLength = i + 1;
        }

        // First occurrence is important
        if (firstIndex.find(prefixSum) == firstIndex.end()) {
            firstIndex[prefixSum] = i;
        }

        // Same prefix sum means sum between them is zero
        else {
            int length = i - firstIndex[prefixSum];
            maxLength = max(maxLength, length);
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = 8;

    cout << "Longest zero-sum subarray length: "
         << longestZeroSumSubarray(arr, n)
         << endl;

    return 0;
}
