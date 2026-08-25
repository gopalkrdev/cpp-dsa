#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(
    vector<int>& nums,
    int k
) {
    unordered_map<int, int> prefixCount;

    // Empty prefix
    prefixCount[0] = 1;

    int sum = 0;
    int count = 0;

    for (int x : nums) {

        sum += x;

        int required = sum - k;

        if (prefixCount.find(required)
            != prefixCount.end()) {

            count += prefixCount[required];
        }

        prefixCount[sum]++;
    }

    return count;
}

int main() {

    vector<int> nums = {
        1, 2, 3
    };

    int k = 3;

    cout << "Number of subarrays: "
         << subarraySum(nums, k)
         << endl;

    return 0;
}
