#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int>& nums) {

    unordered_map<int, int> freq;

    int n = nums.size();

    for (int x : nums) {

        freq[x]++;

        if (freq[x] > n / 2) {
            return x;
        }
    }

    return -1;
}

int main() {

    vector<int> nums = {
        2, 2, 1, 1, 1, 2, 2
    };

    cout << "Majority Element: "
         << majorityElement(nums)
         << endl;

    return 0;
}
