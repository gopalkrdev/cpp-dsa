#include <iostream>
using namespace std;

int sumDigits(int n) {
    if (n < 10)
        return n;

    return (n % 10) + sumDigits(n / 10);
}

int singleDigitSum(int n) {
    if (n < 10)
        return n;

    return singleDigitSum(sumDigits(n));
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (n < 0)
        n = -n;

    cout << "Single digit sum = " << singleDigitSum(n);

    return 0;
}
