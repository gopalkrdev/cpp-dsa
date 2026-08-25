#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {

private:

    // Smaller half
    // Maximum element at top
    priority_queue<int> small;

    // Larger half
    // Minimum element at top
    priority_queue<
        int,
        vector<int>,
        greater<int>
    > large;

public:

    void addNum(int num) {

        // Step 1: Add to small
        small.push(num);

        // Step 2: Make sure every element
        // in small <= every element in large
        if (!large.empty() &&
            small.top() > large.top()) {

            int value = small.top();

            small.pop();

            large.push(value);
        }

        // Step 3: Balance sizes
        if (small.size() >
            large.size() + 1) {

            large.push(small.top());

            small.pop();
        }

        if (large.size() >
            small.size()) {

            small.push(large.top());

            large.pop();
        }
    }

    double findMedian() {

        if (small.size() >
            large.size()) {

            return small.top();
        }

        return (
            small.top() +
            large.top()
        ) / 2.0;
    }
};

int main() {

    MedianFinder mf;

    mf.addNum(5);

    cout << "Median: "
         << mf.findMedian()
         << endl;

    mf.addNum(15);

    cout << "Median: "
         << mf.findMedian()
         << endl;

    mf.addNum(1);

    cout << "Median: "
         << mf.findMedian()
         << endl;

    mf.addNum(3);

    cout << "Median: "
         << mf.findMedian()
         << endl;

    return 0;
}
