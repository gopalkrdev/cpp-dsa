#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    int weight;
    int value;
};

bool compare(Item a, Item b) {
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;

    return ratioA > ratioB;
}

double fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (auto item : items) {

        if (capacity == 0)
            break;

        if (item.weight <= capacity) {
            capacity -= item.weight;
            totalValue += item.value;
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
        {10, 60},
        {20, 100},
        {30, 120}
    };

    int capacity = 50;

    cout << fixed << setprecision(2);

    cout << "Maximum value: "
         << fractionalKnapsack(items, capacity)
         << endl;

    return 0;
}
