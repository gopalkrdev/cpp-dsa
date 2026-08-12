#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& arr) {
    vector<vector<int>> result;

    sort(arr.begin(), arr.end());

    int n = arr.size();

    for (int i = 0; i < n - 2; i++) {

        // Skip duplicate first elements
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            long long sum =
                (long long)arr[i] + arr[left] + arr[right];

            if (sum == 0) {
                result.push_back({
                    arr[i],
                    arr[left],
                    arr[right]
                });

                int leftValue = arr[left];
                int rightValue = arr[right];

                while (left < right &&
                       arr[left] == leftValue) {
                    left++;
                }

                while (left < right &&
                       arr[right] == rightValue) {
                    right--;
                }
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return result;
}

int main() {
    vector<int> arr = {
        -1, 0, 1, 2, -1, -4
    };

    vector<vector<int>> result = threeSum(arr);

    cout << "Triplets with sum 0:" << endl;

    for (auto triplet : result) {
        cout << "["
             << triplet[0] << ", "
             << triplet[1] << ", "
             << triplet[2] << "]" << endl;
    }

    return 0;
}
