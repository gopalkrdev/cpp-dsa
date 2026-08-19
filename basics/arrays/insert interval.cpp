#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> insertInterval(
    vector<vector<int>>& intervals,
    vector<int>& newInterval
) {
    vector<vector<int>> result;

    int i = 0;
    int n = intervals.size();

    // 1. Intervals completely before newInterval
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i]);
        i++;
    }

    // 2. Merge overlapping intervals
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] =
            min(newInterval[0], intervals[i][0]);

        newInterval[1] =
            max(newInterval[1], intervals[i][1]);

        i++;
    }

    result.push_back(newInterval);

    // 3. Remaining intervals
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}

int main() {
    vector<vector<int>> intervals = {
        {1, 3},
        {6, 9}
    };

    vector<int> newInterval = {2, 5};

    vector<vector<int>> result =
        insertInterval(intervals, newInterval);

    cout << "After inserting interval:" << endl;

    for (auto interval : result) {
        cout << "[" << interval[0]
             << ", " << interval[1] << "] ";
    }

    cout << endl;

    return 0;
}
