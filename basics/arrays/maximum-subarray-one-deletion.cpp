#include <iostream>
#include <algorithm>
using namespace std;

int maximumSum(int arr[], int n) {
    int noDelete = arr[0];
    int oneDelete = 0;

    int answer = arr[0];

    for (int i = 1; i < n; i++) {

        int previousNoDelete = noDelete;
        int previousOneDelete = oneDelete;

        // Do not delete current element
        noDelete = max(arr[i],
                       previousNoDelete + arr[i]);

        // Delete one element
        oneDelete = max(previousNoDelete,
                        previousOneDelete + arr[i]);

        answer = max(answer, max(noDelete, oneDelete));
    }

    return answer;
}

int main() {
    int arr[] = {1, -2, 0, 3};
    int n = 4;

    cout << "Maximum subarray sum with one deletion: "
         << maximumSum(arr, n)
         << endl;

    return 0;
}
