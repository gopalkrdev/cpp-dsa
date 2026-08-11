#include <iostream>
#include <algorithm>
using namespace std;

bool canShip(int weights[], int n, int days, int capacity) {
    int dayCount = 1;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {

        if (weights[i] > capacity) {
            return false;
        }

        if (currentWeight + weights[i] <= capacity) {
            currentWeight += weights[i];
        }
        else {
            dayCount++;
            currentWeight = weights[i];
        }
    }

    return dayCount <= days;
}

int shipWithinDays(int weights[], int n, int days) {

    int low = *max_element(weights, weights + n);
    int high = 0;

    for (int i = 0; i < n; i++) {
        high += weights[i];
    }

    int answer = high;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (canShip(weights, n, days, mid)) {
            answer = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {

    int weights[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int n = 10;
    int days = 5;

    cout << "Minimum ship capacity: "
         << shipWithinDays(weights, n, days)
         << endl;

    return 0;
}
