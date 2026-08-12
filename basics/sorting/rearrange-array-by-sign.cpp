#include <iostream>
using namespace std;

void rearrangeBySign(int arr[], int n) {
    int result[100];
    int positiveIndex = 0;
    int negativeIndex = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            result[positiveIndex] = arr[i];
            positiveIndex += 2;
        } else {
            result[negativeIndex] = arr[i];
            negativeIndex += 2;
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
}

int main() {
    int arr[] = {3, 1, -2, -5, 2, -4};
    int n = 6;

    rearrangeBySign(arr, n);

    cout << "Array after rearranging by sign: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
