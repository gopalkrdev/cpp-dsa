#include <iostream>
#include <unordered_map>
using namespace std;

int countSubarrays(int arr[], int n) {
    unordered_map<int, int> frequency;

    // Treat 0 as -1
    int prefixSum = 0;
    int count = 0;

    frequency[0] = 1;

    for (int i = 0; i < n; i++) {

        if (arr[i] == 0) {
            prefixSum--;
        } else {
            prefixSum++;
        }

        // Same prefix sum means equal 0s and 1s
        if (frequency.find(prefixSum) != frequency.end()) {
            count += frequency[prefixSum];
        }

        frequency[prefixSum]++;
    }

    return count;
}

int main() {
    int arr[] = {0, 0, 1, 0, 0, 0, 1, 1};
    int n = 8;

    cout << "Number of subarrays with equal 0s and 1s: "
         << countSubarrays(arr, n)
         << endl;

    return 0;
}
