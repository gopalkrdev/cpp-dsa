#include <iostream>
#include <algorithm>
using namespace std;

int maxArea(int height[], int n) {
    int left = 0;
    int right = n - 1;

    int maxWater = 0;

    while (left < right) {
        int width = right - left;

        int currentHeight = min(height[left], height[right]);

        int area = width * currentHeight;

        maxWater = max(maxWater, area);

        // Move the smaller height
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxWater;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = 9;

    cout << "Maximum water area: "
         << maxArea(height, n)
         << endl;

    return 0;
}
