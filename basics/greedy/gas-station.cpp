#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(
    vector<int>& gas,
    vector<int>& cost
) {
    int totalGas = 0;
    int totalCost = 0;

    int tank = 0;
    int start = 0;

    for (int i = 0; i < gas.size(); i++) {

        totalGas += gas[i];
        totalCost += cost[i];

        tank += gas[i] - cost[i];

        // Current start cannot work
        if (tank < 0) {

            start = i + 1;
            tank = 0;
        }
    }

    // Impossible to complete circuit
    if (totalGas < totalCost) {
        return -1;
    }

    return start;
}

int main() {

    vector<int> gas = {
        1, 2, 3, 4, 5
    };

    vector<int> cost = {
        3, 4, 5, 1, 2
    };

    int result =
        canCompleteCircuit(
            gas,
            cost
        );

    if (result == -1) {
        cout << "Circuit cannot be completed"
             << endl;
    }
    else {
        cout << "Starting station: "
             << result
             << endl;
    }

    return 0;
}
