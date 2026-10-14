#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n = 5;

    vector<vector<int>> graph(n);

   

    graph[0].push_back(1);
    graph[0].push_back(2);

    graph[1].push_back(0);
    graph[1].push_back(3);

    graph[2].push_back(0);

    graph[3].push_back(1);
    graph[3].push_back(4);

    graph[4].push_back(3);

    for (int i = 0; i < n; i++) {

        cout << i << " -> ";

        for (int neighbour : graph[i]) {
            cout << neighbour << " ";
        }

        cout << endl;
    }

    return 0;
}
