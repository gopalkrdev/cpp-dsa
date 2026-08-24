#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

int main() {

    vector<Job> jobs = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    // Sort jobs by decreasing profit
    sort(jobs.begin(), jobs.end(),
         [](Job a, Job b) {
             return a.profit > b.profit;
         });

    // Maximum deadline
    int maxDeadline = 0;

    for (Job job : jobs) {
        maxDeadline =
            max(maxDeadline, job.deadline);
    }

    // Time slots
    vector<char> slot(maxDeadline + 1, '-');

    int totalProfit = 0;
    int jobsDone = 0;

    // Try every job
    for (Job job : jobs) {

        // Find latest free slot
        for (int t = job.deadline; t >= 1; t--) {

            if (slot[t] == '-') {

                slot[t] = job.id;

                totalProfit += job.profit;
                jobsDone++;

                break;
            }
        }
    }

    cout << "Job Sequence: ";

    for (int i = 1; i <= maxDeadline; i++) {
        cout << slot[i] << " ";
    }

    cout << endl;

    cout << "Jobs Done: "
         << jobsDone << endl;

    cout << "Maximum Profit: "
         << totalProfit << endl;

    return 0;
}
