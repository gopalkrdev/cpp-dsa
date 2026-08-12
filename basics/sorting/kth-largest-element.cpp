#include <iostream>
#include <algorithm>
using namespace std;

int kthLargest(int arr[], int n, int k) {
    sort(arr, arr + n, greater<int>());

    return arr[k - 1];
}

int main() {
    int arr[] = {3, 2, 1, 5, 6, 4};
    int n = 6;
    int k = 2;

    cout << "Kth largest element: "
         << kthLargest(arr, n, k)
         << endl;

    return 0;
}
