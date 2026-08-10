#include <iostream>
#include <string>
using namespace std;

int stringLength(string str, int index) {
    if (index == str.length())
        return 0;

    return 1 + stringLength(str, index + 1);
}

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Length of string = " << stringLength(str, 0);

    return 0;
}
