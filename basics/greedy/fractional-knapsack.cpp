#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

double fractionalKnapsack(
    int capacity,
    vector<Item>& items
) {
    // Sort by value/weight ratio
    sort(items.begin(), items.end(),
         [](Item a, Item b) {

             double ratioA =
                 (double)a.value / a.weight;

             double ratioB =
                 (double)b.value / b.weight;

             return ratioA > ratioB;
         });

    double totalValue = 0.0;

    for (Item item : items) {

        if (capacity == 0) {
            break;
        }

        // Complete item
        if (item.weight <= capacity) {

            capacity -= item.weight;
            totalValue += item.value;
        }

        // Fraction of item
        else {

            double fraction =
                (double)capacity / item.weight;

            totalValue +=
                item.value * fraction;

            capacity = 0;
        }
    }

    return totalValue;
}

int main() {

    int capacity = 50;

    vector<Item> items = {
        {10, 60},
        {20, 100},
        {30, 120}
    };

    double result =
        fractionalKnapsack(
            capacity,
            items
        );

    cout << "Maximum value: "
         << result << endl;

    return 0;
}
