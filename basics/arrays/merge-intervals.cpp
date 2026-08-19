#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
        return {};
    }

    // Sort according to starting time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

    result.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {

        int currentStart = intervals[i][0];
        int currentEnd = intervals[i][1];

        int lastEnd = result.back()[1];

        // Overlapping intervals
        if (currentStart <= lastEnd) {
            result.back()[1] =
                max(lastEnd, currentEnd);
        }
        else {
            // No overlap
            result.push_back(intervals[i]);
        }
    }

    return result;
}

int main() {
    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    vector<vector<int>> result =
        mergeIntervals(intervals);

    cout << "Merged intervals:" << endl;

    for (auto interval : result) {
        cout << "[" << interval[0]
             << ", " << interval[1]
             << "] ";
    }

    cout << endl;

    return 0;
}
