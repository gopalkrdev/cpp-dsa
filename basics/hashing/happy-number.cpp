#include <iostream>
#include <unordered_set>
using namespace std;

int sumOfSquares(int n) {

    int sum = 0;

    while (n > 0) {

        int digit = n % 10;

        sum += digit * digit;

        n /= 10;
    }

    return sum;
}

bool isHappy(int n) {

    unordered_set<int> seen;

    while (n != 1) {

        // Cycle detected
        if (seen.count(n)) {
            return false;
        }

        seen.insert(n);

        n = sumOfSquares(n);
    }

    return true;
}

int main() {

    int n = 19;

    if (isHappy(n)) {
        cout << n
             << " is a Happy Number"
             << endl;
    }
    else {
        cout << n
             << " is not a Happy Number"
             << endl;
    }

    return 0;
}
