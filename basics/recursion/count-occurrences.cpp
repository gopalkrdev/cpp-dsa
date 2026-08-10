#include<iostream>
using namespace std;
int countOccurrences(int n, int digit){
  if (n==0)
    return 0;
int count = (n % 10 == digit);

    return count + countOccurrences(n / 10, digit);
}

int main() {
    int n, digit;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Enter digit to count: ";
    cin >> digit;

    if (n < 0)
        n = -n;

    cout << "Occurrences = " << countOccurrences(n, digit);

    return 0;
}
