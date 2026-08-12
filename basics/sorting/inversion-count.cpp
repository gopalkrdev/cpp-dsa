#include <iostream>
using namespace std;

long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    long long inversions = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;

            // All remaining elements in left half
            // form inversions with arr[j].
            inversions += (mid - i + 1);
        }

        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int p = left; p <= right; p++) {
        arr[p] = temp[p];
    }

    return inversions;
}

long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;

    long long count = 0;

    count += mergeSortAndCount(arr, temp, left, mid);
    count += mergeSortAndCount(arr, temp, mid + 1, right);

    count += mergeAndCount(arr, temp, left, mid, right);

    return count;
}

int main() {
    int arr[] = {5, 3, 2, 4, 1};
    int n = 5;

    int temp[100];

    long long inversions =
        mergeSortAndCount(arr, temp, 0, n - 1);

    cout << "Number of inversions: " << inversions << endl;

    return 0;
}
