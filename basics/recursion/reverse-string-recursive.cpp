#include <iostream>
#include <string>
using namespace std;

void reverseString(string &str, int left, int right) {
    if (left >= right)
        return;

    swap(str[left], str[right]);

    reverseString(str, left + 1, right - 1);
}

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    reverseString(str, 0, str.length() - 1);

    cout << "Reversed string = " << str;

    return 0;
}
