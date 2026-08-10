#include<iostream>
using namespace std;
long long power (int base, int exponent){
  if (exponent==0)
    return 1;
long long half=power (base, ecponent/2);
if (exponent % 2 == 0)
        return half * half;
    else
        return base * half * half;
}

int main() {
    int base, exponent;

    cout << "Enter base: ";
    cin >> base;

    cout << "Enter exponent: ";
    cin >> exponent;

    cout << "Result = " << power(base, exponent);

    return 0;
}
