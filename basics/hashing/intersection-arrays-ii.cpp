#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> intersection(
    vector<int>& nums1,
    vector<int>& nums2
) {
    unordered_map<int, int> freq;

    // Count frequency of nums1
    for (int x : nums1) {
        freq[x]++;
    }

    vector<int> result;

    // Check nums2
    for (int x : nums2) {

        if (freq[x] > 0) {

            result.push_back(x);

            freq[x]--;
        }
    }

    return result;
}

int main() {

    vector<int> nums1 = {
        1, 2, 2, 1
    };

    vector<int> nums2 = {
        2, 2, 3
    };

    vector<int> result =
        intersection(nums1, nums2);

    cout << "Intersection: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
