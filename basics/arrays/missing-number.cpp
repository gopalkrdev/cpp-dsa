#include <iostream>
using namespace std;

int missingNumber(int arr[], int n) {
    int xorAll = 0;
    int xorArray = 0;

    // XOR of numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        xorAll ^= i;
    }

    // XOR of array elements
    for (int i = 0; i < n - 1; i++) {
        xorArray ^= arr[i];
    }

    return xorAll ^ xorArray;
}

int main() {
    int arr[] = {1, 2, 4, 5, 6};
    int n = 6;

    cout << "Missing number: "
         << missingNumber(arr, n)
         << endl;

    return 0;
}
