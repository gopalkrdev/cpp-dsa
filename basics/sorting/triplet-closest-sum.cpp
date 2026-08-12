#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int threeSumClosest(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());

    int n = arr.size();

    int closestSum =
        arr[0] + arr[1] + arr[2];

    for (int i = 0; i < n - 2; i++) {

        int left = i + 1;
        int right = n - 1;

        while (left < right) {

            int sum =
                arr[i] + arr[left] + arr[right];

            if (abs(sum - target) <
                abs(closestSum - target)) {
                closestSum = sum;
            }

            if (sum < target) {
                left++;
            }
            else if (sum > target) {
                right--;
            }
            else {
                return sum;
            }
        }
    }

    return closestSum;
}

int main() {
    vector<int> arr = {
        -1, 2, 1, -4
    };

    int target = 1;

    cout << "Closest three sum: "
         << threeSumClosest(arr, target)
         << endl;

    return 0;
}
