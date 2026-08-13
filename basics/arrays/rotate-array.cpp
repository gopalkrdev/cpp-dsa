#include <iostream>
using namespace std;

void reverseArray(int arr[], int left, int right) {
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

void rotateArray(int arr[], int n, int k) {
    k = k % n;

    // Reverse entire array
    reverseArray(arr, 0, n - 1);

    // Reverse first k elements
    reverseArray(arr, 0, k - 1);

    // Reverse remaining elements
    reverseArray(arr, k, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int k = 3;

    rotateArray(arr, n, k);

    cout << "Array after rotation: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
