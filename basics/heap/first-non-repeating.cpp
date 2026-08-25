#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int firstNonRepeating(vector<int>& nums) {

    unordered_map<int, int> freq;

    // Step 1: Count frequency
    for (int x : nums) {
        freq[x]++;
    }

    // Step 2: Find first element
    // whose frequency is 1
    for (int x : nums) {

        if (freq[x] == 1) {
            return x;
        }
    }

    return -1;
}

int main() {

    vector<int> nums = {
        4, 5, 1, 2, 1, 4, 5
    };

    int result =
        firstNonRepeating(nums);

    if (result == -1) {
        cout << "No non-repeating element"
             << endl;
    }
    else {
        cout << "First non-repeating element: "
             << result
             << endl;
    }

    return 0;
}
