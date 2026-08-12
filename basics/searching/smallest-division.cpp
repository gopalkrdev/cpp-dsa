#include <iostream>
#include <vector>
using namespace std;

bool canDivide(vector<int>& nums, int divisor, int threshold) {
    int sum = 0;

    for (int num : nums) {
        sum += (num + divisor - 1) / divisor;

        if (sum > threshold)
            return false;
    }

    return true;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1;
    int high = 0;

    for (int num : nums)
        high = max(high, num);

    int answer = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canDivide(nums, mid, threshold)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    cout << smallestDivisor(nums, threshold) << endl;

    return 0;
}
