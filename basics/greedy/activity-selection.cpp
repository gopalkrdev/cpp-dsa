#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

int activitySelection(vector<Activity>& activities) {

    // Sort by finishing time
    sort(activities.begin(), activities.end(),
         [](Activity a, Activity b) {
             return a.finish < b.finish;
         });

    int count = 1;

    int lastFinish = activities[0].finish;

    cout << "Selected activities:\n";

    cout << "("
         << activities[0].start << ", "
         << activities[0].finish << ")\n";

    for (int i = 1; i < activities.size(); i++) {

        // Activity can be selected
        if (activities[i].start >= lastFinish) {

            count++;

            cout << "("
                 << activities[i].start << ", "
                 << activities[i].finish << ")\n";

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

    int result = activitySelection(activities);

    cout << "Maximum activities: "
         << result << endl;

    return 0;
}
