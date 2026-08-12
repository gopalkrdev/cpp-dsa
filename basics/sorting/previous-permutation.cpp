#include <iostream>
using namespace std;

void reverseArray(int arr[], int left, int right) {
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

void previousPermutation(int arr[], int n) {
    // Step 1: Find the first increasing element from right
    int i = n - 2;

    while (i >= 0 && arr[i] <= arr[i + 1]) {
        i--;
    }

    // Step 2: Find the largest element smaller than arr[i]
    if (i >= 0) {
        int j = n - 1;

        while (arr[j] >= arr[i]) {
            j--;
        }

        swap(arr[i], arr[j]);
    }

    // Step 3: Reverse the remaining part
    reverseArray(arr, i + 1, n - 1);
}

int main() {
    int arr[] = {1, 3, 2};
    int n = 3;

    previousPermutation(arr, n);

    cout << "Previous permutation: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
