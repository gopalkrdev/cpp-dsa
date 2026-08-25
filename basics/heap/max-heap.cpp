#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {

private:

    vector<int> heap;

    // Move element upward
    void heapifyUp(int index) {

        while (index > 0) {

            int parent = (index - 1) / 2;

            if (heap[parent] >= heap[index]) {
                break;
            }

            swap(heap[parent], heap[index]);

            index = parent;
        }
    }

    // Move element downward
    void heapifyDown(int index) {

        int n = heap.size();

        while (true) {

            int left = 2 * index + 1;
            int right = 2 * index + 2;

            int largest = index;

            if (left < n &&
                heap[left] > heap[largest]) {

                largest = left;
            }

            if (right < n &&
                heap[right] > heap[largest]) {

                largest = right;
            }

            if (largest == index) {
                break;
            }

            swap(heap[index], heap[largest]);

            index = largest;
        }
    }

public:

    // Insert element
    void push(int value) {

        heap.push_back(value);

        heapifyUp(heap.size() - 1);
    }

    // Get maximum element
    int top() {

        if (heap.empty()) {
            cout << "Heap is empty\n";
            return -1;
        }

        return heap[0];
    }

    // Remove maximum element
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

    MaxHeap heap;

    heap.push(10);
    heap.push(30);
    heap.push(20);
    heap.push(50);
    heap.push(40);

    cout << "Max Heap elements:\n";

    while (!heap.empty()) {

        cout << heap.top() << " ";

        heap.pop();
    }

    cout << endl;

    return 0;
}
