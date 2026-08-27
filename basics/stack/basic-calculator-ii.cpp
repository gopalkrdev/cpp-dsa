#include <iostream>
#include <string>
#include <stack>
using namespace std;

int calculate(string s) {

    stack<int> st;

    int number = 0;
    char operation = '+';

    for (int i = 0; i < s.length(); i++) {

        char ch = s[i];

        if (isdigit(ch)) {

            number = number * 10
                   + (ch - '0');
        }

        if ((!isdigit(ch) && ch != ' ')
            || i == s.length() - 1) {

            if (operation == '+') {
                st.push(number);
            }

            else if (operation == '-') {
                st.push(-number);
            }

            else if (operation == '*') {

                int top = st.top();
                st.pop();

                st.push(top * number);
            }

            else if (operation == '/') {

                int top = st.top();
                st.pop();

                st.push(top / number);
            }

            operation = ch;
            number = 0;
        }
    }

    int answer = 0;

    while (!st.empty()) {

        answer += st.top();
        st.pop();
    }

    return answer;
}

int main() {

    string s = "3+2*2";

    cout << "Result: "
         << calculate(s)
         << endl;

    return 0;
}
