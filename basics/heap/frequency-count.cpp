#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {

    vector<int> nums = {
        1, 2, 1, 3, 2, 1, 4
    };

    unordered_map<int, int> freq;

    // Count frequency
    for (int x : nums) {
        freq[x]++;
    }

    // Print frequency
    cout << "Frequency:\n";

    for (auto entry : freq) {

        cout << entry.first
             << " -> "
             << entry.second
             << endl;
    }

    return 0;
}
