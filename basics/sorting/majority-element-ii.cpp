#include <iostream>
#include <vector>
using namespace std;

vector<int> majorityElement(int arr[], int n) {
    int candidate1 = 0;
    int candidate2 = 1;

    int count1 = 0;
    int count2 = 0;

    // Find two possible candidates
    for (int i = 0; i < n; i++) {

        if (arr[i] == candidate1) {
            count1++;
        }
        else if (arr[i] == candidate2) {
            count2++;
        }
        else if (count1 == 0) {
            candidate1 = arr[i];
            count1 = 1;
        }
        else if (count2 == 0) {
            candidate2 = arr[i];
            count2 = 1;
        }
        else {
            count1--;
            count2--;
        }
    }

    // Verify candidates
    count1 = 0;
    count2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate1)
            count1++;

        if (arr[i] == candidate2)
            count2++;
    }

    vector<int> result;

    if (count1 > n / 3)
        result.push_back(candidate1);

    if (candidate2 != candidate1 && count2 > n / 3)
        result.push_back(candidate2);

    return result;
}

int main() {
    int arr[] = {1, 2, 1, 1, 3, 2, 2};
    int n = 7;

    vector<int> result = majorityElement(arr, n);

    cout << "Majority elements: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
