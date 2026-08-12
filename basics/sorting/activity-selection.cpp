#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int maxActivities(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compare);

    int count = 1;
    int lastFinish = activities[0].finish;

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastFinish) {
            count++;
            lastFinish = activities[i].finish;
        }
    }

    return count;
}

int main() {
    vector<Activity> activities = {
        {1, 2},
        {3, 4},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9}
    };

    cout << "Maximum activities: "
         << maxActivities(activities)
         << endl;

    return 0;
}
