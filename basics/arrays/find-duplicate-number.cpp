#include <iostream>
using namespace std;

int findDuplicate(int arr[], int n) {
    int slow = arr[0];
    int fast = arr[0];

    // Find intersection point
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    // Find entrance of cycle
    slow = arr[0];

    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main() {
    int arr[] = {1, 3, 4, 2, 2};
    int n = 5;

    cout << "Duplicate number: "
         << findDuplicate(arr, n)
         << endl;

    return 0;
}
