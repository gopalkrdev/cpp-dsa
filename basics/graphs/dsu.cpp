#include <iostream>
#include <vector>
using namespace std;

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

    void unite(int a, int b) {

        int rootA = find(a);
        int rootB = find(b);

        // Already same group
        if (rootA == rootB) {
            return;
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
    }
};

int main() {

    DSU dsu(5);

    dsu.unite(0, 1);
    dsu.unite(1, 2);

    dsu.unite(3, 4);

    cout << "Root of 0: "
         << dsu.find(0) << endl;

    cout << "Root of 2: "
         << dsu.find(2) << endl;

    cout << "Root of 3: "
         << dsu.find(3) << endl;

    cout << "Root of 4: "
         << dsu.find(4) << endl;

    if (dsu.find(0) == dsu.find(2)) {
        cout << "0 and 2 are connected" << endl;
    }

    if (dsu.find(0) != dsu.find(3)) {
        cout << "0 and 3 are not connected" << endl;
    }

    return 0;
}
