#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

string alienOrder(vector<string>& words) {

    vector<vector<int>> graph(26);

    vector<int> indegree(26, 0);
    vector<bool> present(26, false);

    // Mark characters that exist
    for (string word : words) {

        for (char ch : word) {
            present[ch - 'a'] = true;
        }
    }

    // Build graph
    for (int i = 0; i < words.size() - 1; i++) {

        string a = words[i];
        string b = words[i + 1];

        int len = min(a.size(), b.size());

        bool found = false;

        for (int j = 0; j < len; j++) {

            if (a[j] != b[j]) {

                int u = a[j] - 'a';
                int v = b[j] - 'a';

                graph[u].push_back(v);
                indegree[v]++;

                found = true;
                break;
            }
        }

        // Invalid case:
        // "abc" comes before "ab"
        if (!found && a.size() > b.size()) {
            return "";
        }
    }

    queue<int> q;

    for (int i = 0; i < 26; i++) {

        if (present[i] && indegree[i] == 0) {
            q.push(i);
        }
    }

    string order;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        order += char(node + 'a');

        for (int neighbour : graph[node]) {

            indegree[neighbour]--;

            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    // Cycle exists
    if (order.size() !=
        count(present.begin(), present.end(), true)) {

        return "";
    }

    return order;
}

int main() {

    vector<string> words = {
        "wrt",
        "wrf",
        "er",
        "ett",
        "rftt"
    };

    string result = alienOrder(words);

    if (result.empty()) {

        cout << "Invalid ordering" << endl;
    }
    else {

        cout << "Alien Dictionary Order: "
             << result << endl;
    }

    return 0;
}
