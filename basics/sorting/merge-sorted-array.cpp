#include <iostream>
using namespace std;

void mergeSortedArray(int arr1[], int m, int arr2[], int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (arr1[i] > arr2[j]) {
            arr1[k] = arr1[i];
            i--;
        } else {
            arr1[k] = arr2[j];
            j--;
        }

        k--;
    }

    while (j >= 0) {
        arr1[k] = arr2[j];
        j--;
        k--;
    }
}

int main() {
    int arr1[10] = {1, 3, 5, 0, 0, 0};
    int arr2[] = {2, 4, 6};

    int m = 3;
    int n = 3;

    mergeSortedArray(arr1, m, arr2, n);

    cout << "Merged sorted array: ";

    for (int i = 0; i < m + n; i++) {
        cout << arr1[i] << " ";
    }

    cout << endl;

    return 0;
}
