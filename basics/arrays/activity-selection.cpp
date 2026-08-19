#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int end;
};

int maxActivities(vector<Activity>& activities) {

    // Sort by finishing time
    sort(activities.begin(), activities.end(),
         [](Activity a, Activity b) {
             return a.end < b.end;
         });

    int count = 0;
    int lastEnd = -1;

    for (Activity activity : activities) {

        // Activity can be selected
        if (activity.start >= lastEnd) {
            count++;
            lastEnd = activity.end;
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
