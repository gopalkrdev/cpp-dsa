#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(
    int numCourses,
    vector<vector<int>>& prerequisites
) {
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);

    // Build graph
    for (auto prerequisite : prerequisites) {

        int course = prerequisite[0];
        int required = prerequisite[1];

        graph[required].push_back(course);
        indegree[course]++;
    }

    queue<int> q;

    // Courses with no prerequisite
    for (int i = 0; i < numCourses; i++) {

        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;

    while (!q.empty()) {

        int course = q.front();
        q.pop();

        order.push_back(course);

        for (int next : graph[course]) {

            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    if (order.size() != numCourses) {
        return {};
    }

    return order;
}
int main() {

    int numCourses = 4;

    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    vector<int> order =
        findOrder(
            numCourses,
            prerequisites
        );

    if (order.empty()) {

        cout << "No valid course order"
             << endl;
    }
    else {

        cout << "Course Order: ";

        for (int course : order) {
            cout << course << " ";
        }

        cout << endl;
    }

    return 0;
}
