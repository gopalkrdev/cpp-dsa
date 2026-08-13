#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int longestEqual012(int arr[], int n) {
    unordered_map<string, int> firstIndex;

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    int maxLength = 0;

    // Difference state before starting
    firstIndex["0#0"] = -1;

    for (int i = 0; i < n; i++) {

        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;

        int diff01 = count0 - count1;
        int diff12 = count1 - count2;

        string state =
            to_string(diff01) + "#" + to_string(diff12);

        if (firstIndex.find(state) != firstIndex.end()) {
            int length = i - firstIndex[state];
            maxLength = max(maxLength, length);
        } else {
            firstIndex[state] = i;
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {
        0, 1, 2, 0, 1, 2, 0, 1, 2
    };

    int n = 9;

    cout << "Longest subarray with equal 0s, 1s and 2s: "
         << longestEqual012(arr, n)
         << endl;

    return 0;
}
