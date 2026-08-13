#include <iostream>
#include <algorithm>
using namespace std;

int maxProduct(int arr[], int n) {
    int currentMax = arr[0];
    int currentMin = arr[0];

    int answer = arr[0];

    for (int i = 1; i < n; i++) {
        int value = arr[i];

        // Negative number can turn minimum into maximum
        if (value < 0) {
            swap(currentMax, currentMin);
        }

        currentMax = max(value, currentMax * value);
        currentMin = min(value, currentMin * value);

        answer = max(answer, currentMax);
    }

    return answer;
}

int main() {
    int arr[] = {2, 3, -2, 4};
    int n = 4;

    cout << "Maximum product subarray: "
         << maxProduct(arr, n)
         << endl;

    return 0;
}
