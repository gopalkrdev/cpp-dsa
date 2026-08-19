#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int candy(int ratings[], int n) {
    vector<int> candies(n, 1);

    // Left to right
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Right to left
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    int total = 0;

    for (int x : candies) {
        total += x;
    }

    return total;
}

int main() {
    int ratings[] = {1, 0, 2};
    int n = 3;

    cout << "Minimum candies required: "
         << candy(ratings, n)
         << endl;

    return 0;
}
