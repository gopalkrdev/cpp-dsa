#include <iostream>
#include <unordered_map>
using namespace std;

int subarraysDivByK(int arr[], int n, int k) {
    unordered_map<int, int> frequency;

    frequency[0] = 1;

    int prefixSum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int remainder = prefixSum % k;

        // Handle negative remainder
        if (remainder < 0) {
            remainder += k;
        }

        if (frequency.find(remainder) != frequency.end()) {
            count += frequency[remainder];
        }

        frequency[remainder]++;
    }

    return count;
}

int main() {
    int arr[] = {4, 5, 0, -2, -3, 1};
    int n = 6;
    int k = 5;

    cout << "Number of subarrays divisible by "
         << k << ": "
         << subarraysDivByK(arr, n, k)
         << endl;

    return 0;
}
