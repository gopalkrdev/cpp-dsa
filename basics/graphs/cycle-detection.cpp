#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node,
         int parent,
         vector<vector<int>>& graph,
         vector<bool>& visited) {

    visited[node] = true;

    for (int neighbour : graph[node]) {

        // If neighbour is not visited,
        // continue DFS
        if (!visited[neighbour]) {

            if (dfs(neighbour, node, graph, visited)) {
                return true;
            }
        }

        // Neighbour is already visited
        // and it is not the parent
        else if (neighbour != parent) {
            return true;
        }
    }

    return false;
}

bool hasCycle(vector<vector<int>>& graph) {

    int n = graph.size();

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {

            if (dfs(i, -1, graph, visited)) {
                return true;
            }
        }
    }

    return false;
}

int main() {

    int n = 5;

    vector<vector<int>> graph(n);

    // Cycle:
    // 0 -- 1
    // |    |
    // 2 -- 3
    //
    // 3 -- 4

    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[0].push_back(2);
    graph[2].push_back(0);

    graph[1].push_back(3);
    graph[3].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    graph[3].push_back(4);
    graph[4].push_back(3);

    if (hasCycle(graph)) {
        cout << "Cycle exists" << endl;
    }
    else {
        cout << "No cycle" << endl;
    }

    return 0;
}
