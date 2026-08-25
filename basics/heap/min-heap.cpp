#include <iostream>
#include <vector>
using namespace std;

class MinHeap {

private:

    vector<int> heap;

    void heapifyUp(int index) {

        while (index > 0) {

            int parent = (index - 1) / 2;

            if (heap[parent] <= heap[index]) {
                break;
            }

            swap(heap[parent], heap[index]);

            index = parent;
        }
    }

    void heapifyDown(int index) {

        int n = heap.size();

        while (true) {

            int left = 2 * index + 1;
            int right = 2 * index + 2;

            int smallest = index;

            if (left < n &&
                heap[left] < heap[smallest]) {

                smallest = left;
            }

            if (right < n &&
                heap[right] < heap[smallest]) {

                smallest = right;
            }

            if (smallest == index) {
                break;
            }

            swap(heap[index], heap[smallest]);

            index = smallest;
        }
    }

public:

    void push(int value) {

        heap.push_back(value);

        heapifyUp(heap.size() - 1);
    }

    int top() {

        if (heap.empty()) {
            cout << "Heap is empty\n";
            return -1;
        }

        return heap[0];
    }

    void pop() {

        if (heap.empty()) {
            return;
        }

        heap[0] = heap.back();

        heap.pop_back();

        if (!heap.empty()) {
            heapifyDown(0);
        }
    }

    bool empty() {
        return heap.empty();
    }
};

int main() {

    MinHeap heap;

    heap.push(40);
    heap.push(10);
    heap.push(30);
    heap.push(20);
    heap.push(50);

    cout << "Min Heap elements:\n";

    while (!heap.empty()) {

        cout << heap.top() << " ";

        heap.pop();
    }

    cout << endl;

    return 0;
}
