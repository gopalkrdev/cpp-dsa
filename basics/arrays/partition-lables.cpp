#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> partitionLabels(string s) {
    vector<int> last(26, 0);

    // Store last occurrence of every character
    for (int i = 0; i < s.length(); i++) {
        last[s[i] - 'a'] = i;
    }

    vector<int> result;

    int start = 0;
    int end = 0;

    for (int i = 0; i < s.length(); i++) {

        // Current character must stay in this partition
        end = max(end, last[s[i] - 'a']);

        // Partition complete
        if (i == end) {
            result.push_back(end - start + 1);
            start = i + 1;
        }
    }

    return result;
}

int main() {
    string s = "ababcbacadefegdehijhklij";

    vector<int> result = partitionLabels(s);

    cout << "Partition sizes: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}on
