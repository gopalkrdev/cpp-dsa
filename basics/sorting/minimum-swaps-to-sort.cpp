#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumSwaps(int arr[], int n) {
    vector<pair<int, int>> elements;

    for (int i = 0; i < n; i++) {
        elements.push_back({arr[i], i});
    }

    sort(elements.begin(), elements.end());

    vector<bool> visited(n, false);

    int swaps = 0;

    for (int i = 0; i < n; i++) {

        if (visited[i] || elements[i].second == i) {
            continue;
        }

        int cycleSize = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;

            j = elements[j].second;
            cycleSize++;
        }

        if (cycleSize > 1) {
            swaps += cycleSize - 1;
        }
    }

    return swaps;
}

int main() {
    int arr[] = {10, 5, 2, 3, 1};
    int n = 5;

    cout << "Minimum swaps required: "
         << minimumSwaps(arr, n)
         << endl;

    return 0;
}
