#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> maxSlidingWindow(
    vector<int>& nums,
    int k
) {
    vector<int> result;

    // Max Heap:
    // {value, index}
    priority_queue<pair<int, int>> maxHeap;

    for (int i = 0; i < nums.size(); i++) {

        // Add current element
        maxHeap.push({
            nums[i],
            i
        });

        // Remove elements outside window
        while (!maxHeap.empty() &&
               maxHeap.top().second <= i - k) {

            maxHeap.pop();
        }

        // Window is complete
        if (i >= k - 1) {

            result.push_back(
                maxHeap.top().first
            );
        }
    }

    return result;
}

int main() {

    vector<int> nums = {
        1, 3, -1, -3,
        5, 3, 6, 7
    };

    int k = 3;

    vector<int> result =
        maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximum: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
