#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement(
    vector<int>& nums1,
    vector<int>& nums2
) {
    unordered_map<int, int> nextGreater;

    stack<int> st;

    for (int x : nums2) {

        while (!st.empty() &&
               x > st.top()) {

            nextGreater[st.top()] = x;
            st.pop();
        }

        st.push(x);
    }

    while (!st.empty()) {

        nextGreater[st.top()] = -1;
        st.pop();
    }

    vector<int> result;

    for (int x : nums1) {
        result.push_back(nextGreater[x]);
    }

    return result;
}

int main() {

    vector<int> nums1 = {
        4, 1, 2
    };

    vector<int> nums2 = {
        1, 3, 4, 2
    };

    vector<int> result =
        nextGreaterElement(nums1, nums2);

    cout << "Answer: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
