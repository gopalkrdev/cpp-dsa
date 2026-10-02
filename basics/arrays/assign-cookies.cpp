#include <iostream>
#include <algorithm>
using namespace std;

int findContentChildren(int greed[], int n, int cookie[], int m) {

    sort(greed, greed + n);
    sort(cookie, cookie + m);

    int child = 0;
    int currentCookie = 0;

    while (child < n && currentCookie < m) {

        if (cookie[currentCookie] >= greed[child]) {
            child++;
        }

        currentCookie++;
    }

    return child;
}

int main() {

    int greed[] = {1, 2, 3};
    int cookie[] = {1, 1};

    int n = 3;
    int m = 2;

    cout << "Maximum satisfied children: "
         << findContentChildren(greed, n, cookie, m)
         << endl;

    return 0;
}
