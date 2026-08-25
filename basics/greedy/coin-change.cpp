#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> coins = {
        10, 5, 2, 1
    };

    int amount = 18;

    int count = 0;

    cout << "Coins used: ";

    for (int coin : coins) {

        while (amount >= coin) {

            amount -= coin;

            cout << coin << " ";

            count++;
        }
    }

    cout << endl;

    cout << "Minimum coins: "
         << count << endl;

    return 0;
}
