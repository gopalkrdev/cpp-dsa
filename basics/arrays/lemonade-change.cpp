#include <iostream>
using namespace std;

bool lemonadeChange(int bills[], int n) {
    int five = 0;
    int ten = 0;

    for (int i = 0; i < n; i++) {

        if (bills[i] == 5) {
            five++;
        }

        else if (bills[i] == 10) {
            if (five == 0) {
                return false;
            }

            five--;
            ten++;
        }

        else if (bills[i] == 20) {

            // Prefer one $10 + one $5
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            }

            // Otherwise use three $5
            else if (five >= 3) {
                five -= 3;
            }

            else {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int bills[] = {5, 5, 5, 10, 20};
    int n = 5;

    if (lemonadeChange(bills, n)) {
        cout << "Change can be given" << endl;
    }
    else {
        cout << "Change cannot be given" << endl;
    }

    return 0;
}
