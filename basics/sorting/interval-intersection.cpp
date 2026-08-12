#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> findIntersection(
    vector<vector<int>>& first,
    vector<vector<int>>& second
) {
    vector<vector<int>> result;

    int i = 0;
    int j = 0;

    while (i < first.size() && j < second.size()) {
        int start = max(first[i][0], second[j][0]);
        int end = min(first[i][1], second[j][1]);

        // If intervals overlap
        if (start <= end) {
            result.push_back({start, end});
        }

        // Move the interval that ends first
        if (first[i][1] < second[j][1]) {
            i++;
        } else {
            j++;
        }
    }

    return result;
}

int main() {
    vector<vector<int>> first = {
        {0, 2},
        {5, 10},
        {13, 23},
        {24, 25}
    };

    vector<vector<int>> second = {
        {1, 5},
        {8, 12},
        {15, 24},
        {25, 26}
    };

    vector<vector<int>> result =
        findIntersection(first, second);

    cout << "Intersection: ";

    for (auto interval : result) {
        cout << "[" << interval[0]
             << ", " << interval[1] << "] ";
    }

    cout << endl;

    return 0;
}
