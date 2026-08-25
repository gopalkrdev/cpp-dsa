#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumPlatforms(
    vector<int>& arrival,
    vector<int>& departure
) {
    int n = arrival.size();

    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int i = 0;
    int j = 0;

    int platforms = 0;
    int maxPlatforms = 0;

    while (i < n && j < n) {

        // New train arrives
        if (arrival[i] <= departure[j]) {

            platforms++;

            maxPlatforms =
                max(maxPlatforms, platforms);

            i++;
        }

        // Train departs
        else {

            platforms--;

            j++;
        }
    }

    return maxPlatforms;
}

int main() {

    vector<int> arrival = {
        900, 940, 950, 1100, 1500, 1800
    };

    vector<int> departure = {
        910, 1200, 1120, 1130, 1900, 2000
    };

    cout << "Minimum platforms required: "
         << minimumPlatforms(
                arrival,
                departure
            )
         << endl;

    return 0;
}
