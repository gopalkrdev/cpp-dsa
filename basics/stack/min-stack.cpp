#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {

private:
    stack<int> st;
    stack<int> minSt;

public:

    void push(int x) {

        st.push(x);

        if (minSt.empty()) {
            minSt.push(x);
        }
        else {
            minSt.push(
                min(x, minSt.top())
            );
        }
    }

    void pop() {

        if (st.empty()) {
            return;
        }

        st.pop();
        minSt.pop();
    }

    int top() {

        if (st.empty()) {
            return INT_MIN;
        }

        return st.top();
    }

    int getMin() {

        if (minSt.empty()) {
            return INT_MIN;
        }

        return minSt.top();
    }
};

int main() {

    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "Top: "
         << st.top()
         << endl;

    cout << "Minimum: "
         << st.getMin()
         << endl;

    st.pop();

    cout << "After pop:" << endl;

    cout << "Top: "
         << st.top()
         << endl;

    cout << "Minimum: "
         << st.getMin()
         << endl;

    return 0;
}
