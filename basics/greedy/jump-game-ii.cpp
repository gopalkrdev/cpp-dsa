#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int jump(vector<int>& nums) {

    int jumps = 0;

    int currentEnd = 0;
    int farthest = 0;

    for (int i = 0; i < nums.size() - 1; i++) {

        // Farthest position reachable
        farthest = max(
            farthest,
            i + nums[i]
        );

        // Current jump range finished
        if (i == currentEnd) {

            jumps++;

            currentEnd = farthest;
        }
    }

    return jumps;
}

int main() {

    vector<int> nums = {
        2, 3, 1, 1, 4
    };

    cout << "Minimum jumps: "
         << jump(nums)
         << endl;

    return 0;
}
