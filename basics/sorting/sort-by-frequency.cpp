#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }

    return a.second > b.second;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<int, int> frequency;

    for (int x : arr) {
        frequency[x]++;
    }

    vector<pair<int, int>> elements;

    for (auto item : frequency) {
        elements.push_back(item);
    }

    sort(elements.begin(), elements.end(), compare);

    cout << "Sorted by frequency: ";

    for (auto item : elements) {
        for (int i = 0; i < item.second; i++) {
            cout << item.first << " ";
        }
    }

    cout << endl;

    return 0;
}
