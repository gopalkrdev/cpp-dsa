#include <iostream>
using namespace std;

int countZeros(int n) {
    if (n == 0)
        return 1;

    if (n < 10)
        return 0;

    return (n % 10 == 0) + countZeros(n / 10);
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (n < 0)
        n = -n;

    cout << "Number of zeros = " << countZeros(n);

    return 0;
}
