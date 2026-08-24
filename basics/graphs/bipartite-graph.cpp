#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {

    int n = graph.size();

    // -1 = not colored
    //  0 = color 0
    //  1 = color 1
    vector<int> color(n, -1);

    for (int start = 0; start < n; start++) {

        // Handle disconnected graph
        if (color[start] != -1) {
            continue;
        }

        queue<int> q;

        color[start] = 0;
        q.push(start);

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int neighbour : graph[node]) {

                // Not colored yet
                if (color[neighbour] == -1) {

                    // Give opposite color
                    color[neighbour] =
                        1 - color[node];

                    q.push(neighbour);
                }

                // Same color on both ends
                else if (color[neighbour] == color[node]) {

                    return false;
                }
            }
        }
    }

    return true;
}

int main() {

    int n = 4;

    vector<vector<int>> graph(n);

    // 0 -- 1
    // |    |
    // 3 -- 2

    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    graph[3].push_back(0);
    graph[0].push_back(3);

    if (isBipartite(graph)) {
        cout << "Graph is Bipartite" << endl;
    }
    else {
        cout << "Graph is NOT Bipartite" << endl;
    }

    return 0;
}
