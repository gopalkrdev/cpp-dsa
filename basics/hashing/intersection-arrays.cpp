#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(
    vector<int>& nums1,
    vector<int>& nums2
) {
    unordered_set<int> st;

    // Store nums1
    for (int x : nums1) {
        st.insert(x);
    }

    unordered_set<int> resultSet;

    // Check nums2
    for (int x : nums2) {

        if (st.count(x)) {
            resultSet.insert(x);
        }
    }

    // Convert set to vector
    vector<int> result;

    for (int x : resultSet) {
        result.push_back(x);
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
