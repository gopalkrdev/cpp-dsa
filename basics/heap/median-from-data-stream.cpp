#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {

private:

    priority_queue<int> small;

    priority_queue<
        int,
        vector<int>,
        greater<int>
    > large;

public:

    void addNum(int num) {

        small.push(num);

        if (!large.empty() &&
            small.top() > large.top()) {

            int value = small.top();

            small.pop();

            large.push(value);
        }

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
