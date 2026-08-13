#include <iostream>
using namespace std;

void findSubarray(int arr[], int n, int target) {
    int left = 0;
    int currentSum = 0;

    for (int right = 0; right < n; right++) {
        currentSum += arr[right];

        while (currentSum > target && left <= right) {
            currentSum -= arr[left];
            left++;
        }

        if (currentSum == target) {
            cout << "Subarray found from index "
                 << left << " to " << right << endl;

            cout << "Elements: ";

            for (int i = left; i <= right; i++) {
                cout << arr[i] << " ";
            }

            cout << endl;
            return;
        }
    }

    cout << "No subarray found" << endl;
}

int main() {
    int arr[] = {1, 4, 20, 3, 10, 5};
    int n = 6;
    int target = 33;

    findSubarray(arr, n, target);

    return 0;
}
