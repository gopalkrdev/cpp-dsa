#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumRooms(vector<vector<int>>& meetings) {
    int n = meetings.size();

    vector<int> start(n);
    vector<int> end(n);

    for (int i = 0; i < n; i++) {
        start[i] = meetings[i][0];
        end[i] = meetings[i][1];
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int rooms = 0;
    int maxRooms = 0;

    int i = 0;
    int j = 0;

    while (i < n) {
        if (start[i] < end[j]) {
            rooms++;
            maxRooms = max(maxRooms, rooms);
            i++;
        } else {
            rooms--;
            j++;
        }
    }

    return maxRooms;
}

int main() {
    vector<vector<int>> meetings = {
        {0, 30},
        {5, 10},
        {15, 20}
    };

    cout << "Minimum meeting rooms required: "
         << minimumRooms(meetings)
         << endl;

    return 0;
}
