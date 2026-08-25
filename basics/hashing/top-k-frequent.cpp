#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(
    vector<int>& nums,
    int k
) {
    // Step 1: Frequency count
    unordered_map<int, int> freq;

    for (int x : nums) {
        freq[x]++;
    }

    // Step 2: Min Heap
    // {frequency, element}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > minHeap;

    for (auto entry : freq) {

        int element = entry.first;
        int frequency = entry.second;

        minHeap.push({
            frequency,
            element
        });

        // Keep only K elements
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // Step 3: Create answer
    vector<int> result;

    while (!minHeap.empty()) {

        result.push_back(
            minHeap.top().second
        );

        minHeap.pop();
    }

    return result;
}

int main() {

    vector<int> nums = {
        1, 1, 1, 2, 2, 3
    };

    int k = 2;

    vector<int> result =
        topKFrequent(nums, k);

    cout << "Top "
         << k
         << " frequent elements: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
