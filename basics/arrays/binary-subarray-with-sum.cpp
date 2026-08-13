#include <iostream>
#include <unordered_map>
using namespace std;

int numSubarraysWithSum(int arr[], int n, int goal) {
    unordered_map<int, int> prefixCount;

    prefixCount[0] = 1;

    int prefixSum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int required = prefixSum - goal;

        if (prefixCount.find(required) != prefixCount.end()) {
            count += prefixCount[required];
        }

        prefixCount[prefixSum]++;
    }

    return count;
}

int main() {
    int arr[] = {1, 0, 1, 0, 1};
    int n = 5;
    int goal = 2;

    cout << "Number of subarrays: "
         << numSubarraysWithSum(arr, n, goal)
         << endl;

    return 0;
}
