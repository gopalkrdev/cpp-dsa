#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rodCutting(int price[], int n, int length) {

    vector<int> dp(length + 1, 0);

    for (int len = 1; len <= length; len++) {

        for (int cut = 1; cut <= len && cut <= n; cut++) {

            dp[len] = max(
                dp[len],
                price[cut - 1] + dp[len - cut]
            );
        }
    }

    return dp[length];
}

int main() {

    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;

    int length = 8;

    cout << "Maximum profit: "
         << rodCutting(price, n, length)
         << endl;

    return 0;
}
