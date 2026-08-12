#include <iostream>
using namespace std;

void sortByParity(int arr[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {

        if (arr[left] % 2 == 0) {
            left++;
        }
        else if (arr[right] % 2 != 0) {
            right--;
        }
        else {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    int arr[] = {3, 1, 2, 4, 7, 6};
    int n = 6;

    sortByParity(arr, n);

    cout << "Array after sorting by parity: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
