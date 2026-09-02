#include <iostream>
#include <vector>
using namespace std;

void dfs(int node,
         vector<vector<int>>& graph,
         vector<bool>& visited) {

    visited[node] = true;

    for (int neighbour : graph[node]) {

        if (!visited[neighbour]) {
            dfs(neighbour, graph, visited);
        }
    }
}

int countComponents(vector<vector<int>>& graph) {

    int n = graph.size();

    vector<bool> visited(n, false);

    int components = 0;

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {

            components++;

            dfs(i, graph, visited);
        }
    }

    return components;
}

int main() {

    int n = 5;

    vector<vector<int>> graph(n);

    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[3].push_back(4);
    graph[4].push_back(3);

    cout << "Number of connected components: "
         << countComponents(graph)
         << endl;

    return 0;
}
