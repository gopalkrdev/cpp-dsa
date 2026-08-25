#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {

    unordered_set<int> st;

    // Put all elements into set
    for (int x : nums) {
        st.insert(x);
    }

    int longest = 0;

    for (int x : st) {

        // x is the starting point
        if (st.find(x - 1) == st.end()) {

            int current = x;
            int length = 1;

            // Find consecutive numbers
            while (st.find(current + 1)
                   != st.end()) {

                current++;
                length++;
            }

            longest = max(longest, length);
        }
    }

    return longest;
}

int main() {

    vector<int> nums = {
        100, 4, 200, 1, 3, 2
    };

    cout << "Longest consecutive sequence length: "
         << longestConsecutive(nums)
         << endl;

    return 0;
}
