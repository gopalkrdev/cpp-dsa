#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph,
         vector<bool>& visited) {

    // Mark current node visited
    visited[node] = true;

    cout << node << " ";

    // Visit all neighbours
    for (int neighbour : graph[node]) {

        if (!visited[neighbour]) {
            dfs(neighbour, graph, visited);
        }
    }
}

int main() {

    int n = 5;

    vector<vector<int>> graph(n);

    // Edges
    graph[0].push_back(1);
    graph[0].push_back(2);

    graph[1].push_back(0);
    graph[1].push_back(3);
    graph[1].push_back(4);

    graph[2].push_back(0);

    graph[3].push_back(1);

    graph[4].push_back(1);

    vector<bool> visited(n, false);

    cout << "DFS Traversal: ";

    dfs(0, graph, visited);

    cout << endl;

    return 0;
}
