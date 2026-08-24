#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
};

class DSU {

private:
    vector<int> parent;
    vector<int> rank;

public:

    DSU(int n) {

        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {

        if (parent[x] == x) {
            return x;
        }

        // Path compression
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {

        int rootA = find(a);
        int rootB = find(b);

        // Same component = cycle
        if (rootA == rootB) {
            return false;
        }

        // Union by rank
        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        }
        else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        }
        else {

            parent[rootB] = rootA;
            rank[rootA]++;
        }

        return true;
    }
};

int kruskalMST(int n, vector<Edge>& edges) {

    // Sort edges by weight
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.weight < b.weight;
         });

    DSU dsu(n);

    int totalWeight = 0;
    int edgesUsed = 0;

    for (Edge edge : edges) {

        // Add edge only if it doesn't form cycle
        if (dsu.unite(edge.u, edge.v)) {

            totalWeight += edge.weight;
            edgesUsed++;

            cout << edge.u << " -- "
                 << edge.v << " = "
                 << edge.weight << endl;

            // MST needs exactly n-1 edges
            if (edgesUsed == n - 1) {
                break;
            }
        }
    }

    return totalWeight;
}

int main() {

    int n = 5;

    vector<Edge> edges = {

        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    int result = kruskalMST(n, edges);

    cout << "Minimum Spanning Tree weight: "
         << result << endl;

    return 0;
}
