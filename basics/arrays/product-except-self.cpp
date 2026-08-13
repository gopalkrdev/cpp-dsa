#include <iostream>
using namespace std;

void productExceptSelf(int arr[], int n, int result[]) {

    // Prefix product
    int prefix = 1;

    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= arr[i];
    }

    // Suffix product
    int suffix = 1;

    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= arr[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = 4;

    int result[4];

    productExceptSelf(arr, n, result);

    cout << "Product except self: ";

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}
