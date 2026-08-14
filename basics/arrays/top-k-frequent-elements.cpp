#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

vector<int> topKFrequent(int arr[], int n, int k) {
    unordered_map<int, int> frequency;

    // Count frequency
    for (int i = 0; i < n; i++) {
        frequency[arr[i]]++;
    }

    // Min Heap: {frequency, element}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > minHeap;

    for (auto& item : frequency) {
        minHeap.push({item.second, item.first});

        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<int> result;

    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return result;
}

int main() {
    int arr[] = {1, 1, 1, 2, 2, 3};
    int n = 6;
    int k = 2;

    vector<int> result = topKFrequent(arr, n, k);

    cout << "Top " << k << " frequent elements: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
