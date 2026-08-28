#include <iostream>
#include <string>

using namespace std;

int minAddToMakeValid(string s) {

    int open = 0;
    int answer = 0;

    for (char ch : s) {

        if (ch == '(') {
            open++;
        }
        else {

            if (open > 0) {
                open--;
            }
            else {

                answer++;
            }
        }
    }

    answer += open;

    return answer;
}

int main() {

    string s = "())";

    cout << "Minimum additions: "
         << minAddToMakeValid(s)
         << endl;

    return 0;
}
