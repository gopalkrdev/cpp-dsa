#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    int value;
    int weight;
};

double fractionalKnapsack(vector<Item>& items, int capacity) {

    sort(items.begin(), items.end(),
         [](Item a, Item b) {
             return (double)a.value / a.weight >
                    (double)b.value / b.weight;
         });

    double totalValue = 0.0;

    for (Item item : items) {

        if (capacity == 0) {
            break;
        }

        if (item.weight <= capacity) {
            totalValue += item.value;
            capacity -= item.weight;
        }

        else {
            double fraction =
                (double)capacity / item.weight;

            totalValue += item.value * fraction;

            capacity = 0;
        }
    }

    return totalValue;
}

int main() {

    vector<Item> items = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    int capacity = 50;

    cout << fixed << setprecision(2);

    cout << "Maximum value: "
         << fractionalKnapsack(items, capacity)
         << endl;

    return 0;
}
