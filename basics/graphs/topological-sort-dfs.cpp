#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node,
         vector<vector<int>>& graph,
         vector<bool>& visited,
         stack<int>& st) {

    visited[node] = true;

    for (int neighbour : graph[node]) {

        if (!visited[neighbour]) {
            dfs(neighbour, graph, visited, st);
        }
    }

    // Node ko tab push karo
    // jab uske saare neighbours process ho jayein
    st.push(node);
}

vector<int> topologicalSort(
    int n,
    vector<vector<int>>& graph
) {

    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {
            dfs(i, graph, visited, st);
        }
    }

    vector<int> result;

    while (!st.empty()) {

        result.push_back(st.top());
        st.pop();
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

    cout << "Topological Order: ";

    for (int node : result) {
        cout << node << " ";
    }

    cout << endl;

    return 0;
}
