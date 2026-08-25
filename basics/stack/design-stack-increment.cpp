#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CustomStack {

private:

    vector<int> st;
    int capacity;

public:

    CustomStack(int maxSize) {
        capacity = maxSize;
    }

    void push(int x) {

        if (st.size() < capacity) {
            st.push_back(x);
        }
    }

    int pop() {

        if (st.empty()) {
            return -1;
        }

        int value = st.back();

        st.pop_back();

        return value;
    }

    void increment(int k, int val) {

        int limit = min(k, (int)st.size());

        for (int i = 0; i < limit; i++) {
            st[i] += val;
        }
    }

    void display() {

        cout << "Stack: ";

        for (int x : st) {
            cout << x << " ";
        }

        cout << endl;
    }
};

int main() {

    CustomStack st(5);

    st.push(1);
    st.push(2);
    st.push(3);

    st.display();

    st.increment(2, 10);

    st.display();

    cout << "Popped: "
         << st.pop()
         << endl;

    st.display();

    return 0;
}
