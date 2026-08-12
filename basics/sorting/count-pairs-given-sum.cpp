#include <iostream>
#include <algorithm>
using namespace std;

int countPairs(int arr[], int n, int target) {
    sort(arr, arr + n);

    int left = 0;
    int right = n - 1;
    int count = 0;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            // Handle duplicate values
            if (arr[left] == arr[right]) {
                int elements = right - left + 1;
                count += elements * (elements - 1) / 2;
                break;
            }

            int leftValue = arr[left];
            int rightValue = arr[right];

            int leftCount = 0;
            int rightCount = 0;

            while (left <= right &&
                   arr[left] == leftValue) {
                leftCount++;
                left++;
            }

            while (right >= left &&
                   arr[right] == rightValue) {
                rightCount++;
                right--;
            }

            count += leftCount * rightCount;
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    return count;
}

int main() {
    int arr[] = {1, 5, 7, -1, 5};
    int n = 5;
    int target = 6;

    cout << "Number of pairs: "
         << countPairs(arr, n, target)
         << endl;

    return 0;
}
