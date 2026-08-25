#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Element {
    int value;
    int arrayIndex;
    int elementIndex;
};

struct Compare {
    bool operator()(Element a, Element b) {
        return a.value > b.value;
    }
};

vector<int> mergeKSortedArrays(
    vector<vector<int>>& arrays
) {
    priority_queue<
        Element,
        vector<Element>,
        Compare
    > minHeap;

    // First element of every array
    for (int i = 0; i < arrays.size(); i++) {

        if (!arrays[i].empty()) {

            minHeap.push({
                arrays[i][0],
                i,
                0
            });
        }
    }

    vector<int> result;

    while (!minHeap.empty()) {

        Element current = minHeap.top();
        minHeap.pop();

        result.push_back(current.value);

        int nextIndex =
            current.elementIndex + 1;

        // Add next element from same array
        if (nextIndex <
            arrays[current.arrayIndex].size()) {

            minHeap.push({
                arrays[current.arrayIndex][nextIndex],
                current.arrayIndex,
                nextIndex
            });
        }
    }

    return result;
}

int main() {

    vector<vector<int>> arrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    vector<int> result =
        mergeKSortedArrays(arrays);

    cout << "Merged Array: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
