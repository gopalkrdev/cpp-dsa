#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(
    vector<int>& nums,
    int k
) {
    priority_queue<
        int,
        vector<int>,
        greater<int>
    > minHeap;

    for (int num : nums) {

        minHeap.push(num);

        // Keep only k largest elements
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    return minHeap.top();
}

int main() {

    vector<int> nums = {
        7, 10, 4, 3, 20, 15
    };

    int k = 3;

    cout << "Kth largest element: "
         << findKthLargest(nums, k)
         << endl;

    return 0;
}
