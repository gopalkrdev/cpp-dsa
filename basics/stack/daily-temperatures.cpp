#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {

    int n = temperatures.size();

    vector<int> answer(n, 0);

    stack<int> st;

    for (int i = 0; i < n; i++) {

        // Current temperature is warmer
        while (!st.empty() &&
               temperatures[i] >
               temperatures[st.top()]) {

            int previousDay = st.top();
            st.pop();

            answer[previousDay] =
                i - previousDay;
        }

        // Store current index
        st.push(i);
    }

    return answer;
}

int main() {

    vector<int> temperatures = {
        73, 74, 75, 71,
        69, 72, 76, 73
    };

    vector<int> result =
        dailyTemperatures(temperatures);

    cout << "Answer: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
