#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

string simplifyPath(string path) {

    stack<string> st;

    stringstream ss(path);
    string part;

    while (getline(ss, part, '/')) {

        if (part.empty() || part == ".") {
            continue;
        }

        if (part == "..") {

            if (!st.empty()) {
                st.pop();
            }
        }

        else {
            st.push(part);
        }
    }

    if (st.empty()) {
        return "/";
    }

    string result = "";

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
