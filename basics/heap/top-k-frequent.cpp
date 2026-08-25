#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(
    vector<int>& nums,
    int k
) {
    // Frequency map
    unordered_map<int, int> freq;

    for (int num : nums) {
        freq[num]++;
    }

    // Min Heap:
    // {frequency, number}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > minHeap;

    for (auto entry : freq) {

        int number = entry.first;
        int frequency = entry.second;

        minHeap.push({
            frequency,
            number
        });

        // Keep only k elements
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

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
