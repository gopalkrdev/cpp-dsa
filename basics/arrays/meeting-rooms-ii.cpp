#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
        return 0;
    }

    sort(intervals.begin(), intervals.end());

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (auto& interval : intervals) {
        int start = interval[0];
        int end = interval[1];

        if (!minHeap.empty() && minHeap.top() <= start) {
            minHeap.pop();
        }

        minHeap.push(end);
    }

    return minHeap.size();
}

int main() {
    vector<vector<int>> intervals = {
        {0, 30},
        {5, 10},
        {15, 20}
    };

    cout << "Minimum meeting rooms required: "
         << minMeetingRooms(intervals)
         << endl;

    return 0;
}
