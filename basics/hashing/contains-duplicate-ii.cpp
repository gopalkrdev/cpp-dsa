#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsNearbyDuplicate(
    vector<int>& nums,
    int k
) {
    unordered_map<int, int> lastIndex;

    for (int i = 0; i < nums.size(); i++) {

        // Number already seen?
        if (lastIndex.find(nums[i])
            != lastIndex.end()) {

            int previousIndex =
                lastIndex[nums[i]];

            if (i - previousIndex <= k) {
                return true;
            }
        }

        // Store latest index
        lastIndex[nums[i]] = i;
    }

    return false;
}

int main() {

    vector<int> nums = {
        1, 2, 3, 1
    };

    int k = 3;

    if (containsNearbyDuplicate(nums, k)) {
        cout << "Nearby duplicate found"
             << endl;
    }
    else {
        cout << "No nearby duplicate"
             << endl;
    }

    return 0;
}
