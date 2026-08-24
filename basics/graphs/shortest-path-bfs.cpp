#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> shortestPath(
    int source,
    vector<vector<int>>& graph
) {
    int n = graph.size();

    vector<int> distance(n, -1);

    queue<int> q;

    distance[source] = 0;
    q.push(source);

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        for (int neighbour : graph[node]) {

            // First time we reach a node
            if (distance[neighbour] == -1) {

                distance[neighbour] =
                    distance[node] + 1;

                q.push(neighbour);
            }
        }
    }

    return distance;
}

int main() {

    int n = 5;

    vector<vector<int>> graph(n);

    // 0 -- 1
    // |    |
    // 3 -- 2 -- 4

    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[0].push_back(3);
    graph[3].push_back(0);

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    graph[2].push_back(4);
    graph[4].push_back(2);

    int source = 0;

    vector<int> distance =
        shortestPath(source, graph);

    cout << "Shortest distances from "
         << source << ":" << endl;

    for (int i = 0; i < n; i++) {

        cout << "Node " << i
             << " = " << distance[i]
             << endl;
    }

    return 0;
}
