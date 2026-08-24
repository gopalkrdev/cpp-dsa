#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(
    int source,
    vector<vector<pair<int, int>>>& graph
) {
    int n = graph.size();

    // Initially all distances are infinity
    vector<int> distance(n, INT_MAX);

    // {distance, node}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    distance[source] = 0;

    pq.push({0, source});

    while (!pq.empty()) {

        int currentDistance = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        // Ignore outdated entry
        if (currentDistance != distance[node]) {
            continue;
        }

        for (auto edge : graph[node]) {

            int neighbour = edge.first;
            int weight = edge.second;

            int newDistance =
                currentDistance + weight;

            // Better path found
            if (newDistance < distance[neighbour]) {

                distance[neighbour] = newDistance;

                pq.push({
                    newDistance,
                    neighbour
                });
            }
        }
    }

    return distance;
}

int main() {

    int n = 5;

    vector<vector<pair<int, int>>> graph(n);

    // {neighbour, weight}

    graph[0].push_back({1, 4});
    graph[1].push_back({0, 4});

    graph[0].push_back({2, 1});
    graph[2].push_back({0, 1});

    graph[2].push_back({1, 2});
    graph[1].push_back({2, 2});

    graph[1].push_back({3, 1});
    graph[3].push_back({1, 1});

    graph[2].push_back({3, 5});
    graph[3].push_back({2, 5});

    graph[3].push_back({4, 3});
    graph[4].push_back({3, 3});

    int source = 0;

    vector<int> distance =
        dijkstra(source, graph);

    cout << "Shortest distances from "
         << source << ":" << endl;

    for (int i = 0; i < n; i++) {

        cout << "Node " << i
             << " = " << distance[i]
             << endl;
    }

    return 0;
}
