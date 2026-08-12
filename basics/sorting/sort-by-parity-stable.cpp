#include <iostream>
using namespace std;

void stableParitySort(int arr[], int n) {
    int result[100];
    int index = 0;

    // First put even elements
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            result[index] = arr[i];
            index++;
        }
    }

    // Then put odd elements
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            result[index] = arr[i];
            index++;
        }
    }

    // Copy result back
    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
}

int main() {
    int arr[] = {3, 2, 4, 1, 6, 5};
    int n = 6;

    stableParitySort(arr, n);

    cout << "Stable parity sorted array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
