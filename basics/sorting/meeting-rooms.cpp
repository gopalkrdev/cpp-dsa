#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canAttendAllMeetings(vector<vector<int>>& meetings) {
    if (meetings.size() <= 1)
        return true;

    sort(meetings.begin(), meetings.end());

    for (int i = 1; i < meetings.size(); i++) {
        if (meetings[i][0] < meetings[i - 1][1]) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<vector<int>> meetings = {
        {0, 30},
        {35, 50},
        {60, 75}
    };

    if (canAttendAllMeetings(meetings)) {
        cout << "All meetings can be attended" << endl;
    } else {
        cout << "Meetings overlap" << endl;
    }

    return 0;
}
