#include <iostream>
using namespace std;

int squareRoot(int n) {
    int low = 0;
    int high = n;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid <= n / mid) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n = 36;

    cout << "Square root: " << squareRoot(n) << endl;

    return 0;
}
