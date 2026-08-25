#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {

    stack<int> st;

    int water = 0;

    for (int i = 0; i < height.size(); i++) {

        while (!st.empty() &&
               height[i] > height[st.top()]) {

            int bottom = st.top();
            st.pop();

            // No left boundary
            if (st.empty()) {
                break;
            }

            int left = st.top();

            int width = i - left - 1;

            int boundedHeight =
                min(height[left], height[i])
                - height[bottom];

            water += width * boundedHeight;
        }

        st.push(i);
    }

    return water;
}

int main() {

    vector<int> height = {
        0, 1, 0, 2, 1, 0,
        1, 3, 2, 1, 2, 1
    };

    cout << "Trapped Water: "
         << trap(height)
         << endl;

    return 0;
}
