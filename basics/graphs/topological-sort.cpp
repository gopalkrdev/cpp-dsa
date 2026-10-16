#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologicalSort(
    int n,
    vector<vector<int>>& graph
) {

    vector<int> indegree(n, 0);

    for (int i = 0; i < n; i++) {

        for (int neighbour : graph[i]) {
            indegree[neighbour]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {

        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        result.push_back(node);

        for (int neighbour : graph[node]) {

            indegree[neighbour]--;

            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    if (result.size() != n) {
        return {};
    }

    return result;
}

int main() {

    int n = 6;

    vector<vector<int>> graph(n);

    graph[5].push_back(2);
    graph[5].push_back(0);

    graph[4].push_back(0);
    graph[4].push_back(1);

    graph[2].push_back(3);

    graph[3].push_back(1);

    vector<int> result =
        topologicalSort(n, graph);

    if (result.empty()) {

        cout << "Cycle exists. "
             << "Topological sort not possible."
             << endl;
    }
    else {

        cout << "Topological Order: ";

        for (int node : result) {
            cout << node << " ";
        }

        cout << endl;
    }

    return 0;
}
