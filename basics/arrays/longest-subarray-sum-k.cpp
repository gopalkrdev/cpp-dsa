#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int longestSubarray(int arr[], int n, int k) {
    unordered_map<int, int> firstIndex;

    int prefixSum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Subarray starts from index 0
        if (prefixSum == k) {
            maxLength = i + 1;
        }

        // Store first occurrence only
        if (firstIndex.find(prefixSum) == firstIndex.end()) {
            firstIndex[prefixSum] = i;
        }

        // Check whether prefixSum - k exists
        int required = prefixSum - k;

        if (firstIndex.find(required) != firstIndex.end()) {
            int length = i - firstIndex[required];

            maxLength = max(maxLength, length);
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {10, 5, 2, 7, 1, 9};
    int n = 6;
    int k = 15;

    cout << "Longest subarray length: "
         << longestSubarray(arr, n, k)
         << endl;

    return 0;
}
