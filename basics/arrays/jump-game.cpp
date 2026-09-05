#include <iostream>
#include <algorithm>
using namespace std;

bool canJump(int arr[], int n) {
    int farthest = 0;

    for (int i = 0; i < n; i++) {

        if (i > farthest) {
            return false;
        }

        farthest = max(farthest, i + arr[i]);
        
        if (farthest >= n - 1) {
            return true;
        }
    }

    return false;
}

int main() {
    int arr[] = {2, 3, 1, 1, 4};
    int n = 5;

    if (canJump(arr, n)) {
        cout << "Last index is reachable" << endl;
    } else {
        cout << "Last index is not reachable" << endl;
    }

    return 0;
}
