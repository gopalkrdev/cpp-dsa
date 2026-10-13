#include <iostream>
#include <vector>
using namespace std;

int timer = 0;

void dfs(
    int node,
    int parent,
    vector<vector<int>>& graph,
    vector<bool>& visited,
    vector<int>& tin,
    vector<int>& low,
    vector<bool>& isArticulation
) {
    visited[node] = true;

    tin[node] = low[node] = timer++;

    int children = 0;

    for (int neighbour : graph[node]) {

        if (neighbour == parent) {
            continue;
        }

        if (visited[neighbour]) {

            low[node] =
                min(low[node], tin[neighbour]);
        }

        else {

            dfs(
                neighbour,
                node,
                graph,
                visited,
                tin,
                low,
                isArticulation
            );

            low[node] =
                min(low[node], low[neighbour]);

            if (parent != -1 &&
                low[neighbour] >= tin[node]) {

                isArticulation[node] = true;
            }

            children++;
        }
    }

    if (parent == -1 && children > 1) {
        isArticulation[node] = true;
    }
}

int main() {

    int n = 5;

    vector<vector<int>> graph(n);

   

    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[1].push_back(3);
    graph[3].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    graph[3].push_back(4);
    graph[4].push_back(3);

    vector<bool> visited(n, false);
    vector<int> tin(n, -1);
    vector<int> low(n, -1);

    vector<bool> isArticulation(n, false);

    for (int i = 0; i < n; i++) {

        if (!visited[i]) {

            dfs(
                i,
                -1,
                graph,
                visited,
                tin,
                low,
                isArticulation
            );
        }
    }

    cout << "Articulation Points:" << endl;

    for (int i = 0; i < n; i++) {

        if (isArticulation[i]) {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}
