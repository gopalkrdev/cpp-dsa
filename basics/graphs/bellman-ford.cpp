#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
};

vector<int> bellmanFord(
    int n,
    int source,
    vector<Edge>& edges
) {
    vector<int> distance(n, INT_MAX);

    distance[source] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= n - 1; i++) {

        bool changed = false;

        for (Edge edge : edges) {

            if (distance[edge.u] == INT_MAX) {
                continue;
            }

            if (distance[edge.u] + edge.weight
                < distance[edge.v]) {

                distance[edge.v] =
                    distance[edge.u] + edge.weight;

                changed = true;
            }
        }

        // No update means answer is already stable
        if (!changed) {
            break;
        }
    }

    // Check for negative cycle
    for (Edge edge : edges) {

        if (distance[edge.u] == INT_MAX) {
            continue;
        }

        if (distance[edge.u] + edge.weight
            < distance[edge.v]) {

            cout << "Negative cycle exists!"
                 << endl;

            return {};
        }
    }

    return distance;
}

int main() {

    int n = 5;

    vector<Edge> edges = {

        {0, 1, 4},
        {0, 2, 5},
        {1, 2, -2},
        {1, 3, 6},
        {2, 3, 3},
        {3, 4, 2}
    };

    int source = 0;

    vector<int> distance =
        bellmanFord(n, source, edges);

    if (!distance.empty()) {

        cout << "Shortest distances from "
             << source << ":" << endl;

        for (int i = 0; i < n; i++) {

            cout << "Node " << i
                 << " = " << distance[i]
                 << endl;
        }
    }

    return 0;
}
