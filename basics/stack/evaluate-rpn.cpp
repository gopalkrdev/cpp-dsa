#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int evalRPN(vector<string>& tokens) {

    stack<int> st;

    for (string token : tokens) {

        // Number
        if (token != "+" &&
            token != "-" &&
            token != "*" &&
            token != "/") {

            st.push(stoi(token));
        }

        // Operator
        else {

            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            int result;

            if (token == "+") {
                result = a + b;
            }
            else if (token == "-") {
                result = a - b;
            }
            else if (token == "*") {
                result = a * b;
            }
            else {
                result = a / b;
            }

            st.push(result);
        }
    }

    return st.top();
}

int main() {

    vector<string> tokens = {
        "2", "1", "+", "3", "*"
    };

    cout << "Result: "
         << evalRPN(tokens)
         << endl;

    return 0;
}
