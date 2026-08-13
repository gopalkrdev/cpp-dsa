#include <iostream>
using namespace std;

void printLeaders(int arr[], int n) {
    int maxRight = arr[n - 1];

    cout << "Leaders: " << maxRight << " ";

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxRight) {
            maxRight = arr[i];
            cout << maxRight << " ";
        }
    }
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = 6;

    printLeaders(arr, n);

    cout << endl;

    return 0;
}
