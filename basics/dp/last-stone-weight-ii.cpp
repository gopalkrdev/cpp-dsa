#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int lastStoneWeightII(int stones[], int n) {

    int totalSum = 0;

    for (int i = 0; i < n; i++) {
        totalSum += stones[i];
    }

    int target = totalSum / 2;

    // dp[s] = kya sum s banana possible hai?
    vector<bool> dp(target + 1, false);

    dp[0] = true;

    for (int i = 0; i < n; i++) {

        for (int s = target; s >= stones[i]; s--) {

            dp[s] = dp[s] ||
                    dp[s - stones[i]];
        }
    }

    // Sabse bada possible subset sum <= total/2
    int best = 0;

    for (int s = target; s >= 0; s--) {

        if (dp[s]) {
            best = s;
            break;
        }
    }

    // Difference between two groups
    return totalSum - 2 * best;
}

int main() {

    int stones[] = {2, 7, 4, 1, 8, 1};
    int n = 6;

    cout << "Minimum remaining weight: "
         << lastStoneWeightII(stones, n)
         << endl;

    return 0;
}
