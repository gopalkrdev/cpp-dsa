#include <iostream>
#include <algorithm>
using namespace std;

bool canPaint(int boards[], int n, int painters, int maxTime) {
    int painterCount = 1;
    int time = 0;

    for (int i = 0; i < n; i++) {

        if (boards[i] > maxTime) {
            return false;
        }

        if (time + boards[i] <= maxTime) {
            time += boards[i];
        }
        else {
            painterCount++;
            time = boards[i];
        }
    }

    return painterCount <= painters;
}

int painterPartition(int boards[], int n, int painters) {

    if (painters > n) {
        return -1;
    }

    int low = *max_element(boards, boards + n);
    int high = 0;

    for (int i = 0; i < n; i++) {
        high += boards[i];
    }

    int answer = high;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (canPaint(boards, n, painters, mid)) {
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

    int boards[] = {10, 20, 30, 40};
    int n = 4;
    int painters = 2;

    cout << "Minimum maximum time: "
         << painterPartition(boards, n, painters)
         << endl;

    return 0;
}
