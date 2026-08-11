#include <iostream>
#include <algorithm>
using namespace std;

long long hoursRequired(int piles[], int n, int speed) {
    long long hours = 0;

    for (int i = 0; i < n; i++) {
        hours += (piles[i] + speed - 1) / speed;
    }

    return hours;
}

int minEatingSpeed(int piles[], int n, int h) {
    int low = 1;
    int high = *max_element(piles, piles + n);

    int answer = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (hoursRequired(piles, n, mid) <= h) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    int piles[] = {3, 6, 7, 11};

    int n = 4;
    int h = 8;

    cout << "Minimum eating speed: "
         << minEatingSpeed(piles, n, h)
         << endl;

    return 0;
}
