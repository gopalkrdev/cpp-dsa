#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {

    // Max Heap
    priority_queue<int> maxHeap;

    maxHeap.push(5);
    maxHeap.push(2);
    maxHeap.push(9);
    maxHeap.push(1);

    cout << "Max Heap:\n";

    while (!maxHeap.empty()) {

        cout << maxHeap.top() << " ";

        maxHeap.pop();
    }

    cout << endl;


    // Min Heap
    priority_queue<
        int,
        vector<int>,
        greater<int>
    > minHeap;

    minHeap.push(5);
    minHeap.push(2);
    minHeap.push(9);
    minHeap.push(1);

    cout << "Min Heap:\n";

    while (!minHeap.empty()) {

        cout << minHeap.top() << " ";

        minHeap.pop();
    }

    cout << endl;

    return 0;
}
