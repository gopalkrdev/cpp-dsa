#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {

    stack<char> st;

    for (char ch : s) {

        // Opening brackets
        if (ch == '(' ||
            ch == '[' ||
            ch == '{') {

            st.push(ch);
        }

        // Closing bracket ')'
        else if (ch == ')') {

            if (st.empty() ||
                st.top() != '(') {
                return false;
            }

            st.pop();
        }

        // Closing bracket ']'
        else if (ch == ']') {

            if (st.empty() ||
                st.top() != '[') {
                return false;
            }

            st.pop();
        }

        // Closing bracket '}'
        else if (ch == '}') {

            if (st.empty() ||
                st.top() != '{') {
                return false;
            }

            st.pop();
        }
    }

    return st.empty();
}

int main() {

    string s = "{[()]}";

    if (isValid(s)) {
        cout << "Valid Parentheses" << endl;
    }
    else {
        cout << "Invalid Parentheses" << endl;
    }

    return 0;
}
