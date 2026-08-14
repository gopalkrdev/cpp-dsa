#include <iostream>
#include <unordered_set>
using namespace std;

void intersection(int arr1[], int n1, int arr2[], int n2) {
    unordered_set<int> set1;
    unordered_set<int> result;

    // Store first array
    for (int i = 0; i < n1; i++) {
        set1.insert(arr1[i]);
    }

    // Find common elements
    for (int i = 0; i < n2; i++) {
        if (set1.find(arr2[i]) != set1.end()) {
            result.insert(arr2[i]);
        }
    }

    cout << "Intersection: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;
}

int main() {
    int arr1[] = {1, 2, 2, 3, 4};
    int arr2[] = {2, 2, 4, 5};

    int n1 = 5;
    int n2 = 4;

    intersection(arr1, n1, arr2, n2);

    return 0;
}
