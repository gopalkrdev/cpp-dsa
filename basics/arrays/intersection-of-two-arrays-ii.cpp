#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> intersection(int arr1[], int n1, int arr2[], int n2) {
    unordered_map<int, int> frequency;
    vector<int> result;

    // Count elements of first array
    for (int i = 0; i < n1; i++) {
        frequency[arr1[i]]++;
    }

    // Check second array
    for (int i = 0; i < n2; i++) {
        if (frequency[arr2[i]] > 0) {
            result.push_back(arr2[i]);
            frequency[arr2[i]]--;
        }
    }

    return result;
}

int main() {
    int arr1[] = {1, 2, 2, 1};
    int arr2[] = {2, 2};

    int n1 = 4;
    int n2 = 2;

    vector<int> result = intersection(arr1, n1, arr2, n2);

    cout << "Intersection: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
