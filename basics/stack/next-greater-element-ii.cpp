#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {

    int n = nums.size();

    vector<int> answer(n, -1);

    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--) {

        int index = i % n;

        while (!st.empty() &&
               st.top() <= nums[index]) {

            st.pop();
        }

        if (!st.empty()) {
            answer[index] = st.top();
        }

        st.push(nums[index]);
    }

    return answer;
}

int main() {

    vector<int> nums = {
        1, 2, 1
    };

    vector<int> result =
        nextGreaterElements(nums);

    cout << "Answer: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
