#include <iostream>
#include <algorithm>
using namespace std;

int robLinear(int money[], int start, int end) {

    int prev2 = 0;
    int prev1 = 0;

    for (int i = start; i <= end; i++) {

        int current = max(
            prev1,
            prev2 + money[i]
        );

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int robCircle(int money[], int n) {

    if (n == 0)
        return 0;

    if (n == 1)
        return money[0];

    // Case 1: Exclude last house
    int case1 = robLinear(money, 0, n - 2);

    // Case 2: Exclude first house
    int case2 = robLinear(money, 1, n - 1);

    return max(case1, case2);
}

int main() {

    int money[] = {2, 3, 2};
    int n = 3;

    cout << "Maximum money: "
         << robCircle(money, n)
         << endl;

    return 0;
}
