#include<iostream>
using namespace std;
bool isPrime(int n, int divisor){
  if(n<2)
    return false;
 if (divisor * divisor > n)
        return true;

    if (n % divisor == 0)
        return false;

    return isPrime(n, divisor + 1);
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (isPrime(n, 2))
        cout << "Prime number";
    else
        cout << "Not a prime number";

    return 0;
}
