#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int primMST(vector<vector<pair<int, int>>>& graph) {

    int n = graph.size();

    vector<bool> inMST(n, false);

    // {weight, node}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    // Start from node 0
    pq.push({0, 0});

    int totalWeight = 0;

    while (!pq.empty()) {

        int weight = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        // Already included
        if (inMST[node]) {
            continue;
        }

        // Include node in MST
        inMST[node] = true;

        totalWeight += weight;

        // Add neighbouring edges
        for (auto edge : graph[node]) {

            int neighbour = edge.first;
            int edgeWeight = edge.second;

            if (!inMST[neighbour]) {

                pq.push({
                    edgeWeight,
                    neighbour
                });
            }
        }
    }

    return totalWeight;
}

int main() {

    int n = 5;

    vector<vector<pair<int, int>>> graph(n);

    // {neighbour, weight}

    graph[0].push_back({1, 2});
    graph[1].push_back({0, 2});

    graph[0].push_back({3, 6});
    graph[3].push_back({0, 6});

    graph[1].push_back({2, 3});
    graph[2].push_back({1, 3});

    graph[1].push_back({3, 8});
    graph[3].push_back({1, 8});

    graph[1].push_back({4, 5});
    graph[4].push_back({1, 5});

    graph[2].push_back({4, 7});
    graph[4].push_back({2, 7});

    graph[3].push_back({4, 9});
    graph[4].push_back({3, 9});

    int result = primMST(graph);

    cout << "Minimum Spanning Tree weight: "
         << result << endl;

    return 0;
}
