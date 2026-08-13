#include <iostream>
using namespace std;

int secondLargest(int arr[], int n) {
    int largest = arr[0];
    int secondLargest = -1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest &&
                 arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

int main() {
    int arr[] = {10, 5, 8, 20, 15};
    int n = 5;

    cout << "Second largest element: "
         << secondLargest(arr, n)
         << endl;

    return 0;
}
