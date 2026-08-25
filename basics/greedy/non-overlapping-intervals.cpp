#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int eraseOverlapIntervals(
    vector<vector<int>>& intervals
) {
    if (intervals.empty()) {
        return 0;
    }

    // Sort by ending time
    sort(
        intervals.begin(),
        intervals.end(),
        [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        }
    );

    int removed = 0;

    int lastEnd = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {

        // Overlap
        if (intervals[i][0] < lastEnd) {

            removed++;
        }

        // No overlap
        else {

            lastEnd = intervals[i][1];
        }
    }

    return removed;
}

int main() {

    vector<vector<int>> intervals = {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 3}
    };

    int result =
        eraseOverlapIntervals(intervals);

    cout << "Minimum intervals to remove: "
         << result << endl;

    return 0;
}
