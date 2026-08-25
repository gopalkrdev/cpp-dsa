#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarraySumK(
    vector<int>& nums,
    int k
) {
    unordered_map<int, int> firstIndex;

    int sum = 0;
    int maxLength = 0;

    for (int i = 0; i < nums.size(); i++) {

        sum += nums[i];

        // Subarray starts from index 0
        if (sum == k) {
            maxLength = i + 1;
        }

        // Check previous prefix sum
        int required = sum - k;

        if (firstIndex.find(required)
            != firstIndex.end()) {

            int length =
                i - firstIndex[required];

            maxLength =
                max(maxLength, length);
        }

        // Store only first occurrence
        if (firstIndex.find(sum)
            == firstIndex.end()) {

            firstIndex[sum] = i;
        }
    }

    return maxLength;
}

int main() {

    vector<int> nums = {
        10, 5, 2, 7, 1, 9
    };

    int k = 15;

    cout << "Longest subarray length: "
         << longestSubarraySumK(nums, k)
         << endl;

    return 0;
}
