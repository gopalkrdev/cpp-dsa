#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>>& graph) {

    int n = graph.size();

    vector<bool> visited(n, false);

    queue<int> q;

    // Start node
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        cout << node << " ";

        // Visit neighbours
        for (int neighbour : graph[node]) {

            if (!visited[neighbour]) {

                visited[neighbour] = true;
                q.push(neighbour);
            }
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

    cout << "BFS Traversal: ";

    bfs(0, graph);

    cout << endl;

    return 0;
}
