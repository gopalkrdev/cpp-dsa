#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: "
         << st.top()
         << endl;

    cout << "Stack size: "
         << st.size()
         << endl;

    st.pop();

    cout << "After pop, top: "
         << st.top()
         << endl;

    if (st.empty()) {
        cout << "Stack is empty"
             << endl;
    }
    else {
        cout << "Stack is not empty"
             << endl;
    }

    st.pop();
    st.pop();

    if (st.empty()) {
        cout << "Stack is empty now"
             << endl;
    }

    return 0;
}
