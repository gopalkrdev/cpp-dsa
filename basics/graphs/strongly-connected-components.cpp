#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs1(
    int node,
    vector<vector<int>>& graph,
    vector<bool>& visited,
    stack<int>& st
) {
    visited[node] = true;

    for (int neighbour : graph[node]) {
        if (!visited[neighbour]) {
            dfs1(neighbour, graph, visited, st);
        }
    }

    st.push(node);
}

void dfs2(
    int node,
    vector<vector<int>>& reversedGraph,
    vector<bool>& visited
) {
    visited[node] = true;

    cout << node << " ";

    for (int neighbour : reversedGraph[node]) {
        if (!visited[neighbour]) {
            dfs2(neighbour, reversedGraph, visited);
        }
    }
}

int main() {

    int n = 5;

    vector<vector<int>> graph(n);
    vector<vector<int>> reversedGraph(n);

    // Directed graph
    graph[0].push_back(1);
    graph[1].push_back(2);
    graph[2].push_back(0);

    graph[1].push_back(3);
    graph[3].push_back(4);
    graph[4].push_back(3);

    // Create reversed graph
    for (int u = 0; u < n; u++) {

        for (int v : graph[u]) {
            reversedGraph[v].push_back(u);
        }
    }

    // Step 1: DFS and store finish order
    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {
            dfs1(i, graph, visited, st);
        }
    }

    // Step 2: Reset visited
    fill(visited.begin(), visited.end(), false);

    // Step 3: DFS on reversed graph
    cout << "Strongly Connected Components:\n";

    while (!st.empty()) {

        int node = st.top();
        st.pop();

        if (!visited[node]) {

            dfs2(
                node,
                reversedGraph,
                visited
            );

            cout << endl;
        }
    }

    return 0;
}
