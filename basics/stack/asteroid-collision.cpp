#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {

    stack<int> st;

    for (int asteroid : asteroids) {

        bool destroyed = false;

        // Collision possible only when
        // stack top is moving right
        // and current asteroid is moving left
        while (!st.empty() &&
               st.top() > 0 &&
               asteroid < 0) {

            int top = st.top();

            // Current asteroid is smaller
            if (top < -asteroid) {
                st.pop();
                continue;
            }

            // Both have same size
            if (top == -asteroid) {
                st.pop();
            }

            // Current asteroid is destroyed
            destroyed = true;
            break;
        }

        // If current asteroid survived
        if (!destroyed) {
            st.push(asteroid);
        }
    }

    // Convert stack to vector
    vector<int> result(st.size());

    for (int i = st.size() - 1; i >= 0; i--) {
        result[i] = st.top();
        st.pop();
    }

    return result;
}

int main() {

    vector<int> asteroids = {
        5, 10, -5
    };

    vector<int> result =
        asteroidCollision(asteroids);

    cout << "Remaining asteroids: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
