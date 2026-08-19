#include <iostream>
#include <algorithm>
using namespace std;

int findMinimumPlatforms(int arrival[], int departure[], int n) {

    // Sort arrival and departure times
    sort(arrival, arrival + n);
    sort(departure, departure + n);

    int i = 0;
    int j = 0;

    int platforms = 0;
    int maxPlatforms = 0;

    while (i < n && j < n) {

        // New train arrives before current train departs
        if (arrival[i] <= departure[j]) {
            platforms++;
            maxPlatforms = max(maxPlatforms, platforms);
            i++;
        }
        else {
            // A train has departed
            platforms--;
            j++;
        }
    }

    return maxPlatforms;
}

int main() {

    int arrival[] = {
        900, 940, 950, 1100, 1500, 1800
    };

    int departure[] = {
        910, 1200, 1120, 1130, 1900, 2000
    };

    int n = 6;

    cout << "Minimum platforms required: "
         << findMinimumPlatforms(arrival, departure, n)
         << endl;

    return 0;
}
