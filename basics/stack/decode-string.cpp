#include <iostream>
#include <string>
#include <stack>
using namespace std;

string decodeString(string s) {

    stack<int> countStack;
    stack<string> stringStack;

    string current = "";
    int number = 0;

    for (char ch : s) {

        // If character is a digit
        if (isdigit(ch)) {

            number = number * 10
                    + (ch - '0');
        }

        // Opening bracket
        else if (ch == '[') {

            countStack.push(number);
            stringStack.push(current);

            number = 0;
            current = "";
        }

        // Closing bracket
        else if (ch == ']') {

            int repeat = countStack.top();
            countStack.pop();

            string previous =
                stringStack.top();
            stringStack.pop();

            string temp = "";

            for (int i = 0; i < repeat; i++) {
                temp += current;
            }

            current = previous + temp;
        }

        // Normal character
        else {

            current += ch;
        }
    }

    return current;
}

int main() {

    string s = "3[a2[c]]";

    cout << "Decoded string: "
         << decodeString(s)
         << endl;

    return 0;
}
