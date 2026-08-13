#include <iostream>
#include <algorithm>
using namespace std;

int maxConsecutiveOnes(int arr[], int n) {
    int currentCount = 0;
    int maxCount = 0;

    for (int i = 0; i < n; i++) {

        if (arr[i] == 1) {
            currentCount++;
            maxCount = max(maxCount, currentCount);
        }
        else {
            currentCount = 0;
        }
    }

    return maxCount;
}

int main() {
    int arr[] = {1, 1, 0, 1, 1, 1, 0, 1};
    int n = 8;

    cout << "Maximum consecutive ones: "
         << maxConsecutiveOnes(arr, n)
         << endl;

    return 0;
}
