#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& arr, int target) {
    vector<vector<int>> result;

    sort(arr.begin(), arr.end());

    int n = arr.size();

    for (int i = 0; i < n - 3; i++) {

        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        for (int j = i + 1; j < n - 2; j++) {

            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;

            int left = j + 1;
            int right = n - 1;

            while (left < right) {

                long long sum = (long long)arr[i]
                              + arr[j]
                              + arr[left]
                              + arr[right];

                if (sum == target) {
                    result.push_back({
                        arr[i],
                        arr[j],
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
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
    }

    return result;
}

int main() {
    vector<int> arr = {
        1, 0, -1, 0, -2, 2
    };

    int target = 0;

    vector<vector<int>> result =
        fourSum(arr, target);

    cout << "Quadruplets with target sum:" << endl;

    for (auto quad : result) {
        cout << "[";

        for (int i = 0; i < quad.size(); i++) {
            cout << quad[i];

            if (i != quad.size() - 1)
                cout << ", ";
        }

        cout << "]" << endl;
    }

    return 0;
}
