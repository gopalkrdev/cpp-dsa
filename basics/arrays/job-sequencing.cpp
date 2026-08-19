#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

void jobSequencing(vector<Job>& jobs) {

    // Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(),
         [](Job a, Job b) {
             return a.profit > b.profit;
         });

    int maxDeadline = 0;

    for (Job job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    vector<char> slot(maxDeadline + 1, '-');

    int totalProfit = 0;
    int jobCount = 0;

    for (Job job : jobs) {

        // Find latest available slot
        for (int j = job.deadline; j >= 1; j--) {

            if (slot[j] == '-') {
                slot[j] = job.id;
                totalProfit += job.profit;
                jobCount++;
                break;
            }
        }
    }

    cout << "Selected jobs: ";

    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != '-') {
            cout << slot[i] << " ";
        }
    }

    cout << endl;

    cout << "Number of jobs: "
         << jobCount << endl;

    cout << "Maximum profit: "
         << totalProfit << endl;
}

int main() {

    vector<Job> jobs = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    jobSequencing(jobs);

    return 0;
}
