#include <iostream>
using namespace std;

int majorityElement(int arr[], int n) {
    int candidate = arr[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == candidate) {
            count++;
        } else {
            count--;
        }

        if (count == 0) {
            candidate = arr[i];
            count = 1;
        }
    }

    return candidate;
}

int main() {
    int arr[] = {2, 2, 1, 1, 1, 2, 2};
    int n = 7;

    cout << "Majority element: "
         << majorityElement(arr, n)
         << endl;

    return 0;
}
