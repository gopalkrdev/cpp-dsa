#include <iostream>
using namespace std;

void reverseArray(int arr[], int left, int right) {
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

void nextPermutation(int arr[], int n) {
    // Step 1: Find the first decreasing element
    int i = n - 2;

    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }

    // Step 2: Find element just greater than arr[i]
    if (i >= 0) {
        int j = n - 1;

        while (arr[j] <= arr[i]) {
            j--;
        }

        swap(arr[i], arr[j]);
    }

    // Step 3: Reverse the remaining part
    reverseArray(arr, i + 1, n - 1);
}

int main() {
    int arr[] = {1, 2, 3};
    int n = 3;

    nextPermutation(arr, n);

    cout << "Next permutation: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
