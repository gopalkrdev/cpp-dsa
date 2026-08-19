#include <iostream>
using namespace std;

int canCompleteCircuit(int gas[], int cost[], int n) {
    int totalGas = 0;
    int totalCost = 0;

    int currentGas = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        totalGas += gas[i];
        totalCost += cost[i];

        currentGas += gas[i] - cost[i];

        // Current starting point cannot work
        if (currentGas < 0) {
            start = i + 1;
            currentGas = 0;
        }
    }

    // Total gas is less than total cost
    if (totalGas < totalCost) {
        return -1;
    }

    return start;
}

int main() {
    int gas[] = {1, 2, 3, 4, 5};
    int cost[] = {3, 4, 5, 1, 2};

    int n = 5;

    int result = canCompleteCircuit(gas, cost, n);

    if (result == -1) {
        cout << "Cannot complete the circuit" << endl;
    } else {
        cout << "Starting station: " << result << endl;
    }

    return 0;
}
