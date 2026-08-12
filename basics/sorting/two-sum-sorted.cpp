#include <iostream>
#include <algorithm>
using namespace std;

bool twoSum(int arr[], int n, int target) {
    sort(arr, arr + n);

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            cout << "Pair found: "
                 << arr[left] << " + "
                 << arr[right] << " = "
                 << target << endl;

            return true;
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    return false;
}

int main() {
    int arr[] = {2, 7, 11, 15};
    int n = 4;
    int target = 9;

    if (!twoSum(arr, n, target)) {
        cout << "No pair found" << endl;
    }

    return 0;
}
