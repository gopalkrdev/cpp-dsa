#include <iostream>
using namespace std;

void countingSort(int arr[], int n) {
    int maxElement = arr[0];

    // Find maximum element
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    // Create count array
    int count[maxElement + 1] = {0};

    // Count frequency of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Put elements back into original array
    int index = 0;

    for (int i = 0; i <= maxElement; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    countingSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
