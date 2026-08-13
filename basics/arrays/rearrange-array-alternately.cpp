#include <iostream>
#include <algorithm>
using namespace std;

void rearrange(int arr[], int n) {
    sort(arr, arr + n);

    int result[100];

    int left = 0;
    int right = n - 1;
    int index = 0;

    while (left <= right) {

        if (left != right) {
            result[index++] = arr[right];
            result[index++] = arr[left];

            right--;
            left++;
        }
        else {
            result[index++] = arr[left];
            left++;
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 6;

    rearrange(arr, n);

    cout << "Rearranged array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
