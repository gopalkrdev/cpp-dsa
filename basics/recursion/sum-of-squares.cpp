#include<iostream>
using namespace std;
int sumOfSquares(int n) {
    if (n == 0)
        return 0;

    return n * n + sumOfSquares(n - 1);
}

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Sum of squares = " << sumOfSquares(n);

    return 0;
}
