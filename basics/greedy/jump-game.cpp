#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(vector<int>& nums) {

    int maxReach = 0;

    for (int i = 0; i < nums.size(); i++) {

        // Current index unreachable
        if (i > maxReach) {
            return false;
        }

        // Update maximum reachable index
        maxReach =
            max(maxReach, i + nums[i]);

        // Already reached the end
        if (maxReach >= nums.size() - 1) {
            return true;
        }
    }

    return true;
}

int main() {

    vector<int> nums = {
        2, 3, 1, 1, 4
    };

    if (canJump(nums)) {
        cout << "Can reach the last index"
             << endl;
    }
    else {
        cout << "Cannot reach the last index"
             << endl;
    }

    return 0;
}
