#include <iostream>
using namespace std;

int searchInsert(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= key) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int arr[] = {1, 3, 5, 6};
    int n = 4;
    int key = 5;

    int index = searchInsert(arr, n, key);

    cout << "Insert position: " << index << endl;

    return 0;
}
