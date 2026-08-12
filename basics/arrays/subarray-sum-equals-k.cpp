#include <iostream>
#include <unordered_map>
using namespace std;

int subarraySum(int arr[], int n, int k) {
    unordered_map<int, int> prefixSum;

    prefixSum[0] = 1;

    int sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        int required = sum - k;

        if (prefixSum.find(required) != prefixSum.end()) {
            count += prefixSum[required];
        }

        prefixSum[sum]++;
    }

    return count;
}

int main() {
    int arr[] = {1, 1, 1};
    int n = 3;
    int k = 2;

    cout << "Number of subarrays: "
         << subarraySum(arr, n, k)
         << endl;

    return 0;
}
