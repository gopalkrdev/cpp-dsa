#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>

using namespace std;

string removeInvalidParentheses(string s) {

    stack<int> st;

    unordered_set<int> invalid;

    // Find invalid parentheses
    for (int i = 0; i < s.length(); i++) {

        if (s[i] == '(') {
            st.push(i);
        }

        else if (s[i] == ')') {

            if (!st.empty()) {
                st.pop();
            }
            else {
                // No matching '('
                invalid.insert(i);
            }
        }
    }

    // Remaining '(' are invalid
    while (!st.empty()) {

        invalid.insert(st.top());
        st.pop();
    }

    // Build result
    string result = "";

    for (int i = 0; i < s.length(); i++) {

        if (invalid.find(i) == invalid.end()) {
            result += s[i];
        }
    }

    return result;
}

int main() {

    string s = "lee(t(c)o)de)";

    cout << "Valid string: "
         << removeInvalidParentheses(s)
         << endl;

    return 0;
}
