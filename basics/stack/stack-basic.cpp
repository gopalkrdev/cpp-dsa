#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack<int> st;

    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: "
         << st.top()
         << endl;

    cout << "Stack size: "
         << st.size()
         << endl;

    // Remove top
    st.pop();

    cout << "After pop, top: "
         << st.top()
         << endl;

    // Check empty
    if (st.empty()) {
        cout << "Stack is empty"
             << endl;
    }
    else {
        cout << "Stack is not empty"
             << endl;
    }

    // Remove remaining elements
    st.pop();
    st.pop();

    if (st.empty()) {
        cout << "Stack is empty now"
             << endl;
    }

    return 0;
}
