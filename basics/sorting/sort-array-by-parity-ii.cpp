#include <iostream>
using namespace std;

void sortByParityII(int arr[], int n) {
    int evenIndex = 0;
    int oddIndex = 1;

    while (evenIndex < n && oddIndex < n) {

        while (evenIndex < n && arr[evenIndex] % 2 == 0) {
            evenIndex += 2;
        }

        while (oddIndex < n && arr[oddIndex] % 2 != 0) {
            oddIndex += 2;
        }

        if (evenIndex < n && oddIndex < n) {
            swap(arr[evenIndex], arr[oddIndex]);
            evenIndex += 2;
            oddIndex += 2;
        }
    }
}

int main() {
    int arr[] = {4, 2, 5, 7};
    int n = 4;

    sortByParityII(arr, n);

    cout << "Array after rearranging: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
