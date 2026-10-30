#include <iostream>
#include <queue>

using namespace std;

class MyStack {

private:

    queue<int> q;

public:

    void push(int x) {

        int size = q.size();

        q.push(x);

        for (int i = 0; i < size; i++) {

            q.push(q.front());
            q.pop();
        }
    }

    int pop() {

        if (q.empty()) {
            return -1;
        }

        int value = q.front();
        q.pop();

        return value;
    }

    int top() {

        if (q.empty()) {
            return -1;
        }

        return q.front();
    }

    bool empty() {

        return q.empty();
    }
};

int main() {

    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: "
         << st.top()
         << endl;

    cout << "Popped: "
         << st.pop()
         << endl;

    cout << "Top after pop: "
         << st.top()
         << endl;

    cout << "Popped: "
         << st.pop()
         << endl;

    return 0;
}
