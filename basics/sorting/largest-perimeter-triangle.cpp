#include <iostream>
#include <algorithm>
using namespace std;

int largestPerimeter(int arr[], int n) {
    sort(arr, arr + n);

    for (int i = n - 1; i >= 2; i--) {
        // Triangle condition:
        // a + b > c
        if (arr[i - 2] + arr[i - 1] > arr[i]) {
            return arr[i - 2] + arr[i - 1] + arr[i];
        }
    }

    return 0;
}

int main() {
    int arr[] = {2, 1, 2, 4, 18, 8};
    int n = 6;

    cout << "Largest perimeter: "
         << largestPerimeter(arr, n)
         << endl;

    return 0;
}
