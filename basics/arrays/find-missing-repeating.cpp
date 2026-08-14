#include <iostream>
using namespace std;

void findMissingRepeating(int arr[], int n) {
    int repeating = -1;
    int missing = -1;

    for (int i = 0; i < n; i++) {
        int index = abs(arr[i]) - 1;

        if (arr[index] < 0) {
            repeating = abs(arr[i]);
        } else {
            arr[index] = -arr[index];
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            missing = i + 1;
            break;
        }
    }

    cout << "Repeating number: " << repeating << endl;
    cout << "Missing number: " << missing << endl;
}

int main() {
    int arr[] = {4, 3, 6, 2, 1, 1};
    int n = 6;

    findMissingRepeating(arr, n);

    return 0;
}
