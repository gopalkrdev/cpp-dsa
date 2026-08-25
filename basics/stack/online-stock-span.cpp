#include <iostream>
#include <stack>
using namespace std;

class StockSpanner {

private:

    // pair = {price, span}
    stack<pair<int, int>> st;

public:

    int next(int price) {

        int span = 1;

        // Remove all previous prices
        // smaller than or equal to current price
        while (!st.empty() &&
               st.top().first <= price) {

            span += st.top().second;

            st.pop();
        }

        // Store current price and span
        st.push({price, span});

        return span;
    }
};

int main() {

    StockSpanner sp;

    int prices[] = {
        100, 80, 60, 70, 60, 75, 85
    };

    int n = 7;

    cout << "Spans: ";

    for (int i = 0; i < n; i++) {

        cout << sp.next(prices[i])
             << " ";
    }

    cout << endl;

    return 0;
}
