#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty())
        return {};

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

    result.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= result.back()[1]) {
            result.back()[1] =
                max(result.back()[1], intervals[i][1]);
        }
        else {
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
        {9, 12}
    };

    vector<vector<int>> result =
        mergeIntervals(intervals);

    cout << "Merged intervals: ";

    for (auto interval : result) {
        cout << "[" << interval[0]
             << ", " << interval[1] << "] ";
    }

    cout << endl;

    return 0;
}
