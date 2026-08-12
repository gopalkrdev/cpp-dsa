#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int countStations(vector<int>& stations, double distance) {
    int count = 0;

    for (int i = 1; i < stations.size(); i++) {
        double gap = stations[i] - stations[i - 1];

        count += (int)(gap / distance);
    }

    return count;
}

double minimizeMaxDistance(vector<int>& stations, int k) {

    double low = 0.0;
    double high = 0.0;

    for (int i = 1; i < stations.size(); i++) {
        high = max(high,
                   (double)(stations[i] - stations[i - 1]));
    }

    for (int iteration = 0; iteration < 100; iteration++) {

        double mid = low + (high - low) / 2.0;

        if (countStations(stations, mid) <= k) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return high;
}

int main() {

    vector<int> stations = {1, 2, 3, 4, 5};
    int k = 4;

    cout << fixed << setprecision(2);

    cout << "Minimum maximum distance: "
         << minimizeMaxDistance(stations, k)
         << endl;

    return 0;
}
