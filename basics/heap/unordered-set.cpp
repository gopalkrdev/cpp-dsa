#include <iostream>
#include <unordered_set>
using namespace std;

int main() {

    unordered_set<int> st;

    // Insert
    st.insert(10);
    st.insert(20);
    st.insert(30);

    // Duplicate
    st.insert(20);

    cout << "Size: "
         << st.size()
         << endl;

    // Search
    if (st.find(20) != st.end()) {
        cout << "20 found"
             << endl;
    }

    // Search using count
    if (st.count(30)) {
        cout << "30 exists"
             << endl;
    }

    // Delete
    st.erase(10);

    cout << "After deletion:\n";

    for (int x : st) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
