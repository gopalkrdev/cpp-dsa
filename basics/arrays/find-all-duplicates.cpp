#include <iostream>
#include <vector>
using namespace std;

vector<int> findDuplicates(int arr[], int n) {
    vector<int> result;

    for (int i = 0; i < n; i++) {
        int index = abs(arr[i]) - 1;

        if (arr[index] < 0) {
            result.push_back(abs(arr[i]));
        } else {
            arr[index] = -arr[index];
        }
    }

    return result;
}

int main() {
    int arr[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int n = 8;

    vector<int> result = findDuplicates(arr, n);

    cout << "Duplicate elements: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
