#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

string simplifyPath(string path) {

    stack<string> st;

    stringstream ss(path);
    string part;

    // Split path using '/'
    while (getline(ss, part, '/')) {

        // Ignore empty part and "."
        if (part.empty() || part == ".") {
            continue;
        }

        // Go one directory back
        if (part == "..") {

            if (!st.empty()) {
                st.pop();
            }
        }

        // Normal directory
        else {
            st.push(part);
        }
    }

    // If stack is empty
    if (st.empty()) {
        return "/";
    }

    string result = "";

    // Stack ko reverse order me access karna hoga
    stack<string> temp;

    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    while (!temp.empty()) {

        result += "/";
        result += temp.top();

        temp.pop();
    }

    return result;
}

int main() {

    string path = "/home/user/../documents/";

    cout << "Simplified Path: "
         << simplifyPath(path)
         << endl;

    return 0;
}
