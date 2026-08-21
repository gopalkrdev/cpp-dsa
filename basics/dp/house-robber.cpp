#include <iostream>
#include <algorithm>
using namespace std;

int rob(int money[], int n) {

    if (n == 0)
        return 0;

    if (n == 1)
        return money[0];

    int prev2 = 0;
    int prev1 = money[0];

    for (int i = 1; i < n; i++) {

        // Either rob current house or skip it
        int current = max(prev1, prev2 + money[i]);

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main() {

    int money[] = {2, 7, 9, 3, 1};
    int n = 5;

    cout << "Maximum money: "
         << rob(money, n)
         << endl;

    return 0;
}
