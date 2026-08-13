#include <iostream>
#include <unordered_map>
using namespace std;

int countSubarraysWithXorK(int arr[], int n, int k) {
    unordered_map<int, int> frequency;

    int prefixXor = 0;
    int count = 0;

    frequency[0] = 1;

    for (int i = 0; i < n; i++) {
        prefixXor ^= arr[i];

        int required = prefixXor ^ k;

        if (frequency.find(required) != frequency.end()) {
            count += frequency[required];
        }

        frequency[prefixXor]++;
    }

    return count;
}

int main() {
    int arr[] = {4, 2, 2, 6, 4};
    int n = 5;
    int k = 6;

    cout << "Number of subarrays with XOR "
         << k << ": "
         << countSubarraysWithXorK(arr, n, k)
         << endl;

    return 0;
}
