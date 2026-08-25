#include <iostream>
#include <stack>

using namespace std;

class MyQueue {

private:

    stack<int> inputStack;
    stack<int> outputStack;

    void transfer() {

        while (!inputStack.empty()) {

            outputStack.push(inputStack.top());
            inputStack.pop();
        }
    }

public:

    // Add element
    void push(int x) {

        inputStack.push(x);
    }

    // Remove front element
    int pop() {

        if (outputStack.empty()) {
            transfer();
        }

        if (outputStack.empty()) {
            return -1;
        }

        int value = outputStack.top();

        outputStack.pop();

        return value;
    }

    // Return front element
    int front() {

        if (outputStack.empty()) {
            transfer();
        }

        if (outputStack.empty()) {
            return -1;
        }

        return outputStack.top();
    }

    // Check empty
    bool empty() {

        return inputStack.empty()
            && outputStack.empty();
    }
};

int main() {

    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: "
         << q.front()
         << endl;

    cout << "Popped: "
         << q.pop()
         << endl;

    cout << "Front after pop: "
         << q.front()
         << endl;

    cout << "Popped: "
         << q.pop()
         << endl;

    cout << "Popped: "
         << q.pop()
         << endl;

    return 0;
}
