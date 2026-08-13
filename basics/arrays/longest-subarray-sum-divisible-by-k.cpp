#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int longestSubarray(int arr[], int n, int k) {
    unordered_map<int, int> firstIndex;

    int prefixSum = 0;
    int maxLength = 0;

    // Remainder 0 exists before the array
    firstIndex[0] = -1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int remainder = prefixSum % k;

        // Handle negative numbers
        if (remainder < 0) {
            remainder += k;
        }

        // First occurrence gives maximum length
        if (firstIndex.find(remainder) != firstIndex.end()) {
            int length = i - firstIndex[remainder];
            maxLength = max(maxLength, length);
        }
        else {
            firstIndex[remainder] = i;
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {2, 7, 6, 1, 4, 5};
    int n = 6;
    int k = 3;

    cout << "Longest subarray length: "
         << longestSubarray(arr, n, k)
         << endl;

    return 0;
}
