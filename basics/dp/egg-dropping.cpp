#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int eggDropping(int eggs, int floors) {

    // dp[e][f] = minimum attempts needed
    // with e eggs and f floors
    vector<vector<int>> dp(
        eggs + 1,
        vector<int>(floors + 1, 0)
    );

    // 0 floors -> 0 attempts
    // 1 floor  -> 1 attempt
    for (int e = 1; e <= eggs; e++) {
        dp[e][0] = 0;
        dp[e][1] = 1;
    }

    // With only 1 egg, we have to try
    // every floor from bottom to top
    for (int f = 1; f <= floors; f++) {
        dp[1][f] = f;
    }

    for (int e = 2; e <= eggs; e++) {

        for (int f = 2; f <= floors; f++) {

            dp[e][f] = INT_MAX;

            // Try dropping from every floor
            for (int x = 1; x <= f; x++) {

                // Egg breaks:
                // check floors below
                int eggBreaks = dp[e - 1][x - 1];

                // Egg doesn't break:
                // check floors above
                int eggSurvives = dp[e][f - x];

                int attempts =
                    1 + max(eggBreaks, eggSurvives);

                dp[e][f] =
                    min(dp[e][f], attempts);
            }
        }
    }

    return dp[eggs][floors];
}

int main() {

    int eggs = 2;
    int floors = 10;

    cout << "Minimum attempts: "
         << eggDropping(eggs, floors)
         << endl;

    return 0;
}
