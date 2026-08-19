#include <iostream>
#include <algorithm>
using namespace std;

int minJumps(int arr[], int n) {
    if (n <= 1) {
        return 0;
    }

    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;

    for (int i = 0; i < n - 1; i++) {

        farthest = max(farthest, i + arr[i]);

        // Current jump ki range complete
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;

            // Last index reached
            if (currentEnd >= n - 1) {
                break;
            }
        }
    }

    return jumps;
}

int main() {
    int arr[] = {2, 3, 1, 1, 4};
    int n = 5;

    cout << "Minimum jumps: "
         << minJumps(arr, n)
         << endl;

    return 0;
}
