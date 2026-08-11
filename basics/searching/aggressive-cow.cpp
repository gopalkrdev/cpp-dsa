#include <iostream>
#include <algorithm>
using namespace std;

bool canPlace(int stalls[], int n, int cows, int minDistance) {
    int count = 1;
    int lastPosition = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPosition >= minDistance) {
            count++;
            lastPosition = stalls[i];

            if (count == cows) {
                return true;
            }
        }
    }

    return false;
}

int aggressiveCows(int stalls[], int n, int cows) {
    sort(stalls, stalls + n);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int answer = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(stalls, n, cows, mid)) {
            answer = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return answer;
}

int main() {
    int stalls[] = {1, 2, 4, 8, 9};
    int n = 5;
    int cows = 3;

    cout << "Maximum minimum distance: "
         << aggressiveCows(stalls, n, cows) << endl;

    return 0;
}
