#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int distanceSquared(vector<int>& point) {

    int x = point[0];
    int y = point[1];

    return x * x + y * y;
}

vector<vector<int>> kClosest(
    vector<vector<int>>& points,
    int k
) {

    // Max Heap:
    // {distance, point}
    priority_queue<
        pair<int, vector<int>>
    > maxHeap;

    for (vector<int>& point : points) {

        int distance =
            distanceSquared(point);

        maxHeap.push({
            distance,
            point
        });

        // Keep only K closest points
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    vector<vector<int>> result;

    while (!maxHeap.empty()) {

        result.push_back(
            maxHeap.top().second
        );

        maxHeap.pop();
    }

    return result;
}

int main() {

    vector<vector<int>> points = {
        {1, 3},
        {-2, 2},
        {5, 8},
        {0, 1}
    };

    int k = 2;

    vector<vector<int>> result =
        kClosest(points, k);

    cout << "K Closest Points:\n";

    for (vector<int>& point : result) {

        cout << "("
             << point[0]
             << ", "
             << point[1]
             << ")"
             << endl;
    }

    return 0;
}
