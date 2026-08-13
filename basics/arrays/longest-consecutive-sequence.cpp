#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int longestConsecutive(int arr[], int n) {
    unordered_set<int> numbers;

    for (int i = 0; i < n; i++) {
        numbers.insert(arr[i]);
    }

    int longest = 0;

    for (int i = 0; i < n; i++) {

        // Start only if this is the beginning
        // of a sequence.
        if (numbers.find(arr[i] - 1) == numbers.end()) {

            int current = arr[i];
            int length = 1;

            while (numbers.find(current + 1) != numbers.end()) {
                current++;
                length++;
            }

            longest = max(longest, length);
        }
    }

    return longest;
}

int main() {
    int arr[] = {100, 4, 200, 1, 3, 2};
    int n = 6;

    cout << "Longest consecutive sequence length: "
         << longestConsecutive(arr, n)
         << endl;

    return 0;
}
