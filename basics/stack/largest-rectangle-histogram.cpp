#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int largestRectangleArea(vector<int>& heights) {

    int n = heights.size();

    stack<int> st;

    int maxArea = 0;

    for (int i = 0; i <= n; i++) {

        // Sentinel height 0 at the end
        int currentHeight =
            (i == n) ? 0 : heights[i];

        while (!st.empty() &&
               currentHeight < heights[st.top()]) {

            int height = heights[st.top()];
            st.pop();

            int width;

            if (st.empty()) {
                width = i;
            }
            else {
                width = i - st.top() - 1;
            }

            int area = height * width;

            maxArea = max(maxArea, area);
        }

        st.push(i);
    }

    return maxArea;
}

int main() {

    vector<int> heights = {
        2, 1, 5, 6, 2, 3
    };

    cout << "Largest Rectangle Area: "
         << largestRectangleArea(heights)
         << endl;

    return 0;
}
